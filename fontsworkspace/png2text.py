import os
import sys
from PIL import Image
from typing import List

class PngToPseudographics:
    """
    Converts PNG image to pseudographics format (# and .).
    Output image size matches the input image size.
    """

    def __init__(self, threshold: int = 127):
        """
        Args:
            threshold: Brightness threshold for black-and-white conversion (0-255)
        """
        self.threshold = threshold

    def load_image(self, image_path: str) -> Image.Image:
        """
        Loads an image and converts it to black-and-white.
        
        Args:
            image_path: Path to PNG file
            
        Returns:
            Black-and-white image (1-bit)
        """
        with Image.open(image_path) as img:
            # Convert to grayscale
            gray_img = img.convert('L')
            
            # Apply threshold to get black-and-white image
            bw_img = gray_img.point(lambda x: 255 if x > self.threshold else 0, '1')
            
            return bw_img

    def split_into_tiles(self, img: Image.Image, n: int, m: int):
        """Splits the image into tiles and saves them"""
        width, height = img.size
        
        # Calculate tile size
        tile_width = width // m
        tile_height = height // n
        
        for i in range(n):  # rows (vertical)
            for j in range(m):  # columns (horizontal)
                # Calculate coordinates for cropping
                left = j * tile_width
                top = i * tile_height
                right = left + tile_width if j < m - 1 else width
                bottom = top + tile_height if i < n - 1 else height
                
                # Crop the tile
                tile = img.crop((left, top, right, bottom))
                
                # Convert tile to text
                text_lines = self.image_to_text(tile)
                
                # Generate output filename
                base_name = os.path.splitext(self.input_path)[0]
                output_path = f"{base_name}-{i+1}{j+1}.txt"
                
                # Save
                with open(output_path, 'w', encoding='utf-8') as f:
                    for line in text_lines:
                        f.write(line + '\n')
                
                print(f"Saved tile [{i+1},{j+1}]: {output_path}")

    def image_to_text(self, img: Image.Image) -> List[str]:
        """
        Converts a black-and-white image to text (# and .).
        
        Args:
            img: Black-and-white image (1-bit)
            
        Returns:
            List of strings representing the text image
        """
        width, height = img.size
        pixels = img.load()
        
        result = []
        for y in range(height):
            line = ''
            for x in range(width):
                # If pixel is white (255) -> '#', if black (0) -> '.'
                if pixels[x, y] == 255:
                    line += '#'
                else:
                    line += '.'
            result.append(line)
        
        return result

    def convert(self, input_path: str, n: int = 1, m: int = 1, verbose: bool = True):
        """
        Converts a PNG file to pseudographics text with tile splitting.
        
        Args:
            input_path: Path to input PNG file
            n: Number of vertical parts
            m: Number of horizontal parts
            verbose: Print progress information
        """
        self.input_path = input_path
        
        if verbose:
            print(f"Loading image: {input_path}")
        
        # Load and convert the image
        bw_img = self.load_image(input_path)
        
        width, height = bw_img.size
        
        if verbose:
            print(f"Image size: {width}x{height}")
            print(f"Brightness threshold: {self.threshold}")
            print(f"Split: {n}x{m}")
        
        if n == 1 and m == 1:
            # No splitting - save as single file
            text_lines = self.image_to_text(bw_img)
            output_path = os.path.splitext(input_path)[0] + '.txt'
            
            with open(output_path, 'w', encoding='utf-8') as f:
                for line in text_lines:
                    f.write(line + '\n')
            
            if verbose:
                print(f"Saved to: {output_path}")
        else:
            # With splitting
            self.split_into_tiles(bw_img, n, m)
            if verbose:
                print(f"Saved {n*m} files")


def main():
    if len(sys.argv) < 2:
        print("Usage: python png2text.py <input_file.png> [N M] [options]")
        print("")
        print("Parameters:")
        print("  N M - number of vertical and horizontal parts (default: 1 1)")
        print("")
        print("Options:")
        print("  --threshold <value>   Brightness threshold (0-255, default: 127)")
        print("")
        print("Examples:")
        print("  python png2text.py logo.png")
        print("  python png2text.py logo.png 2 2")
        print("  python png2text.py logo.png 3 4 --threshold 200")
        sys.exit(1)
    
    input_path = sys.argv[1]
    
    if not os.path.exists(input_path):
        print(f"Error: File '{input_path}' not found!")
        sys.exit(1)
    
    # Parse N and M (if provided)
    n, m = 1, 1
    arg_offset = 2
    
    if len(sys.argv) > 2 and sys.argv[2].isdigit():
        n = int(sys.argv[2])
        arg_offset = 3
        if len(sys.argv) > 3 and sys.argv[3].isdigit():
            m = int(sys.argv[3])
            arg_offset = 4
    
    # Parse options
    threshold = 127
    
    i = arg_offset
    while i < len(sys.argv):
        if sys.argv[i] == '--threshold' and i + 1 < len(sys.argv):
            threshold = int(sys.argv[i + 1])
            i += 2
        else:
            i += 1
    
    converter = PngToPseudographics(threshold)
    converter.convert(input_path, n, m)


if __name__ == "__main__":
    main()