import os
import sys
import re
from typing import List, Tuple, Optional

class TxtToCharmapConverter:
    """
    Конвертирует txt-файлы с символами произвольного размера в C-массивы для микродисплея.
    
    Поддерживаемые высоты: любые (кратные 8 или нет).
    Формат упаковки: разбиение на горизонтальные полосы по 8 строк.
    В каждой полосе для каждой колонки собирается байт (бит0=верхняя строка полосы, бит7=нижняя).
    
    Для каждого файла создаётся отдельная переменная.
    """

    def __init__(self, input_dir: str, output_file: str = "charmap.h"):
        """
        Args:
            input_dir: Директория с txt-файлами (например, "picto/")
            output_file: Имя выходного C-файла
        """
        self.input_dir = input_dir
        self.output_file = output_file

    def parse_txt_char(self, file_path: str) -> Tuple[List[int], int, int]:
        """
        Читает txt-файл и возвращает массив байт для микродисплея.
        
        Упаковка:
        - Разбиваем изображение на горизонтальные полосы по 8 строк
        - В каждой полосе для каждой колонки собираем байт:
          бит0 = верхняя строка полосы, бит7 = нижняя строка полосы
        - Порядок байт: сначала все колонки первой полосы, затем все колонки второй полосы и т.д.
        
        Args:
            file_path: Путь к txt-файлу (N строк по M символов # и .)
            
        Returns:
            Кортеж (массив_байт, ширина_символа, высота_символа)
        """
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = [line.rstrip('\n') for line in f.readlines()]
        
        # Определяем размеры символа
        height = len(lines)
        width = max(len(line) for line in lines) if lines else 0
        
        # Обрезаем/дополняем каждую строку до единой ширины
        for i in range(len(lines)):
            if len(lines[i]) > width:
                lines[i] = lines[i][:width]
            elif len(lines[i]) < width:
                lines[i] = lines[i] + '.' * (width - len(lines[i]))
        
        # Определяем количество полос по 8 строк
        num_bands = (height + 7) // 8
        bytes_per_band = width  # в каждой полосе по байту на колонку
        
        # Массив для результата
        columns = []
        
        # Обрабатываем каждую полосу
        for band in range(num_bands):
            start_row = band * 8
            end_row = min(start_row + 8, height)
            
            # Для каждой колонки собираем байт
            for col in range(width):
                byte = 0
                for row in range(start_row, end_row):
                    if lines[row][col] == '#':
                        # бит0 = верхняя строка полосы
                        bit_pos = row - start_row
                        byte |= (1 << bit_pos)
                columns.append(byte)
        
        return columns, width, height

    def get_name_from_filename(self, filename: str) -> Optional[str]:
        """
        Извлекает имя переменной из имени файла (без расширения).
        """
        name = os.path.splitext(filename)[0]
        # Очищаем имя от недопустимых символов для C-идентификатора
        name = re.sub(r'[^a-zA-Z0-9_]', '_', name)
        return name

    def scan_directory(self) -> List[Tuple[str, List[int], int, int]]:
        """
        Сканирует директорию и собирает все символы.
        
        Returns:
            Список кортежей (имя_переменной, массив_байт, ширина, высота)
        """
        chars = []
        
        for filename in sorted(os.listdir(self.input_dir)):
            if not filename.endswith('.txt'):
                continue
            
            name = self.get_name_from_filename(filename)
            if name is None:
                continue
            
            file_path = os.path.join(self.input_dir, filename)
            try:
                columns, width, height = self.parse_txt_char(file_path)
                num_bands = (height + 7) // 8
                print(f"  {filename} -> {name}: {width}x{height} "
                      f"({num_bands} полос по 8 строк, всего {len(columns)} байт)")
                chars.append((name, columns, width, height))
            except Exception as e:
                print(f"  Ошибка в {filename}: {e}")
        
        return chars

    def generate_c_arrays(self, chars: List[Tuple[str, List[int], int, int]]) -> str:
        """
        Генерирует C-код с массивами символов.
        """
        lines = []
        
        # Заголовок
        lines.append("// Auto-generated font/pictogram arrays")
        lines.append("// Format: width, height, then byte data")
        lines.append("// Bytes are organized in horizontal bands of 8 rows each")
        lines.append("// For each band: one byte per column (bit0=top row of band, bit7=bottom row)")
        lines.append("// Order: all columns of band0, then all columns of band1, etc.")
        lines.append("")
        lines.append("#include <Arduino.h>")
        lines.append("")
        
        # Генерируем отдельную переменную для каждого файла
        for name, columns, width, height in chars:
            num_bands = (height + 7) // 8
            total_bytes = len(columns)
            
            lines.append(f"// {width}x{height} pictogram")
            lines.append(f"const uint8_t picto_{name}[] PROGMEM = {{")
            lines.append(f"    {width}, {height},  // ({width}x{height} пикселей)")
            
            # Форматируем байты в строки по 8-12 байт на строку для читаемости
            byte_strs = [f"0x{byte:02x}" for byte in columns]
            bytes_per_line = 8  # количество байт на строку в выводе
            
            for i in range(0, len(byte_strs), bytes_per_line):
                chunk = byte_strs[i:i+bytes_per_line]
                line = "    " + ", ".join(chunk)
                if i + bytes_per_line < len(byte_strs):
                    line += ","
                lines.append(line)
            
            lines.append("};")
            lines.append("")
        
        # Добавляем информацию о количестве сгенерированных массивов
        lines.append(f"// Total pictograms generated: {len(chars)}")
        
        return '\n'.join(lines)

    def convert(self):
        """
        Основной метод конвертации.
        """
        if not os.path.exists(self.input_dir):
            print(f"Ошибка: директория '{self.input_dir}' не найдена!")
            return False
        
        print(f"Сканирование директории: {self.input_dir}")
        chars = self.scan_directory()
        
        if not chars:
            print("Не найдено ни одного txt-файла!")
            return False
        
        print(f"\nНайдено файлов: {len(chars)}")
        
        c_code = self.generate_c_arrays(chars)
        
        with open(self.output_file, 'w', encoding='utf-8') as f:
            f.write(c_code)
        
        print(f"\nСоздан файл: {self.output_file}")
        return True


def main():
    if len(sys.argv) < 2:
        print("Использование: python picto_converter.py <каталог_с_txt_файлами> [выходной_файл]")
        print("")
        print("Параметры:")
        print("  каталог_с_txt_файлами  - директория с файлами .txt (обязательный)")
        print("  выходной_файл          - имя выходного .h файла (по умолчанию pictograms.h)")
        print("")
        print("Формат упаковки данных:")
        print("  - Изображение разбивается на горизонтальные полосы по 8 строк")
        print("  - В каждой полосе для каждой колонки собирается байт")
        print("  - Бит0 = верхняя строка полосы, бит7 = нижняя строка полосы")
        print("  - Порядок байт: все колонки полосы0, затем все колонки полосы1, ...")
        print("")
        print("Пример:")
        print("  python picto_converter.py pictograms/ my_pictos.h")
        print("")
        print("Для каждого файла будет создана переменная picto_<имя_файла>[]")
        sys.exit(1)
    
    input_dir = sys.argv[1]
    # Убираем слеш в конце, если есть
    input_dir = input_dir.rstrip('/\\')
    
    # Выходной файл
    output_file = sys.argv[2] if len(sys.argv) > 2 else "pictograms.h"
    
    try:
        converter = TxtToCharmapConverter(input_dir, output_file)
        
        if converter.convert():
            print(f"\nГотово! Файл {output_file} создан.")
            print("Скопируйте его в ваш проект Arduino/PlatformIO.")
        else:
            print("\nОшибка при конвертации.")
            sys.exit(1)
    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()