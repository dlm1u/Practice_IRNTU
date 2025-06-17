#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Функция генерации горы со случайными числами в диапазоне [1, 1000].
std::vector<std::vector<int>> Generator(int size) {
  std::vector<std::vector<int>> mountain; // создаем гору.
  for (int i = 0; i < size; i++) {
    std::vector<int> row; // временный вектор, содержащий значения текущего уровня горы.
    for (int j = 0; j <= i; j++) {
      row.push_back(rand() % 1000 + 1); // генерация случаного числа.
    }
    mountain.push_back(row); // добавляем число в текущую строку row.
  }
  return mountain;
}

// Поиск минимального пути.
std::pair<int, std::vector<int>> FindMinPath(const std::vector<std::vector<int>>& mountain) {
  int size = mountain.size(); // храним высоту горы.
  std::vector<std::vector<int>> dp = mountain; // создаем копию горы, в которую будем записывать минимальные суммы на каждом шаге.

  // Строим dp снизу вверх.
  for(int i = size - 2; i >= 0; --i) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] += std::min(dp[i+1][j], dp[i + 1][j + 1]);
      // обновляем значения по самому минимальному соседу.
      //В dp[0][0] будет храниться минимальная сумма пути от вершины до основания.
    }
  }

  // Восстановление пути.
  std::vector<int> path;
  path.push_back(mountain[0][0]); // добавляем верхний элемент.
  int col = 0; // индекс, по которому отслеживаем, где сейчас находимся.
  for (int i = 1; i < size; i++) {
    if (dp[i][col] < dp[i][col + 1]) { // смотрим соседей.
      path.push_back(mountain[i][col]); // идем влево вниз.
    } else {
      path.push_back(mountain[i][col + 1]); // идем вправо вниз.
      col++; // сдвигаем индекс вправо.
    }
  }
  return {dp[0][0], path};
  // возвращаем пару значений, dp[0][0] — это минимальная сумма пути от вершины до основания, 
  //path — последовательность чисел, по которым проходил минимальный путь.
}

int main() {
  srand(time(0)); // инициализация генератора случайных чисел.

  int size = 0;
  std::cout << "Высота: ";
  std::cin >> size;

  auto mount = Generator(size); // генерация горы.

  // вывод горы.
  for (const auto& row : mount) {
    for (int num : row) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  // поиск кратчайшего пути.
  auto result = FindMinPath(mount);
  int min = result.first;
  std::vector<int> path = result.second;

  // вывод результата.
  std::cout << "Минимальная сумма: " << min << std::endl;
  std::cout << "Путь: ";
  for (int num : path) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}