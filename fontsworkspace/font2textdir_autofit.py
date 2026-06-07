import freetype
import os
import sys
from typing import List, Tuple, Dict

# ============================================================
# НАСТРАИВАЕМЫЕ КОНСТАНТЫ
# ============================================================
OUTPUT_WIDTH = 16   # ширина поля вывода в пикселях
OUTPUT_HEIGHT = 16  # высота поля вывода в пикселях
POSTPROCESSING_DESCALEFACTOR = 1  # коэффициент уменьшения
MIN_FONT_SIZE = 8   # минимальный размер шрифта
MAX_FONT_SIZE = 100 # максимальный размер шрифта
AUTO_CENTER = True  # автоцентрирование (True - по центру, False - как раньше)
# ============================================================


class FontToPseudographics:
    """
    Конвертирует символы OpenType/TrueType шрифта в псевдографику.
    Для каждого символа подбирается максимальный размер шрифта,
    при котором он помещается в заданное поле без обрезки.
    """

    def __init__(self, font_path: str):
        """
        Инициализация конвертера.

        Args:
            font_path: Путь к файлу шрифта (.ttf, .otf).
        """
        self.font_path = font_path
        self.face = freetype.Face(font_path)
        # Кэш размеров символов для оптимизации
        self.size_cache: Dict[Tuple[str, int], Tuple[int, int]] = {}

    def get_char_dimensions(self, char: str, font_size: int) -> Tuple[int, int]:
        """
        Получает размеры глифа символа для указанного размера шрифта.

        Args:
            char: Один символ для измерения.
            font_size: Размер шрифта в пикселях.

        Returns:
            Кортеж (ширина_глифа, высота_глифа)
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
        Получает bounding box символа для более точного центрирования.

        Args:
            char: Символ для анализа.
            font_size: Размер шрифта.

        Returns:
            Кортеж (x_min, y_min, x_max, y_max) - границы реального изображения символа
        """
        self.face.set_pixel_sizes(0, font_size)
        self.face.load_char(char, freetype.FT_LOAD_RENDER | freetype.FT_LOAD_TARGET_MONO)
        bitmap = self.face.glyph.bitmap
        
        # Получаем реальные границы символа (без пустых строк/столбцов)
        rows = bitmap.rows
        cols = bitmap.width
        
        # Преобразуем в матрицу для анализа
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
        
        # Находим границы
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
        
        if x_min > x_max:  # Пустой символ
            return 0, 0, cols, rows
        
        return x_min, y_min, x_max, y_max

    def find_optimal_size_for_char(self, char: str) -> int:
        """
        Находит максимальный размер шрифта для конкретного символа,
        при котором он помещается в поле OUTPUT_WIDTH x OUTPUT_HEIGHT.

        Args:
            char: Символ для подбора размера.

        Returns:
            Оптимальный размер шрифта в пикселях
        """
        effective_width = OUTPUT_WIDTH
        effective_height = OUTPUT_HEIGHT
        
        # Учитываем коэффициент уменьшения
        if POSTPROCESSING_DESCALEFACTOR > 1:
            effective_width = OUTPUT_WIDTH // POSTPROCESSING_DESCALEFACTOR
            effective_height = OUTPUT_HEIGHT // POSTPROCESSING_DESCALEFACTOR
        
        # Бинарный поиск оптимального размера
        left, right = MIN_FONT_SIZE, MAX_FONT_SIZE
        best_size = MIN_FONT_SIZE
        
        while left <= right:
            mid = (left + right) // 2
            
            # Проверяем размер mid для этого символа
            width, height = self.get_char_dimensions(char, mid)
            
            fits = (width <= effective_width and height <= effective_height)
            
            if fits:
                best_size = mid
                left = mid + 1  # пробуем увеличить
            else:
                right = mid - 1  # уменьшаем
        
        return best_size

    def get_char_bitmap(self, char: str, font_size: int) -> Tuple[List[List[int]], int, int]:
        """
        Получает битовую карту символа с указанным размером.

        Args:
            char: Один символ для рендеринга.
            font_size: Размер шрифта в пикселях.

        Returns:
            Кортеж (матрица пикселей, ширина_глифа, высота_глифа)
        """
        self.face.set_pixel_sizes(0, font_size)
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

    def fit_to_field(self, matrix: List[List[int]], char_code: int, src_width: int, src_height: int, 
                     font_size: int) -> List[str]:
        """
        Вписывает матрицу символа в поле OUTPUT_WIDTH x OUTPUT_HEIGHT.
        
        Args:
            matrix: Исходная матрица пикселей.
            char_code: Код символа (для определения группы).
            src_width: Ширина символа.
            src_height: Высота символа.
            font_size: Размер шрифта (для получения bbox).

        Returns:
            Список из OUTPUT_HEIGHT строк, каждая строка из OUTPUT_WIDTH символов.
        """
        # Создаём пустое поле
        result = [['.' for _ in range(OUTPUT_WIDTH)] for _ in range(OUTPUT_HEIGHT)]
        
        if AUTO_CENTER:
            # Получаем реальные границы символа
            char = chr(char_code)
            x_min, y_min, x_max, y_max = self.get_char_bbox(char, font_size)
            actual_width = x_max - x_min + 1 if x_max >= x_min else 0
            actual_height = y_max - y_min + 1 if y_max >= y_min else 0
            
            if actual_width > 0 and actual_height > 0:
                # Создаём обрезанную матрицу без лишних полей
                cropped_matrix = []
                for i in range(y_min, y_max + 1):
                    row = []
                    for j in range(x_min, x_max + 1):
                        if i < len(matrix) and j < len(matrix[i]):
                            row.append(matrix[i][j])
                    cropped_matrix.append(row)
                
                # Центрируем обрезанный символ
                offset_x = (OUTPUT_WIDTH - actual_width) // 2
                offset_y = (OUTPUT_HEIGHT - actual_height) // 2
                
                # Копируем пиксели
                for i in range(actual_height):
                    if offset_y + i >= OUTPUT_HEIGHT:
                        break
                    for j in range(actual_width):
                        if offset_x + j >= OUTPUT_WIDTH:
                            break
                        if cropped_matrix[i][j] == 1:
                            result[offset_y + i][offset_x + j] = '#'
            else:
                # Если символ пустой, просто центрируем оригинальную матрицу
                offset_x = (OUTPUT_WIDTH - src_width) // 2
                offset_y = (OUTPUT_HEIGHT - src_height) // 2
                for i in range(min(src_height, OUTPUT_HEIGHT - offset_y)):
                    for j in range(min(src_width, OUTPUT_WIDTH - offset_x)):
                        if i < len(matrix) and j < len(matrix[i]):
                            if matrix[i][j] == 1:
                                result[offset_y + i][offset_x + j] = '#'
        else:
            # Старое поведение
            # Центрирование по горизонтали
            offset_x = (OUTPUT_WIDTH - src_width) // 2

            # Вертикальное выравнивание
            if char_code in [ord(x) for x in '*+-<>=~']:
                offset_y = ((OUTPUT_HEIGHT - src_height) // 4) * 2 + 1
            elif char_code in [ord(x) for x in '"`\'^']:
                offset_y = 1
            else:
                # Для букв - прижимаем к низу
                offset_y = OUTPUT_HEIGHT - src_height

            # Копируем пиксели
            for i in range(min(src_height, OUTPUT_HEIGHT - offset_y)):
                for j in range(min(src_width, OUTPUT_WIDTH - offset_x)):
                    if i < len(matrix) and j < len(matrix[i]):
                        if matrix[i][j] == 1:
                            result[offset_y + i][offset_x + j] = '#'

        return [''.join(row) for row in result]

    def save_char(self, char_code: int, output_dir: str):
        """
        Сохраняет один символ в файл, подбирая для него оптимальный размер шрифта.
        """
        char = chr(char_code)

        # Пропускаем непечатаемые символы
        if char_code == 127:
            return

        try:
            # Подбираем оптимальный размер для этого символа
            optimal_size = self.find_optimal_size_for_char(char)
            
            # Получаем битмап с оптимальным размером
            matrix, width, height = self.get_char_bitmap(char, optimal_size)
            
            # Вписываем в поле (передаём optimal_size для bbox)
            ascii_lines = self.fit_to_field(matrix, char_code, width, height, optimal_size)
            
            # Применяем дескейлинг, если нужно
            if POSTPROCESSING_DESCALEFACTOR > 1:
                char_matrix = [list(line) for line in ascii_lines]
                char_matrix = self.descale_matrix(char_matrix)
                ascii_lines = [''.join(row) for row in char_matrix]

            # Сохраняем в файл
            filename = f"{char_code:04x}.txt"
            filepath = os.path.join(output_dir, filename)

            with open(filepath, 'w', encoding='utf-8') as f:
                for line in ascii_lines:
                    f.write(line + '\n')

            print(f"Сохранён символ {char_code} ('{char}') -> {filename} (шрифт {optimal_size}px)")

        except Exception as e:
            print(f"Ошибка при рендеринге символа {char_code} ('{char}'): {e}")

    def generate_font(self):
        """
        Генерирует все символы для шрифта.
        """
        font_name = os.path.splitext(os.path.basename(self.font_path))[0]
        font_name = "".join(c for c in font_name if c.isalnum() or c in '._-')

        output_dir = os.path.join(os.getcwd(), font_name)
        os.makedirs(output_dir, exist_ok=True)

        final_width = OUTPUT_WIDTH // POSTPROCESSING_DESCALEFACTOR
        final_height = OUTPUT_HEIGHT // POSTPROCESSING_DESCALEFACTOR

        print(f"\nСоздание шрифта '{font_name}' в директории: {output_dir}")
        print(f"Размер поля: {OUTPUT_WIDTH}x{OUTPUT_HEIGHT}")
        print(f"Финальный размер: {final_width}x{final_height}")
        print(f"Автоцентрирование: {'ВКЛ' if AUTO_CENTER else 'ВЫКЛ'}")
        print(f"Для каждого символа будет подобран свой размер шрифта от {MIN_FONT_SIZE} до {MAX_FONT_SIZE}px")
        print()

        # Статистика по размерам
        size_stats: Dict[int, int] = {}
        
        # Генерируем символы с 32 по 224
#        for code in range(32, 225):
        for code in range(0xea01, 0xf69d):
            self.save_char(code, output_dir)
            char = chr(code)
            if code != 127:
                optimal_size = self.find_optimal_size_for_char(char)
                size_stats[optimal_size] = size_stats.get(optimal_size, 0) + 1

        print(f"\nГотово! Символы сохранены в {output_dir}")
        
        # Сохраняем общую статистику
        stats_path = os.path.join(output_dir, "statistics.txt")
        with open(stats_path, 'w', encoding='utf-8') as f:
            f.write(f"Шрифт: {self.font_path}\n")
            f.write(f"Размер поля: {OUTPUT_WIDTH}x{OUTPUT_HEIGHT}\n")
            f.write(f"Финальный размер: {final_width}x{final_height}\n")
            f.write(f"Автоцентрирование: {'ВКЛ' if AUTO_CENTER else 'ВЫКЛ'}\n")
            f.write(f"\nСтатистика по размерам шрифта:\n")
            for size in sorted(size_stats.keys()):
                f.write(f"  {size}px: {size_stats[size]} символов\n")


def main():
    if len(sys.argv) != 2:
        print("Использование: python font_converter.py <путь_к_файлу_шрифта>")
        print("Пример: python font_converter.py arial.ttf")
        print("")
        print(f"Размер поля: {OUTPUT_WIDTH}x{OUTPUT_HEIGHT}")
        print(f"Коэффициент уменьшения: {POSTPROCESSING_DESCALEFACTOR}")
        print(f"Диапазон размеров шрифта: {MIN_FONT_SIZE}-{MAX_FONT_SIZE}px")
        print(f"Автоцентрирование: {'ВКЛ' if AUTO_CENTER else 'ВЫКЛ'}")
        print("")
        print("Для каждого символа будет подобран МАКСИМАЛЬНЫЙ размер шрифта,")
        print("при котором он полностью помещается в заданное поле.")
        print("При включённом автоцентрировании символы будут идеально отцентрированы по факту.")
        sys.exit(1)

    font_path = sys.argv[1]

    if not os.path.exists(font_path):
        print(f"Ошибка: файл шрифта '{font_path}' не найден!")
        sys.exit(1)

    converter = FontToPseudographics(font_path)
    converter.generate_font()


if __name__ == "__main__":
    main()