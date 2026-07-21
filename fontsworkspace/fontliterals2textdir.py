import freetype
import os
import sys
import argparse
from typing import List, Tuple, Set

class FontToPseudographics:
    """
    Converts OpenType/TrueType font characters to pseudographics.
    Each character is saved to a separate file in a subdirectory named after the font.
    Output format: (output_width // descale_factor) x (output_height // descale_factor) pixels.
    """

    def __init__(self, font_path: str, font_size: int = 12):
        """
        Initialize the converter.

        Args:
            font_path: Path to the font file (.ttf, .otf).
            font_size: Font size in pixels.
        """
        self.face = freetype.Face(font_path)
        self.font_size = font_size
        self.face.set_pixel_sizes(0, font_size)

    def get_char_bitmap(self, char: str) -> Tuple[List[List[int]], int, int]:
        """
        Get the bitmap of a character.

        Args:
            char: Single character to render.

        Returns:
            Tuple (pixel matrix, glyph_width, glyph_height)
        """
        # Load glyph in monochrome mode
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
        Reduces the matrix, keeping only rows and columns with indices
        multiples of descale_factor.
        
        Args:
            matrix: Original matrix of size output_height x output_width
            descale_factor: Reduction factor
            
        Returns:
            Reduced matrix of size (output_height // factor) x (output_width // factor)
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

    def fit_to_field(self, matrix: List[List[int]], char_code: int, output_width: int, output_height: int) -> List[str]:
        """
        Fits the character matrix into the output_width x output_height field.
        
        Rules:
        - Horizontal alignment: offset_x = ((output_width - src_width) // 4) * 2
        - Vertical alignment for A-Z and a-z: bottom-aligned
        - Vertical alignment for others: centered
        
        Args:
            matrix: Source pixel matrix.
            char_code: Character code (for group detection).
            output_width: Output field width.
            output_height: Output field height.
            
        Returns:
            List of output_height strings, each of output_width characters (# or .)
        """
        src_height = len(matrix)
        src_width = len(matrix[0]) if src_height > 0 else 0

        # If character is too tall, crop it (take central part)
        if src_height > output_height:
            start_row = (src_height - output_height) // 2
            matrix = matrix[start_row:start_row + output_height]
            src_height = output_height

        # If character is too wide, crop it (take central part)
        if src_width > output_width:
            start_col = (src_width - output_width) // 2
            matrix = [row[start_col:start_col + output_width] for row in matrix]
            src_width = output_width

        # Create empty field
        result = [['.' for _ in range(output_width)] for _ in range(output_height)]

        # Calculate horizontal offset for centering
        offset_x = ((output_width - src_width) // 4) * 2

        if char_code in [ord(x) for x in '*+-<>=~']:
            offset_y = ((output_height - src_height) // 4) * 2 + 1
        elif char_code in [ord(x) for x in '"`\'^']:
            offset_y = 1
        else:
            offset_y = (output_height - src_height)

        # Copy pixels with calculated offsets
        for i in range(min(src_height, output_height - offset_y)):
            for j in range(min(src_width, output_width - offset_x)):
                if i < len(matrix) and j < len(matrix[i]):
                    if matrix[i][j] == 1:
                        result[offset_y + i][offset_x + j] = '#'

        # Convert to strings
        return [''.join(row) for row in result]

    def save_char(self, char_code: int, output_dir: str, output_width: int, output_height: int, descale_factor: int):
        """
        Save a single character to a file.

        Args:
            char_code: Character code.
            output_dir: Directory for saving.
            output_width: Output field width.
            output_height: Output field height.
            descale_factor: Reduction factor.
        """
        try:
            char = chr(char_code)
            matrix, _, _ = self.get_char_bitmap(char)
            ascii_lines = self.fit_to_field(matrix, char_code, output_width, output_height)
            
            # Convert strings to character matrix
            char_matrix = [list(line) for line in ascii_lines]
            
            # Apply descaling if needed
            if descale_factor > 1:
                char_matrix = self.descale_matrix(char_matrix, descale_factor)
            
            # Convert back to strings
            final_lines = [''.join(row) for row in char_matrix]

            # File name: character_code.txt
            filename = f"{char_code:04d}.txt"
            filepath = os.path.join(output_dir, filename)

            with open(filepath, 'w', encoding='utf-8') as f:
                for line in final_lines:
                    f.write(line + '\n')

            print(f"Saved character {char_code} ('{char}') -> {filename}")

        except Exception as e:
            print(f"Error rendering character {char_code}: {e}")

    def generate_font(self, font_path: str, output_width: int, output_height: int, 
                     descale_factor: int, char_codes: Set[int]):
        """
        Generate characters for the specified character codes.

        Args:
            font_path: Path to the font file.
            output_width: Output field width.
            output_height: Output field height.
            descale_factor: Reduction factor.
            char_codes: Set of character codes to generate.
        """
        # Get font name without extension
        font_name = os.path.splitext(os.path.basename(font_path))[0]
        # Clean the name from invalid characters
        font_name = "".join(c for c in font_name if c.isalnum() or c in '._-')

        # Create subdirectory
        output_dir = os.path.join(os.getcwd(), font_name)
        os.makedirs(output_dir, exist_ok=True)

        final_width = output_width // descale_factor
        final_height = output_height // descale_factor

        print(f"Generating font '{font_name}' in directory: {output_dir}")
        print(f"Output size: {output_width}x{output_height} -> Final size: {final_width}x{final_height}")
        print(f"Character count: {len(char_codes)}")
        print()

        # Sort codes for consistent output
        for code in sorted(char_codes):
            self.save_char(code, output_dir, output_width, output_height, descale_factor)

        print(f"\nDone! Characters saved to {output_dir}")


def parse_char_codes(range_str: str) -> Set[int]:
    """
    Parse character range string into a set of character codes.
    
    Supported formats:
    - Single code: "65"
    - Range: "32-127"
    - Multiple ranges: "32-127,1040-1103"
    - Mixed: "65,90,1040-1071"
    - With single codes and ranges: "65,90,1040-1071,1105"
    
    Args:
        range_str: String specifying character codes/ranges
        
    Returns:
        Set of integer character codes
    """
    codes = set()
    
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
                start = int(start_str.strip())
                end = int(end_str.strip())
                if start > end:
                    start, end = end, start
                codes.update(range(start, end + 1))
            except ValueError:
                print(f"Warning: Invalid range '{part}', skipping")
        else:
            # Single code
            try:
                codes.add(int(part))
            except ValueError:
                print(f"Warning: Invalid code '{part}', skipping")
    
    return codes


def print_help():
    """Print help message."""
    help_text = """
Font to Pseudographics Converter

Usage:
    python fontliterals2textdir.py <font_path> [options]

Options:
    -w, --width WIDTH       Work field width in pixels (default: 16)
    -h, --height HEIGHT     Work field height in pixels (default: 16)
    -d, --descale FACTOR    Descale factor (1 - no change, 2 - reduce by 2x, etc.) (default: 1)
    -s, --size SIZE         Font size in pixels (default: 20)
    -r, --range RANGE       Character range(s): "32-127", "1040-1103", "32-127,1040-1103", "65,90,1040-1103" (default: "32-127")

Arguments:
    font_path               Path to the font file (.ttf, .otf)

Examples:
    # ASCII characters (32-127)
    python fontliterals2textdir.py arial.ttf -r 32-127
    
    # Cyrillic uppercase and lowercase (А-Я, а-я)
    python fontliterals2textdir.py arial.ttf -r 1040-1103
    
    # Cyrillic including Ё and ё
    python fontliterals2textdir.py arial.ttf -r 1040-1103,1025,1105
    
    # Multiple ranges (ASCII + Cyrillic)
    python fontliterals2textdir.py arial.ttf -r 32-127,1040-1103
    
    # Custom size and descaling
    python fontliterals2textdir.py arial.ttf -r 1040-1103 -w 24 -h 24 -s 20 -d 2

Common character ranges:
    ASCII printable:  32-127
    Cyrillic:         1040-1103 (А-Яа-я)
    Cyrillic + Ёё:    1040-1103,1025,1105
    Greek:            913-969
    Hebrew:           1488-1514
    Arabic:           1569-1610
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
        type=int,
        default=20,
        help='Font size in pixels (default: 20)'
    )
    
    parser.add_argument(
        '-r', '--range',
        type=str,
        default='32-127',
        help='Character range(s): "32-127", "1040-1103", "32-127,1040-1103", "65,90,1040-1103" (default: "32-127")'
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

    # Parse character codes
    char_codes = parse_char_codes(args.range)
    if not char_codes:
        print("Error: No valid character codes specified")
        print_help()
        sys.exit(1)

    # Print configuration
    print("Font to Pseudographics Converter")
    print("=" * 40)
    print(f"Font file: {args.font_path}")
    print(f"Output size: {args.width}x{args.height}")
    print(f"Descale factor: {args.descale}")
    print(f"Final size: {args.width // args.descale}x{args.height // args.descale}")
    print(f"Font size: {args.size}px")
    print(f"Character codes: {len(char_codes)} characters")
    if len(char_codes) <= 20:
        print(f"Codes: {sorted(char_codes)}")
    else:
        print(f"Range: {min(char_codes)}-{max(char_codes)}")
    print("=" * 40)
    print()

    # Create converter and generate font
    converter = FontToPseudographics(args.font_path, font_size=args.size)
    converter.generate_font(args.font_path, args.width, args.height, args.descale, char_codes)


if __name__ == "__main__":
    main()