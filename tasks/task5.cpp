#include <iostream>
#include <vector>
#include <climits>

int main() {
  int h = 0;
  int w = 0;
  std::cin >> h >> w;

  std::vector<std::vector<int>> matrix(h, std::vector<int>(w));
  // Считываем матрицу
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  // Начальные значения для поиска минимума и максимума
  int minRow = INT_MAX, maxRow = INT_MIN;
  int minCol = INT_MAX, maxCol = INT_MIN;

  // Проходим по всей матрице
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (matrix[i][j] == 1) {
        // Обновляем границы прямоугольника
        if (i < minRow) minRow = i;
        if (i > maxRow) maxRow = i;
        if (j < minCol) minCol = j;
        if (j > maxCol) maxCol = j;
      }
    }
  }

  // Выводим координаты: верхний левый угол и нижний правый угол
  std::cout << minRow - 1 << " " << minCol - 1 << " " << maxRow + 1 << " " << maxCol + 1 << std::endl;

  return 0;
}
