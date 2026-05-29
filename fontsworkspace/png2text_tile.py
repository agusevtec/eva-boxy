import os
import sys
from PIL import Image
from typing import List

class PngToPseudographics:
    """
    Конвертирует PNG-картинку в псевдографический формат (# и .).
    Размер выходной картинки совпадает с размером входной.
    """

    def __init__(self, threshold: int = 127):
        """
        Args:
            threshold: Порог яркости для преобразования в чёрно-белое (0-255)
        """
        self.threshold = threshold

    def load_image(self, image_path: str) -> Image.Image:
        """
        Загружает изображение и преобразует его в чёрно-белое.
        
        Args:
            image_path: Путь к PNG-файлу
            
        Returns:
            Чёрно-белое изображение (1-битное)
        """
        with Image.open(image_path) as img:
            # Конвертируем в оттенки серого
            gray_img = img.convert('L')
            
            # Применяем порог для получения чёрно-белого изображения
            bw_img = gray_img.point(lambda x: 255 if x > self.threshold else 0, '1')
            
            return bw_img

    def split_into_tiles(self, img: Image.Image, n: int, m: int):
        """Нарезает изображение на тайлы и сохраняет их"""
        width, height = img.size
        
        # Вычисляем размер каждого тайла
        tile_width = width // m
        tile_height = height // n
        
        for i in range(n):  # строки (вертикаль)
            for j in range(m):  # столбцы (горизонталь)
                # Вычисляем координаты для вырезания
                left = j * tile_width
                top = i * tile_height
                right = left + tile_width if j < m - 1 else width
                bottom = top + tile_height if i < n - 1 else height
                
                # Вырезаем тайл
                tile = img.crop((left, top, right, bottom))
                
                # Конвертируем тайл в текст
                text_lines = self.image_to_text(tile)
                
                # Формируем имя выходного файла
                base_name = os.path.splitext(self.input_path)[0]
                output_path = f"{base_name}-{i+1}{j+1}.txt"
                
                # Сохраняем
                with open(output_path, 'w', encoding='utf-8') as f:
                    for line in text_lines:
                        f.write(line + '\n')
                
                print(f"Сохранен тайл [{i+1},{j+1}]: {output_path}")

    def image_to_text(self, img: Image.Image) -> List[str]:
        """
        Преобразует чёрно-белое изображение в текст (# и .).
        
        Args:
            img: Чёрно-белое изображение (1-битное)
            
        Returns:
            Список строк текстового представления
        """
        width, height = img.size
        pixels = img.load()
        
        result = []
        for y in range(height):
            line = ''
            for x in range(width):
                # Если пиксель белый (255) -> '#', если чёрный (0) -> '.'
                if pixels[x, y] == 255:
                    line += '#'
                else:
                    line += '.'
            result.append(line)
        
        return result

    def convert(self, input_path: str, n: int = 1, m: int = 1, verbose: bool = True):
        """
        Конвертирует PNG-файл в псевдографический текст с нарезкой на тайлы.
        
        Args:
            input_path: Путь к входному PNG-файлу
            n: Количество частей по вертикали
            m: Количество частей по горизонтали
            verbose: Выводить информацию о процессе
        """
        self.input_path = input_path
        
        if verbose:
            print(f"Загрузка изображения: {input_path}")
        
        # Загружаем и преобразуем изображение
        bw_img = self.load_image(input_path)
        
        width, height = bw_img.size
        
        if verbose:
            print(f"Размер изображения: {width}x{height}")
            print(f"Порог яркости: {self.threshold}")
            print(f"Нарезка: {n}x{m}")
        
        if n == 1 and m == 1:
            # Без нарезки - сохраняем один файл
            text_lines = self.image_to_text(bw_img)
            output_path = os.path.splitext(input_path)[0] + '.txt'
            
            with open(output_path, 'w', encoding='utf-8') as f:
                for line in text_lines:
                    f.write(line + '\n')
            
            if verbose:
                print(f"Сохранено в: {output_path}")
        else:
            # С нарезкой
            self.split_into_tiles(bw_img, n, m)
            if verbose:
                print(f"Сохранено {n*m} файлов")


def main():
    if len(sys.argv) < 2:
        print("Использование: python png_to_txt.py <входной_файл.png> [N M] [опции]")
        print("")
        print("Параметры:")
        print("  N M - количество частей по вертикали и горизонтали (по умолчанию 1 1)")
        print("")
        print("Опции:")
        print("  --threshold <значение>   Порог яркости (0-255, по умолчанию 127)")
        print("")
        print("Примеры:")
        print("  python png_to_txt.py logo.png")
        print("  python png_to_txt.py logo.png 2 2")
        print("  python png_to_txt.py logo.png 3 4 --threshold 200")
        sys.exit(1)
    
    input_path = sys.argv[1]
    
    if not os.path.exists(input_path):
        print(f"Ошибка: файл '{input_path}' не найден!")
        sys.exit(1)
    
    # Парсим N и M (если указаны)
    n, m = 1, 1
    arg_offset = 2
    
    if len(sys.argv) > 2 and sys.argv[2].isdigit():
        n = int(sys.argv[2])
        arg_offset = 3
        if len(sys.argv) > 3 and sys.argv[3].isdigit():
            m = int(sys.argv[3])
            arg_offset = 4
    
    # Парсим опции
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