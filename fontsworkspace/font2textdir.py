import freetype
import os
import sys
from typing import List, Tuple

# ============================================================
# НАСТРАИВАЕМЫЕ КОНСТАНТЫ
# ============================================================
OUTPUT_WIDTH = 16   # ширина поля вывода в пикселях (по умолчанию 16)
OUTPUT_HEIGHT = 16  # высота поля вывода в пикселях (по умолчанию 16)
POSTPROCESSING_DESCALEFACTOR = 1  # коэффициент уменьшения (1 - без изменений, 2 - уменьшить в 2 раза, и т.д.)
# ============================================================


class FontToPseudographics:
    """
    Конвертирует символы OpenType/TrueType шрифта в псевдографику.
    Каждый символ сохраняется в отдельный файл в подкаталоге с именем шрифта.
    Выходной формат: (OUTPUT_WIDTH // POSTPROCESSING_DESCALEFACTOR) x (OUTPUT_HEIGHT // POSTPROCESSING_DESCALEFACTOR) пикселей.
    """

    def __init__(self, font_path: str, font_size: int = 12):
        """
        Инициализация конвертера.

        Args:
            font_path: Путь к файлу шрифта (.ttf, .otf).
            font_size: Размер шрифта в пикселях.
        """
        self.face = freetype.Face(font_path)
        self.font_size = font_size
        self.face.set_pixel_sizes(0, font_size)

    def get_char_bitmap(self, char: str) -> Tuple[List[List[int]], int, int]:
        """
        Получает битовую карту символа.

        Args:
            char: Один символ для рендеринга.

        Returns:
            Кортеж (матрица пикселей, ширина_глифа, высота_глифа)
        """
        # Загружаем глиф в монохромном режиме
        self.face.load_char(char, freetype.FT_LOAD_RENDER | freetype.FT_LOAD_TARGET_MONO)
        bitmap = self.face.glyph.bitmap

        rows = bitmap.rows
        cols = bitmap.width

        # Преобразуем в матрицу 0/1
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

    def descale_matrix(self, matrix: List[List[int]]) -> List[List[int]]:
        """
        Уменьшает матрицу, оставляя только строки и столбцы с индексами,
        кратными POSTPROCESSING_DESCALEFACTOR.
        
        Args:
            matrix: Исходная матрица размером OUTPUT_HEIGHT x OUTPUT_WIDTH
            
        Returns:
            Уменьшенная матрица размером (OUTPUT_HEIGHT // factor) x (OUTPUT_WIDTH // factor)
        """
        if POSTPROCESSING_DESCALEFACTOR <= 1:
            return matrix
        
        new_height = len(matrix) // POSTPROCESSING_DESCALEFACTOR
        new_width = len(matrix[0]) // POSTPROCESSING_DESCALEFACTOR if matrix else 0
        
        result = []
        for i in range(new_height):
            row = []
            src_row = i * POSTPROCESSING_DESCALEFACTOR
            for j in range(new_width):
                src_col = j * POSTPROCESSING_DESCALEFACTOR
                row.append(matrix[src_row][src_col])
            result.append(row)
        
        return result

    def fit_to_field(self, matrix: List[List[int]], char_code: int) -> List[str]:
        """
        Вписывает матрицу символа в поле OUTPUT_WIDTH x OUTPUT_HEIGHT.
        
        Правила:
        - Горизонтальное выравнивание: offset_x = ((OUTPUT_WIDTH - src_width) // 4) * 2
        - Вертикальное выравнивание для A-Z и a-z: прижато к низу
        - Вертикальное выравнивание для остальных: по центру
        
        Args:
            matrix: Исходная матрица пикселей.
            char_code: Код символа (для определения группы).
            
        Returns:
            Список из OUTPUT_HEIGHT строк, каждая строка из OUTPUT_WIDTH символов (# или .)
        """
        src_height = len(matrix)
        src_width = len(matrix[0]) if src_height > 0 else 0

        # Если символ слишком большой по высоте, обрезаем (берём центральную часть)
        if src_height > OUTPUT_HEIGHT:
            start_row = (src_height - OUTPUT_HEIGHT) // 2
            matrix = matrix[start_row:start_row + OUTPUT_HEIGHT]
            src_height = OUTPUT_HEIGHT

        # Если символ слишком большой по ширине, обрезаем (берём центральную часть)
        if src_width > OUTPUT_WIDTH:
            start_col = (src_width - OUTPUT_WIDTH) // 2
            matrix = [row[start_col:start_col + OUTPUT_WIDTH] for row in matrix]
            src_width = OUTPUT_WIDTH

        # Создаём пустое поле
        result = [['.' for _ in range(OUTPUT_WIDTH)] for _ in range(OUTPUT_HEIGHT)]

        # Вычисляем смещение для центрирования
        offset_x = ((OUTPUT_WIDTH - src_width) // 4) * 2

        if char_code in [ord(x) for x in '*+-<>=~']:
            offset_y = ((OUTPUT_HEIGHT - src_height) // 4) * 2 + 1
        elif char_code in [ord(x) for x in '"`\'^']:
            offset_y = 1
        else:
            offset_y = (OUTPUT_HEIGHT - src_height)

        # Копируем пиксели с вычисленными смещениями
        for i in range(min(src_height, OUTPUT_HEIGHT - offset_y)):
            for j in range(min(src_width, OUTPUT_WIDTH - offset_x)):
                if i < len(matrix) and j < len(matrix[i]):
                    if matrix[i][j] == 1:
                        result[offset_y + i][offset_x + j] = '#'

        # Преобразуем в строки
        return [''.join(row) for row in result]

    def save_char(self, char_code: int, output_dir: str):
        """
        Сохраняет один символ в файл.

        Args:
            char_code: Код символа (32-127).
            output_dir: Директория для сохранения.
        """
        char = chr(char_code)

        # Пропускаем непечатаемые символы (код 127 — DEL)
        if char_code == 127:
            return

        try:
            matrix, _, _ = self.get_char_bitmap(char)
            ascii_lines = self.fit_to_field(matrix, char_code)
            
            # Преобразуем строки в матрицу символов
            char_matrix = [list(line) for line in ascii_lines]
            
            # Применяем дескейлинг, если нужно
            if POSTPROCESSING_DESCALEFACTOR > 1:
                char_matrix = self.descale_matrix(char_matrix)
            
            # Преобразуем обратно в строки
            final_lines = [''.join(row) for row in char_matrix]

            # Имя файла: код_символа.txt
            filename = f"{char_code:03d}.txt"
            filepath = os.path.join(output_dir, filename)

            with open(filepath, 'w', encoding='utf-8') as f:
                for line in final_lines:
                    f.write(line + '\n')

            print(f"Сохранён символ {char_code} ('{char}') -> {filename}")

        except Exception as e:
            print(f"Ошибка при рендеринге символа {char_code} ('{char}'): {e}")

    def generate_font(self, font_path: str):
        """
        Генерирует все символы от 32 до 127 для указанного шрифта.

        Args:
            font_path: Путь к файлу шрифта.
        """
        # Получаем имя шрифта без расширения
        font_name = os.path.splitext(os.path.basename(font_path))[0]
        # Очищаем имя от недопустимых символов
        font_name = "".join(c for c in font_name if c.isalnum() or c in '._-')

        # Создаём подкаталог
        output_dir = os.path.join(os.getcwd(), font_name)
        os.makedirs(output_dir, exist_ok=True)

        final_width = OUTPUT_WIDTH // POSTPROCESSING_DESCALEFACTOR
        final_height = OUTPUT_HEIGHT // POSTPROCESSING_DESCALEFACTOR

        print(f"Создание шрифта '{font_name}' в директории: {output_dir}")
        print()

        # Генерируем символы с 32 по 127
#        for code in range(32, 225):
        for code in range(63081, 63081+10):
#        for code in range(0xea01, 0xf69d):
            self.save_char(code, output_dir)

        print(f"\nГотово! Символы сохранены в {output_dir}")


def main():
    if len(sys.argv) != 2:
        print("Использование: python font_converter.py <путь_к_файлу_шрифта>")
        print("Пример: python font_converter.py arial.ttf")
        print("")
        print(f"Текущие настройки поля вывода: {OUTPUT_WIDTH}x{OUTPUT_HEIGHT}")
        print(f"Коэффициент уменьшения: {POSTPROCESSING_DESCALEFACTOR}")
        print(f"Финальный размер: {OUTPUT_WIDTH // POSTPROCESSING_DESCALEFACTOR}x{OUTPUT_HEIGHT // POSTPROCESSING_DESCALEFACTOR}")
        print("")
        print("Чтобы изменить размер, отредактируйте константы в начале файла:")
        print("  - OUTPUT_WIDTH")
        print("  - OUTPUT_HEIGHT") 
        print("  - POSTPROCESSING_DESCALEFACTOR")
        sys.exit(1)

    font_path = sys.argv[1]

    if not os.path.exists(font_path):
        print(f"Ошибка: файл шрифта '{font_path}' не найден!")
        sys.exit(1)

    # Размер шрифта можно менять здесь (влияет на детализацию)
    converter = FontToPseudographics(font_path, font_size=20)
    converter.generate_font(font_path)


if __name__ == "__main__":
    main()