import os
import sys
import re
from typing import List, Tuple, Optional

# ============================================================
# НАСТРАИВАЕМЫЕ КОНСТАНТЫ
# ============================================================
INPUT_SIZE = 16      # размер исходного txt-файла (16x16)
OUTPUT_WIDTH = 8     # ширина поля вывода в пикселях (будет 8)
OUTPUT_HEIGHT = 8    # высота поля вывода в пикселях (будет 8)
# ============================================================


class TxtToCharmapConverter:
    """
    Конвертирует txt-файлы с символами (16x16) в C-массив для микродисплея (8x8).
    Ресайз: берутся только чётные строки и чётные столбцы.
    
    Формат вывода: массив байт, где каждый байт — вертикальный столбец (8 пикселей),
    бит 0 — верхняя строка, бит 7 — нижняя строка.
    """

    def __init__(self, input_dir: str, output_file: str = "charmap.h", 
                 col_from: int = 0, col_to: int = 7):
        """
        Args:
            input_dir: Директория с txt-файлами (например, "arial/")
            output_file: Имя выходного C-файла
            col_from: Начальная колонка для включения в выходной массив (0 = левая)
            col_to: Конечная колонка для включения в выходной массив (7 = правая)
        """
        self.input_dir = input_dir
        self.output_file = output_file
        self.col_from = max(0, min(col_from, 7))
        self.col_to = min(7, max(col_to, 0))
        
        if self.col_from > self.col_to:
            raise ValueError(f"col_from ({col_from}) > col_to ({col_to})")
        
        self.num_cols = self.col_to - self.col_from + 1
        print(f"Будет экспортировано колонок: {self.num_cols} (с {self.col_from} по {self.col_to})")

    def parse_txt_char(self, file_path: str) -> List[int]:
        """
        Читает txt-файл 16x16, делает ресайз в 8x8 (берёт чётные строки и столбцы),
        и возвращает массив байт для микродисплея.
        
        Args:
            file_path: Путь к txt-файлу (16 строк по 16 символов # и .)
            
        Returns:
            Список из 8 байт (по одному на колонку после ресайза)
        """
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = [line.rstrip('\n') for line in f.readlines()]
        
        # Оставляем только первые INPUT_SIZE строк (16)
        lines = lines[:INPUT_SIZE]
        
        # Дополняем до INPUT_SIZE строк, если их меньше
        while len(lines) < INPUT_SIZE:
            lines.append('.' * INPUT_SIZE)
        
        # Обрезаем/дополняем каждую строку до INPUT_SIZE символов
        for i in range(len(lines)):
            if len(lines[i]) > INPUT_SIZE:
                lines[i] = lines[i][:INPUT_SIZE]
            elif len(lines[i]) < INPUT_SIZE:
                lines[i] = lines[i] + '.' * (INPUT_SIZE - len(lines[i]))
        
        # РЕСАЙЗ: берём только чётные строки и чётные столбцы
        # Получаем матрицу 8x8
        resized = []
        for row in range(0, INPUT_SIZE, 2):      # 0, 2, 4, ... , 14
            new_row = []
            for col in range(0, INPUT_SIZE, 2):  # 0, 2, 4, ... , 14
                new_row.append(lines[row][col])
            resized.append(''.join(new_row))
        
        # Преобразуем в байты для микродисплея
        # Каждый байт = вертикальный столбец из 8 пикселей
        # Бит 0 = верхняя строка, бит 7 = нижняя строка
        columns = []
        for col in range(8):  # после ресайза ширина 8
            byte = 0
            for row in range(8):  # после ресайза высота 8
                if resized[row][col] == '#':
                    byte |= (1 << row)  # бит 0 — верхняя строка
            columns.append(byte)
        
        return columns

    def get_char_code_from_filename(self, filename: str) -> Optional[int]:
        """
        Извлекает код символа из имени файла (XXX.txt).
        """
        match = re.match(r'(\d+)\.txt$', filename)
        if match:
            return int(match.group(1))
        return None

    def scan_directory(self) -> List[Tuple[int, List[int]]]:
        """
        Сканирует директорию и собирает все символы.
        
        Returns:
            Список кортежей (код_символа, массив_байт_из_8_колонок)
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
                print(f"  {filename} -> код {code}")
            except Exception as e:
                print(f"  Ошибка в {filename}: {e}")
        
        return sorted(chars, key=lambda x: x[0])

    def extract_column_range(self, columns: List[int]) -> List[int]:
        """
        Извлекает указанный диапазон колонок из массива байт.
        
        Args:
            columns: Список из 8 байт (0-7)
            
        Returns:
            Список байт для указанного диапазона колонок
        """
        return columns[self.col_from:self.col_to + 1]

    def generate_c_array(self, chars: List[Tuple[int, List[int]]]) -> str:
        """
        Генерирует C-код с массивом символов.
        """
        lines = []
        
        # Заголовок
        lines.append("// Auto-generated font array")
        lines.append(f"// Source: {INPUT_SIZE}x{INPUT_SIZE} -> resized to 8x8 (even rows/cols only)")
        lines.append(f"// Output format: {self.num_cols} bytes per character (8x{self.num_cols} monochrome)")
        lines.append("// Byte bits: bit0=top row, bit7=bottom row")
        lines.append(f"// Exported columns: {self.col_from} to {self.col_to} (0-indexed)")
        lines.append("")
        lines.append("#include <Arduino.h>")
        lines.append("")
        lines.append(f"const uint8_t Tile64PagedScreenBase::kCharmap[][{self.num_cols}] PROGMEM = {{")
        
        # Создаём словарь для быстрого доступа
        char_dict = {code: columns for code, columns in chars}
        
        # Генерируем для кодов 32-127
        char_count = 0
        total = 96  # от 32 до 127 включительно = 96 символов
        
        for code in range(32, 128):
            if code in char_dict:
                full_columns = char_dict[code]
                extracted = self.extract_column_range(full_columns)
                # Форматируем массив байт
                byte_str = ', '.join(f"0x{byte:02x}" for byte in extracted)
                
                # Добавляем комментарий с самим символом
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
                
                # Запятая после каждой строки, кроме последней
                if char_count < total - 1:
                    lines.append(f"    {{{byte_str}}},{comment}")
                else:
                    lines.append(f"    {{{byte_str}}}{comment}")
                
                char_count += 1
            else:
                # Если символ отсутствует, ставим пустой
                empty_bytes = ', '.join(["0x00"] * self.num_cols)
                comment = f" // (missing: {code})"
                
                if char_count < total - 1:
                    lines.append(f"    {{{empty_bytes}}},{comment}")
                else:
                    lines.append(f"    {{{empty_bytes}}}{comment}")
                
                char_count += 1
        
        lines.append("};")
        lines.append("")
        
        # Добавляем информацию о количестве символов
        present = len([c for c in char_dict if 32 <= c <= 127])
        lines.append(f"// Total characters: {present} of 96")
        
        return '\n'.join(lines)

    def convert(self):
        """
        Основной метод конвертации.
        """
        if not os.path.exists(self.input_dir):
            print(f"Ошибка: директория '{self.input_dir}' не найдена!")
            return False
        
        print(f"Сканирование директории: {self.input_dir}")
        print(f"Ресайз: {INPUT_SIZE}x{INPUT_SIZE} -> 8x8 (чётные строки/столбцы)")
        chars = self.scan_directory()
        
        if not chars:
            print("Не найдено ни одного txt-файла!")
            return False
        
        print(f"\nНайдено символов: {len(chars)}")
        
        c_code = self.generate_c_array(chars)
        
        with open(self.output_file, 'w', encoding='utf-8') as f:
            f.write(c_code)
        
        print(f"\nСоздан файл: {self.output_file}")
        return True


def main():
    if len(sys.argv) < 2:
        print("Использование: python txt_to_charmap.py <каталог_со_шрифтом> [выходной_файл] [колонка_от] [колонка_до]")
        print("")
        print("Параметры:")
        print("  каталог_со_шрифтом  - директория с файлами XXX.txt (обязательный)")
        print("  выходной_файл       - имя выходного .h файла (по умолчанию charmap.h)")
        print("  колонка_от          - первая колонка для экспорта (по умолчанию 0)")
        print("  колонка_до          - последняя колонка для экспорта (по умолчанию 7)")
        print("")
        print(f"Ресайз: исходные файлы {INPUT_SIZE}x{INPUT_SIZE} -> 8x8 (только чётные строки и столбцы)")
        print("")
        print("Примеры:")
        print("  python txt_to_charmap.py arial/")
        print("  python txt_to_charmap.py arial/ myfont.h")
        print("  python txt_to_charmap.py arial/ charmap.h 0 4   # только колонки 0-4")
        sys.exit(1)
    
    input_dir = sys.argv[1]
    output_file = os.path.basename(sys.argv[1]) + ".h"
    col_from = int(sys.argv[2]) if len(sys.argv) > 2 else 0
    col_to = int(sys.argv[3]) if len(sys.argv) > 3 else 7
    
    try:
        converter = TxtToCharmapConverter(input_dir, output_file, col_from, col_to)
        
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