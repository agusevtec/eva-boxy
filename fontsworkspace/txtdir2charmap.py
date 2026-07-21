import os
import sys
import re
from typing import List, Tuple, Optional


class TxtToCharmapConverter:
    """
    Converts txt files with characters to C-array for microdisplay.
    Size is automatically determined from the input file (must be square).
    Resize: only even rows and even columns are taken (2x reduction).
    
    Output format: array of bytes, where each byte is a vertical column (8 pixels),
    bit 0 is top row, bit 7 is bottom row.
    """

    def __init__(self, input_dir: str, output_file: str = "charmap.h", 
                 col_from: int = 0, col_to: int = 7):
        """
        Args:
            input_dir: Directory with txt files (e.g., "arial/")
            output_file: Name of output C-file
            col_from: Starting column to include in output array (0 = left)
            col_to: Ending column to include in output array
        """
        self.input_dir = input_dir
        self.output_file = output_file
        self.col_from = col_from
        self.col_to = col_to
        
        if self.col_from > self.col_to:
            raise ValueError(f"col_from ({col_from}) > col_to ({col_to})")
        
        self.num_cols = self.col_to - self.col_from + 1
        print(f"Will export columns: {self.num_cols} (from {self.col_from} to {self.col_to})")

    def get_file_size(self, file_path: str) -> Tuple[int, int]:
        """
        Determines the size of a txt file (number of rows and columns).
        
        Args:
            file_path: Path to txt file
            
        Returns:
            Tuple (width, height) in characters
        """
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = [line.rstrip('\n') for line in f.readlines()]
        
        height = len(lines)
        width = max(len(line) for line in lines) if lines else 0
        
        return width, height

    def parse_txt_char(self, file_path: str) -> List[int]:
        """
        Reads a txt file, resizes by 2x (takes even rows and columns),
        and returns an array of bytes for microdisplay.
        
        Args:
            file_path: Path to txt file (lines with # and . characters)
            
        Returns:
            List of bytes (one per column after resize)
        """
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = [line.rstrip('\n') for line in f.readlines()]
        
        # Determine file size
        height = len(lines)
        width = max(len(line) for line in lines) if lines else 0
        
        # Check that file is square
        if width != height:
            print(f"  Warning: file is not square ({width}x{height}), will crop to {min(width, height)}")
        
        size = min(width, height)
        
        # Keep only size rows and columns
        lines = lines[:size]
        
        # Pad to size rows if fewer
        while len(lines) < size:
            lines.append('.' * size)
        
        # Crop/pad each line to size characters
        for i in range(len(lines)):
            if len(lines[i]) > size:
                lines[i] = lines[i][:size]
            elif len(lines[i]) < size:
                lines[i] = lines[i] + '.' * (size - len(lines[i]))
        
        # RESIZE: take only even rows and even columns
        # Get matrix (size/2) x (size/2)
        new_size = size // 2
        resized = []
        for row in range(0, size, 2):      # 0, 2, 4, ...
            new_row = []
            for col in range(0, size, 2):  # 0, 2, 4, ...
                new_row.append(lines[row][col])
            resized.append(''.join(new_row))
        
        # Convert to bytes for microdisplay
        # Each byte = vertical column of new_size pixels
        # Bit 0 = top row, bit 7 = bottom row
        columns = []
        for col in range(new_size):
            byte = 0
            for row in range(new_size):
                if row < len(resized) and col < len(resized[row]):
                    if resized[row][col] == '#':
                        byte |= (1 << row)  # bit 0 is top row
            columns.append(byte)
        
        return columns

    def get_char_code_from_filename(self, filename: str) -> Optional[int]:
        """
        Extracts character code from filename (XXX.txt).
        """
        match = re.match(r'(\d+)\.txt$', filename)
        if match:
            return int(match.group(1))
        return None

    def scan_directory(self) -> List[Tuple[int, List[int]]]:
        """
        Scans directory and collects all characters.
        
        Returns:
            List of tuples (character_code, byte_array_of_columns)
        """
        chars = []
        
        for filename in sorted(os.listdir(self.input_dir)):
            if not filename.endswith('.txt'):
                continue
            
            code = self.get_char_code_from_filename(filename)
            if code is None:
                continue
            
            file_path = os.path.join(self.input_dir, filename)
            try:
                columns = self.parse_txt_char(file_path)
                chars.append((code, columns))
                print(f"  {filename} -> code {code}")
            except Exception as e:
                print(f"  Error in {filename}: {e}")
        
        return sorted(chars, key=lambda x: x[0])

    def extract_column_range(self, columns: List[int]) -> List[int]:
        """
        Extracts the specified column range from the byte array.
        
        Args:
            columns: List of bytes (0-7)
            
        Returns:
            List of bytes for the specified column range
        """
        return columns[self.col_from:self.col_to + 1]

    def generate_c_array(self, chars: List[Tuple[int, List[int]]]) -> str:
        """
        Generates C-code with character array.
        """
        lines = []
        
        # Determine size from first character
        if chars:
            first_cols = chars[0][1]
            num_cols = len(first_cols)
            num_rows = 8  # always 8 rows after resize
        else:
            num_cols = 8
            num_rows = 8
        
        # Header
        lines.append("// Auto-generated font array")
        lines.append(f"// Source: {num_cols*2}x{num_rows*2} -> resized to {num_cols}x{num_rows} (even rows/cols only)")
        lines.append(f"// Output format: {self.num_cols} bytes per character ({num_rows}x{self.num_cols} monochrome)")
        lines.append("// Byte bits: bit0=top row, bit7=bottom row")
        lines.append(f"// Exported columns: {self.col_from} to {self.col_to} (0-indexed)")
        lines.append("")
        lines.append("#include <Arduino.h>")
        lines.append("")
        lines.append(f"const uint8_t Tile64PagedScreenBase::kCharmap[][{self.num_cols}] PROGMEM = {{")
        
        # Create dictionary for fast lookup
        char_dict = {code: columns for code, columns in chars}
        
        # Generate for codes 32-127
        char_count = 0
        total = 96  # from 32 to 127 inclusive = 96 characters
        
        for code in range(32, 128):
            if code in char_dict:
                full_columns = char_dict[code]
                extracted = self.extract_column_range(full_columns)
                # Format byte array
                byte_str = ', '.join(f"0x{byte:02x}" for byte in extracted)
                
                # Add comment with the character itself
                if 32 <= code <= 126:
                    char_repr = chr(code)
                    if char_repr == '\\':
                        char_repr = '\\\\'
                    elif char_repr == '"':
                        char_repr = '\\"'
                    elif char_repr == '\'':
                        char_repr = "\\'"
                    comment = f" // '{char_repr}'"
                else:
                    comment = " // (DEL)"
                
                # Comma after each line except the last
                if char_count < total - 1:
                    lines.append(f"    {{{byte_str}}},{comment}")
                else:
                    lines.append(f"    {{{byte_str}}}{comment}")
                
                char_count += 1
            else:
                # If character is missing, use empty
                empty_bytes = ', '.join(["0x00"] * self.num_cols)
                comment = f" // (missing: {code})"
                
                if char_count < total - 1:
                    lines.append(f"    {{{empty_bytes}}},{comment}")
                else:
                    lines.append(f"    {{{empty_bytes}}}{comment}")
                
                char_count += 1
        
        lines.append("};")
        lines.append("")
        
        # Add information about number of characters
        present = len([c for c in char_dict if 32 <= c <= 127])
        lines.append(f"// Total characters: {present} of 96")
        
        return '\n'.join(lines)

    def convert(self):
        """
        Main conversion method.
        """
        if not os.path.exists(self.input_dir):
            print(f"Error: directory '{self.input_dir}' not found!")
            return False
        
        print(f"Scanning directory: {self.input_dir}")
        chars = self.scan_directory()
        
        if not chars:
            print("No txt files found!")
            return False
        
        # Determine size from first file
        first_cols = chars[0][1]
        input_size = len(first_cols) * 2
        output_size = len(first_cols)
        
        print(f"\nInput file size: {input_size}x{input_size}")
        print(f"Output size after resize: {output_size}x{output_size}")
        print(f"Characters found: {len(chars)}")
        
        c_code = self.generate_c_array(chars)
        
        with open(self.output_file, 'w', encoding='utf-8') as f:
            f.write(c_code)
        
        print(f"\nCreated file: {self.output_file}")
        return True


def main():
    if len(sys.argv) < 2:
        print("Usage: python txt_to_charmap.py <font_directory> [output_file] [col_from] [col_to]")
        print("")
        print("Parameters:")
        print("  font_directory  - directory with XXX.txt files (required)")
        print("  output_file     - name of output .h file (default: <directory_name>.h)")
        print("  col_from        - first column to export (default: 0)")
        print("  col_to          - last column to export (default: 7)")
        print("")
        print("Size is automatically determined from input files (must be square)")
        print("Resize: input files are reduced by 2x (only even rows and columns)")
        print("")
        print("Examples:")
        print("  python txt_to_charmap.py arial/")
        print("  python txt_to_charmap.py arial/ myfont.h")
        print("  python txt_to_charmap.py arial/ charmap.h 0 4   # only columns 0-4")
        sys.exit(1)
    
    input_dir = sys.argv[1]
    output_file = os.path.basename(input_dir) + ".h"
    col_from = int(sys.argv[2]) if len(sys.argv) > 2 else 0
    col_to = int(sys.argv[3]) if len(sys.argv) > 3 else 7
    
    try:
        converter = TxtToCharmapConverter(input_dir, output_file, col_from, col_to)
        
        if converter.convert():
            print(f"\nDone! File {output_file} created.")
            print("Copy it to your Arduino/PlatformIO project.")
        else:
            print("\nError during conversion.")
            sys.exit(1)
    except ValueError as e:
        print(f"Error: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()