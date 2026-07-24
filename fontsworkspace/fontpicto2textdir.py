import freetype
import os
import sys
import argparse
from typing import List, Tuple, Dict

# ============================================================
# CONSTANTS
# ============================================================
MIN_FONT_SIZE = 8    # minimum font size
MAX_FONT_SIZE = 100  # maximum font size
# ============================================================


class FontToPseudographics:
    """
    Converts OpenType/TrueType font characters to pseudographics.
    For each character, the maximum font size is automatically selected
    so that it fits within the given field without cropping.
    """

    def __init__(self, font_path: str):
        """
        Initialize the converter.

        Args:
            font_path: Path to the font file (.ttf, .otf).
        """
        self.font_path = font_path
        self.face = freetype.Face(font_path)
        # Cache character dimensions for optimization
        self.size_cache: Dict[Tuple[str, int], Tuple[int, int]] = {}

    def get_char_dimensions(self, char: str, font_size: int) -> Tuple[int, int]:
        """
        Get glyph dimensions for a character at the specified font size.

        Args:
            char: Single character to measure.
            font_size: Font size in pixels.

        Returns:
            Tuple (glyph_width, glyph_height)
        """
        cache_key = (char, font_size)
        if cache_key in self.size_cache:
            return self.size_cache[cache_key]
        
        self.face.set_pixel_sizes(0, font_size)
        self.face.load_char(char, freetype.FT_LOAD_RENDER | freetype.FT_LOAD_TARGET_MONO)
        bitmap = self.face.glyph.bitmap
        result = (bitmap.width, bitmap.rows)
        
        self.size_cache[cache_key] = result
        return result

    def get_char_bbox(self, char: str, font_size: int) -> Tuple[int, int, int, int]:
        """
        Get the bounding box of a character for precise centering.

        Args:
            char: Character to analyze.
            font_size: Font size.

        Returns:
            Tuple (x_min, y_min, x_max, y_max) - actual boundaries of the character image
        """
        self.face.set_pixel_sizes(0, font_size)
        self.face.load_char(char, freetype.FT_LOAD_RENDER | freetype.FT_LOAD_TARGET_MONO)
        bitmap = self.face.glyph.bitmap
        
        rows = bitmap.rows
        cols = bitmap.width
        
        # Convert to matrix for analysis
        matrix = []
        for i in range(rows):
            row = []
            for j in range(cols):
                byte_index = i * bitmap.pitch + (j // 8)
                bit_index = 7 - (j % 8)
                if byte_index < len(bitmap.buffer):
                    byte = bitmap.buffer[byte_index]
                    pixel = (byte >> bit_index) & 1
                else:
                    pixel = 0
                row.append(pixel)
            matrix.append(row)
        
        # Find boundaries
        x_min = cols
        x_max = -1
        y_min = rows
        y_max = -1
        
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 1:
                    x_min = min(x_min, j)
                    x_max = max(x_max, j)
                    y_min = min(y_min, i)
                    y_max = max(y_max, i)
        
        if x_min > x_max:  # Empty character
            return 0, 0, cols, rows
        
        return x_min, y_min, x_max, y_max

    def find_optimal_size_for_char(self, char: str, output_width: int, output_height: int, 
                                   descale_factor: int) -> int:
        """
        Find the maximum font size for a specific character that fits within
        the output_width x output_height field.

        Args:
            char: Character to find optimal size for.
            output_width: Output field width.
            output_height: Output field height.
            descale_factor: Descale factor.

        Returns:
            Optimal font size in pixels
        """
        effective_width = output_width
        effective_height = output_height
        
        # Account for descale factor
        if descale_factor > 1:
            effective_width = output_width // descale_factor
            effective_height = output_height // descale_factor
        
        # Binary search for optimal size
        left, right = MIN_FONT_SIZE, MAX_FONT_SIZE
        best_size = MIN_FONT_SIZE
        
        while left <= right:
            mid = (left + right) // 2
            
            # Check size mid for this character
            width, height = self.get_char_dimensions(char, mid)
            
            fits = (width <= effective_width and height <= effective_height)
            
            if fits:
                best_size = mid
                left = mid + 1  # try to increase
            else:
                right = mid - 1  # decrease
        
        return best_size

    def get_char_bitmap(self, char: str, font_size: int) -> Tuple[List[List[int]], int, int]:
        """
        Get the character bitmap with the specified font size.

        Args:
            char: Single character to render.
            font_size: Font size in pixels.

        Returns:
            Tuple (pixel matrix, glyph_width, glyph_height)
        """
        self.face.set_pixel_sizes(0, font_size)
        self.face.load_char(char, freetype.FT_LOAD_RENDER | freetype.FT_LOAD_TARGET_MONO)
        bitmap = self.face.glyph.bitmap

        rows = bitmap.rows
        cols = bitmap.width

        # Convert to 0/1 matrix
        matrix = []
        for i in range(rows):
            row = []
            for j in range(cols):
                byte_index = i * bitmap.pitch + (j // 8)
                bit_index = 7 - (j % 8)
                if byte_index < len(bitmap.buffer):
                    byte = bitmap.buffer[byte_index]
                    pixel = (byte >> bit_index) & 1
                else:
                    pixel = 0
                row.append(pixel)
            matrix.append(row)

        return matrix, cols, rows

    def descale_matrix(self, matrix: List[List[int]], descale_factor: int) -> List[List[int]]:
        """
        Reduce the matrix, keeping only rows and columns with indices
        multiples of descale_factor.
        """
        if descale_factor <= 1:
            return matrix
        
        new_height = len(matrix) // descale_factor
        new_width = len(matrix[0]) // descale_factor if matrix else 0
        
        result = []
        for i in range(new_height):
            row = []
            src_row = i * descale_factor
            for j in range(new_width):
                src_col = j * descale_factor
                row.append(matrix[src_row][src_col])
            result.append(row)
        
        return result

    def fit_to_field(self, matrix: List[List[int]], char_code: int, src_width: int, src_height: int, 
                     font_size: int, output_width: int, output_height: int) -> List[str]:
        """
        Fit the character matrix into the output_width x output_height field.
        Always centers the character precisely based on its actual bounding box.

        Args:
            matrix: Source pixel matrix.
            char_code: Character code.
            src_width: Character width.
            src_height: Character height.
            font_size: Font size (for getting bbox).
            output_width: Output field width.
            output_height: Output field height.

        Returns:
            List of output_height strings, each of output_width characters.
        """
        # Create empty field
        result = [['.' for _ in range(output_width)] for _ in range(output_height)]
        
        # Get actual character boundaries
        char = chr(char_code)
        x_min, y_min, x_max, y_max = self.get_char_bbox(char, font_size)
        actual_width = x_max - x_min + 1 if x_max >= x_min else 0
        actual_height = y_max - y_min + 1 if y_max >= y_min else 0
        
        if actual_width > 0 and actual_height > 0:
            # Create cropped matrix without extra margins
            cropped_matrix = []
            for i in range(y_min, y_max + 1):
                row = []
                for j in range(x_min, x_max + 1):
                    if i < len(matrix) and j < len(matrix[i]):
                        row.append(matrix[i][j])
                cropped_matrix.append(row)
            
            # Center the cropped character
            offset_x = (output_width - actual_width) // 2
            offset_y = (output_height - actual_height) // 2
            
            # Copy pixels
            for i in range(actual_height):
                if offset_y + i >= output_height:
                    break
                for j in range(actual_width):
                    if offset_x + j >= output_width:
                        break
                    if cropped_matrix[i][j] == 1:
                        result[offset_y + i][offset_x + j] = '#'
        else:
            # If character is empty, just center the original matrix
            offset_x = (output_width - src_width) // 2
            offset_y = (output_height - src_height) // 2
            for i in range(min(src_height, output_height - offset_y)):
                for j in range(min(src_width, output_width - offset_x)):
                    if i < len(matrix) and j < len(matrix[i]):
                        if matrix[i][j] == 1:
                            result[offset_y + i][offset_x + j] = '#'

        return [''.join(row) for row in result]

    def save_char(self, char_code: int, output_dir: str, output_width: int, output_height: int, 
                  descale_factor: int, fixed_size: int = None):
        """
        Save a single character to a file, selecting the optimal font size.

        Args:
            char_code: Character code.
            output_dir: Output directory.
            output_width: Output field width.
            output_height: Output field height.
            descale_factor: Descale factor.
            fixed_size: Fixed font size if provided, else None for auto.
        """
        char = chr(char_code)

        # Skip non-printable characters
        if char_code == 127:
            return

        try:
            # Determine font size
            if fixed_size:
                font_size = fixed_size
                # Check if character fits
                width, height = self.get_char_dimensions(char, font_size)
                effective_width = output_width // descale_factor if descale_factor > 1 else output_width
                effective_height = output_height // descale_factor if descale_factor > 1 else output_height
                if width > effective_width or height > effective_height:
                    print(f"Warning: Character '{char}' ({char_code}) may be cropped at {font_size}px")
            else:
                # Find optimal size for this character
                font_size = self.find_optimal_size_for_char(char, output_width, output_height, descale_factor)
            
            # Get bitmap with determined size
            matrix, width, height = self.get_char_bitmap(char, font_size)
            
            # Fit into field (always centered)
            ascii_lines = self.fit_to_field(matrix, char_code, width, height, font_size, 
                                           output_width, output_height)
            
            # Apply descaling if needed
            if descale_factor > 1:
                char_matrix = [list(line) for line in ascii_lines]
                char_matrix = self.descale_matrix(char_matrix, descale_factor)
                ascii_lines = [''.join(row) for row in char_matrix]

            # Save to file - use hex if code > 9999 or if it contains hex in range
            if char_code > 9999:
                filename = f"{char_code:04x}.txt"
                code_display = f"0x{char_code:04x}"
            else:
                filename = f"{char_code:04d}.txt"
                code_display = str(char_code)
            
            filepath = os.path.join(output_dir, filename)

            with open(filepath, 'w', encoding='utf-8') as f:
                for line in ascii_lines:
                    f.write(line + '\n')

            size_info = f"{font_size}px" if font_size else "auto"
            print(f"Saved character {code_display} ('{char}') -> {filename} (font {size_info})")

        except Exception as e:
            print(f"Error rendering character {char_code} ('{char}'): {e}")

    def generate_font(self, output_width: int, output_height: int, descale_factor: int, 
                     char_range: str, fixed_size: int = None):
        """
        Generate all characters for the font.

        Args:
            output_width: Output field width.
            output_height: Output field height.
            descale_factor: Descale factor.
            char_range: Character range string.
            fixed_size: Fixed font size if provided, else None for auto.
        """
        font_name = os.path.splitext(os.path.basename(self.font_path))[0]
        font_name = "".join(c for c in font_name if c.isalnum() or c in '._-')

        output_dir = os.path.join(os.getcwd(), font_name)
        os.makedirs(output_dir, exist_ok=True)

        final_width = output_width // descale_factor
        final_height = output_height // descale_factor

        print(f"\nGenerating font '{font_name}' in directory: {output_dir}")
        print(f"Field size: {output_width}x{output_height}")
        print(f"Final size: {final_width}x{final_height}")
        print(f"Auto-centering: ON (always enabled)")
        if fixed_size:
            print(f"Font size: {fixed_size}px (fixed)")
        else:
            print(f"Font size: auto (optimized per character, {MIN_FONT_SIZE}-{MAX_FONT_SIZE}px)")
        print()

        # Parse character range
        char_codes = self.parse_char_range(char_range)
        
        # Statistics by size
        size_stats: Dict[int, int] = {}
        
        # Generate characters
        for code in sorted(char_codes):
            self.save_char(code, output_dir, output_width, output_height, descale_factor, fixed_size)
            if not fixed_size and code != 127:
                char = chr(code)
                optimal_size = self.find_optimal_size_for_char(char, output_width, output_height, descale_factor)
                size_stats[optimal_size] = size_stats.get(optimal_size, 0) + 1

        print(f"\nDone! Characters saved to {output_dir}")
        
        # Save statistics (only for auto mode)
        if not fixed_size:
            stats_path = os.path.join(output_dir, "statistics.txt")
            with open(stats_path, 'w', encoding='utf-8') as f:
                f.write(f"Font: {self.font_path}\n")
                f.write(f"Field size: {output_width}x{output_height}\n")
                f.write(f"Final size: {final_width}x{final_height}\n")
                f.write(f"Auto-centering: ON\n")
                f.write(f"\nFont size statistics:\n")
                for size in sorted(size_stats.keys()):
                    f.write(f"  {size}px: {size_stats[size]} characters\n")

    def parse_char_range(self, range_str: str) -> List[int]:
        """
        Parse character range string into a list of character codes.
        
        Automatically detects format:
        - If number starts with '0x' -> parse as hexadecimal
        - Otherwise -> parse as decimal
        
        Supported formats:
        - Range: "32-127" or "0x20-0x7F"
        - Multiple ranges: "32-127,1040-1103" or "0x20-0x7F,0x0410-0x044F"
        - Single code: "65" or "0x41"
        - Mixed: "32,0x41,90,0x5A"
        
        Args:
            range_str: String specifying character codes/ranges
            
        Returns:
            List of integer character codes
        """
        codes = []
        
        def parse_number(s: str) -> int:
            """Parse number as decimal or hex based on 0x prefix."""
            s = s.strip()
            if s.lower().startswith('0x'):
                return int(s, 16)
            return int(s)
        
        # Split by comma
        parts = range_str.split(',')
        
        for part in parts:
            part = part.strip()
            if not part:
                continue
                
            if '-' in part:
                # Range: start-end
                try:
                    start_str, end_str = part.split('-')
                    start = parse_number(start_str)
                    end = parse_number(end_str)
                    if start > end:
                        start, end = end, start
                    codes.extend(range(start, end + 1))
                except ValueError:
                    print(f"Warning: Invalid range '{part}', skipping")
            else:
                # Single code
                try:
                    codes.append(parse_number(part))
                except ValueError:
                    print(f"Warning: Invalid code '{part}', skipping")
        
        return codes


def print_help():
    """Print help message."""
    help_text = """
Font to Pseudographics Converter (fontpicto2textdir.py)

Converts OpenType/TrueType font characters to pseudographics.
For each character, the maximum font size is automatically selected
so that it fits within the given field without cropping.
Characters are always centered based on their actual bounding box.

Usage:
    python fontpicto2textdir.py <font_path> [options]

Options:
    -w, --width WIDTH       Output field width in pixels (default: 16)
    -h, --height HEIGHT     Output field height in pixels (default: 16)
    -d, --descale FACTOR    Descale factor (1 - no change, 2 - reduce by 2x, etc.) (default: 1)
    -s, --size SIZE         Font size - fixed value or 'auto' for automatic optimization (default: auto)
    -r, --range RANGE       Character range(s): "32-127", "1040-1103", "0x20-0x7F,0x0410-0x044F" (default: "32-127")

Arguments:
    font_path               Path to the font file (.ttf, .otf)

Notes:
    - Numbers with '0x' prefix are parsed as hexadecimal
    - Numbers without prefix are parsed as decimal
    - Mixing decimal and hex in the same range is allowed

Examples:
    # ASCII characters (decimal)
    python fontpicto2textdir.py arial.ttf -r 32-127
    
    # ASCII characters (hexadecimal)
    python fontpicto2textdir.py arial.ttf -r 0x20-0x7F
    
    # Cyrillic characters with fixed font size 24px (hex)
    python fontpicto2textdir.py arial.ttf -r 0x0410-0x044F -s 24
    
    # Multiple ranges with mixed formats
    python fontpicto2textdir.py arial.ttf -r 32-127,0x0410-0x044F,1025,0x0451
    
    # Custom size and descaling
    python fontpicto2textdir.py arial.ttf -r 0x20-0x7F,0x0410-0x044F -w 24 -h 24 -d 2

Common character ranges:
    ASCII printable:  32-127 (0x20-0x7F)
    Cyrillic:         1040-1103 (0x0410-0x044F) (А-Яа-я)
    Cyrillic + Ёё:    1040-1103,1025,1105 (0x0410-0x044F,0x0401,0x0451)
    Greek:            913-969 (0x0391-0x03C9)
    Hebrew:           1488-1514 (0x05D0-0x05EA)
    Arabic:           1569-1610 (0x0621-0x064A)
"""

    print(help_text)


def main():
    # Create parser without help option
    parser = argparse.ArgumentParser(add_help=False)
    
    parser.add_argument(
        'font_path',
        nargs='?',
        help='Path to the font file (.ttf, .otf)'
    )
    
    parser.add_argument(
        '-w', '--width',
        type=int,
        default=16,
        help='Output field width in pixels (default: 16)'
    )
    
    parser.add_argument(
        '-h', '--height',
        type=int,
        default=16,
        help='Output field height in pixels (default: 16)'
    )
    
    parser.add_argument(
        '-d', '--descale',
        type=int,
        default=1,
        help='Descale factor (1 - no change, 2 - reduce by 2x, etc.) (default: 1)'
    )
    
    parser.add_argument(
        '-s', '--size',
        type=str,
        default='auto',
        help='Font size - fixed value or "auto" for automatic optimization (default: auto)'
    )
    
    parser.add_argument(
        '-r', '--range',
        type=str,
        default='32-127',
        help='Character range(s): "32-127", "1040-1103", "0x20-0x7F,0x0410-0x044F" (default: "32-127")'
    )
    
    # Parse arguments
    args = parser.parse_args()

    # Check if font_path is provided
    if not args.font_path:
        print("Error: Font path is required!")
        print_help()
        sys.exit(1)

    # Validate font path
    if not os.path.exists(args.font_path):
        print(f"Error: Font file '{args.font_path}' not found!")
        print_help()
        sys.exit(1)

    # Validate descale factor
    if args.descale < 1:
        print("Error: Descale factor must be >= 1")
        print_help()
        sys.exit(1)

    # Validate width and height
    if args.width < 1 or args.height < 1:
        print("Error: Width and height must be >= 1")
        print_help()
        sys.exit(1)

    # Parse font size
    fixed_size = None
    
    if args.size.lower() == 'auto':
        # Auto mode: optimize size for each character
        print("Using auto font size optimization")
    else:
        try:
            fixed_size = int(args.size)
            if fixed_size < MIN_FONT_SIZE or fixed_size > MAX_FONT_SIZE:
                print(f"Warning: Font size {fixed_size} is outside recommended range ({MIN_FONT_SIZE}-{MAX_FONT_SIZE}px)")
        except ValueError:
            print(f"Error: Invalid font size '{args.size}'. Use a number or 'auto'")
            print_help()
            sys.exit(1)

    # Parse character range
    if not args.range:
        print("Error: Character range cannot be empty")
        print_help()
        sys.exit(1)

    # Print configuration
    print("Font to Pseudographics Converter")
    print("=" * 40)
    print(f"Font file: {args.font_path}")
    print(f"Output size: {args.width}x{args.height}")
    print(f"Descale factor: {args.descale}")
    print(f"Final size: {args.width // args.descale}x{args.height // args.descale}")
    if fixed_size:
        print(f"Font size: {fixed_size}px (fixed)")
    else:
        print(f"Font size: auto (optimized per character, {MIN_FONT_SIZE}-{MAX_FONT_SIZE}px)")
    print(f"Auto-centering: ON (always enabled)")
    print(f"Character range: {args.range}")
    print("=" * 40)
    print()

    # Create converter and generate font
    converter = FontToPseudographics(args.font_path)
    converter.generate_font(args.width, args.height, args.descale, args.range, fixed_size)


if __name__ == "__main__":
    main()