import os
import sys
import re
from typing import List, Tuple

class TxtToCharmapConverter:
    """
    Converts a directory with txt files to a C++ Pictoset class.
    """

    def __init__(self, input_dir: str, output_prefix: str = "pictograms"):
        self.input_dir = input_dir
        self.output_prefix = output_prefix
        self.header_file = f"{output_prefix}.h"
        self.cpp_file = f"{output_prefix}.cpp"
        
        # Class name from directory name
        self.class_name = os.path.basename(input_dir.rstrip('/\\'))
        if self.class_name:
            self.class_name = self.class_name[0].upper() + self.class_name[1:]

    def parse_txt_char(self, file_path: str) -> Tuple[List[int], int, int]:
        """Reads a txt file and returns a byte array."""
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = [line.rstrip('\n') for line in f.readlines()]
        
        height = len(lines)
        width = max(len(line) for line in lines) if lines else 0
        
        # Crop/pad lines
        for i in range(len(lines)):
            if len(lines[i]) > width:
                lines[i] = lines[i][:width]
            elif len(lines[i]) < width:
                lines[i] = lines[i] + '.' * (width - len(lines[i]))
        
        # Pack into bytes (bands of 8 rows)
        num_bands = (height + 7) // 8
        columns = []
        
        for band in range(num_bands):
            start_row = band * 8
            end_row = min(start_row + 8, height)
            
            for col in range(width):
                byte = 0
                for row in range(start_row, end_row):
                    if lines[row][col] == '#':
                        byte |= (1 << (row - start_row))
                columns.append(byte)
        
        return columns, width, height

    def get_variable_name(self, filename: str) -> str:
        """Generates a PROGMEM variable name with picto_ prefix"""
        name = os.path.splitext(filename)[0]
        name = re.sub(r'[^a-zA-Z0-9_]', '_', name)
        return f"picto_{name}"

    def get_constant_name(self, filename: str) -> str:
        """Generates a constant name for the header file"""
        name = os.path.splitext(filename)[0]
        name = re.sub(r'[^a-zA-Z0-9_]', '_', name)
        return name.upper()

    def scan_directory(self) -> List[Tuple[str, str, List[int], int, int]]:
        """Scans the directory and collects all tiles."""
        tiles = []
        
        for filename in sorted(os.listdir(self.input_dir)):
            if not filename.endswith('.txt'):
                continue
            
            var_name = self.get_variable_name(filename)
            const_name = self.get_constant_name(filename)
            file_path = os.path.join(self.input_dir, filename)
            
            try:
                data, width, height = self.parse_txt_char(file_path)
                print(f"  {filename} -> {var_name}: {width}x{height}, {len(data)} bytes")
                tiles.append((var_name, const_name, data, width, height))
            except Exception as e:
                print(f"  Error in {filename}: {e}")
        
        return tiles

    def generate_header(self, tiles: List[Tuple[str, str, List[int], int, int]]) -> str:
        """Generates the header file."""
        lines = []
        
        lines.append("#pragma once")
        lines.append("")
        lines.append("#include <Arduino.h>")
        lines.append("")
        lines.append(f"class Pictoset{self.class_name}")
        lines.append("{")
        lines.append("public:")
        lines.append(f"    static const uint8_t* GetTile(unsigned char aIndex);")
        lines.append(f"    static constexpr unsigned char Count = {len(tiles)};")
        lines.append("};")
        lines.append("")
        
        return '\n'.join(lines)

    def generate_cpp(self, tiles: List[Tuple[str, str, List[int], int, int]]) -> str:
        """Generates the cpp file with PROGMEM data inside GetTile."""
        lines = []
        
        lines.append(f'#include "{self.output_prefix}.h"')
        lines.append("#include <avr/pgmspace.h>")
        lines.append("")
        
        lines.append(f"const uint8_t* Pictoset{self.class_name}::GetTile(unsigned char aIndex)")
        lines.append("{")
        
        # Declare all tiles as static local variables
        for var_name, _, data, width, height in tiles:
            lines.append(f"    static const uint8_t {var_name}[] PROGMEM = {{")
            lines.append(f"        {width}, {height},  // {width}x{height}")
            
            byte_strs = [f"0x{byte:02x}" for byte in data]
            bytes_per_line = 8
            
            for i in range(0, len(byte_strs), bytes_per_line):
                chunk = byte_strs[i:i+bytes_per_line]
                line = "        " + ", ".join(chunk)
                if i + bytes_per_line < len(byte_strs):
                    line += ","
                lines.append(line)
            
            lines.append("    };")
            lines.append("")
        
        # Switch by index
        lines.append("    switch (aIndex)")
        lines.append("    {")
        
        for idx, (var_name, _, _, _, _) in enumerate(tiles):
            lines.append(f"        case {idx}: return {var_name};")
        
        lines.append("        default: return nullptr;")
        lines.append("    }")
        lines.append("}")
        lines.append("")
        
        total_bytes = sum(len(data) + 2 for _, _, data, _, _ in tiles)
        lines.append(f"// Total pictogram data size: {total_bytes} bytes")
        
        return '\n'.join(lines)

    def convert(self):
        """Main conversion method."""
        if not os.path.exists(self.input_dir):
            print(f"Error: directory '{self.input_dir}' not found!")
            return False
        
        print(f"Directory: {self.input_dir}")
        print(f"Class: Pictoset{self.class_name}")
        print(f"\nTiles:")
        
        tiles = self.scan_directory()
        
        if not tiles:
            print("No txt files found!")
            return False
        
        print(f"\nTiles found: {len(tiles)}")
        
        # Generate files
        header_code = self.generate_header(tiles)
        cpp_code = self.generate_cpp(tiles)
        
        with open(self.header_file, 'w', encoding='utf-8') as f:
            f.write(header_code)
        
        with open(self.cpp_file, 'w', encoding='utf-8') as f:
            f.write(cpp_code)
        
        print(f"\nCreated:")
        print(f"  {self.header_file}")
        print(f"  {self.cpp_file}")
        return True


def main():
    if len(sys.argv) < 2:
        print("Usage: python txtdir2collection.py <directory> [prefix]")
        print("")
        print("  directory - directory with .txt files (one directory = one Pictoset)")
        print("  prefix    - output files name prefix (default = directory name)")
        print("")
        print("Example:")
        print("  python txtdir2collection.py ./vprogress_bar my_gui")
        sys.exit(1)
    
    input_dir = sys.argv[1].rstrip('/\\')
    output_prefix = sys.argv[2] if len(sys.argv) > 2 else os.path.basename(input_dir)
    
    converter = TxtToCharmapConverter(input_dir, output_prefix)
    
    if converter.convert():
        print(f"\nDone!")
        print(f"\nUsage:")
        print(f"  #include \"{output_prefix}.h\"")
        print(f"  aScreen->Picto({{0,0}}, Pictoset{converter.class_name}::GetTile(0), false);")
    else:
        sys.exit(1)


if __name__ == "__main__":
    main()