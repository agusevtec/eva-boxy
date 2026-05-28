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

    def convert(self, input_path: str, output_path: str = None, verbose: bool = True) -> List[str]:
        """
        Конвертирует PNG-файл в псевдографический текст.
        
        Args:
            input_path: Путь к входному PNG-файлу
            output_path: Путь к выходному txt-файлу (если None, не сохраняем)
            verbose: Выводить информацию о процессе
            
        Returns:
            Список строк текстового представления
        """
        if verbose:
            print(f"Загрузка изображения: {input_path}")
        
        # Загружаем и преобразуем изображение
        bw_img = self.load_image(input_path)
        
        width, height = bw_img.size
        
        if verbose:
            print(f"Размер изображения: {width}x{height}")
            print(f"Порог яркости: {self.threshold}")
        
        # Преобразуем в текст
        text_lines = self.image_to_text(bw_img)
        
        if verbose:
            print(f"Размер текста: {len(text_lines[0])}x{len(text_lines)}")
        
        # Сохраняем в файл, если указан путь
        if output_path:
            with open(output_path, 'w', encoding='utf-8') as f:
                for line in text_lines:
                    f.write(line + '\n')
            if verbose:
                print(f"Сохранено в: {output_path}")
        
        return text_lines


def batch_convert(input_dir: str, output_dir: str, threshold: int = 127):
    """
    Конвертирует все PNG-файлы в директории.
    
    Args:
        input_dir: Входная директория с PNG-файлами
        output_dir: Выходная директория для txt-файлов
        threshold: Порог яркости
    """
    converter = PngToPseudographics(threshold)
    
    # Создаём выходную директорию, если её нет
    os.makedirs(output_dir, exist_ok=True)
    
    # Проходим по всем PNG-файлам
    for filename in os.listdir(input_dir):
        if not filename.lower().endswith('.png'):
            continue
        
        input_path = os.path.join(input_dir, filename)
        output_filename = os.path.splitext(filename)[0] + '.txt'
        output_path = os.path.join(output_dir, output_filename)
        
        print(f"\n--- Обработка: {filename} ---")
        try:
            converter.convert(input_path, output_path)
        except Exception as e:
            print(f"Ошибка при конвертации {filename}: {e}")


def main():
    if len(sys.argv) < 2:
        print("Использование: python png_to_txt.py <входной_файл.png> [выходной_файл.txt] [опции]")
        print("Или для пакетной обработки: python png_to_txt.py --batch <входная_директория> <выходная_директория>")
        print("")
        print("Опции:")
        print("  --threshold <значение>   Порог яркости (0-255, по умолчанию 127)")
        print("")
        print("Примеры:")
        print("  python png_to_txt.py logo.png")
        print("  python png_to_txt.py logo.png logo.txt")
        print("  python png_to_txt.py logo.png --threshold 200")
        print("  python png_to_txt.py --batch images/ txt_output/")
        sys.exit(1)
    
    # Пакетная обработка
    if sys.argv[1] == '--batch':
        if len(sys.argv) < 4:
            print("Ошибка: для пакетной обработки укажите входную и выходную директории")
            sys.exit(1)
        
        input_dir = sys.argv[2]
        output_dir = sys.argv[3]
        
        # Парсим опции
        threshold = 127
        
        i = 4
        while i < len(sys.argv):
            if sys.argv[i] == '--threshold' and i + 1 < len(sys.argv):
                threshold = int(sys.argv[i + 1])
                i += 2
            else:
                i += 1
        
        batch_convert(input_dir, output_dir, threshold)
        return
    
    # Одиночная конвертация
    input_path = sys.argv[1]
    
    if not os.path.exists(input_path):
        print(f"Ошибка: файл '{input_path}' не найден!")
        sys.exit(1)
    
    # Выходной файл
    if len(sys.argv) > 2 and not sys.argv[2].startswith('--'):
        output_path = sys.argv[2]
        arg_offset = 3
    else:
        output_path = os.path.splitext(input_path)[0] + '.txt'
        arg_offset = 2
    
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
    converter.convert(input_path, output_path)


if __name__ == "__main__":
    main()