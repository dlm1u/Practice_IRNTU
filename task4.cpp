#include <iostream>
#include <vector>
#include <string>

// Функция для вычисления обратной перестановки.
std::vector<int> Iniverse(std::vector<int>& p) {
  int n = p.size();
  std::vector<int> invP(n); // вектор для хранения обратной перестановки.
  for (int i = 0; i < n; i++) {
    invP[p[i] - 1] = i + 1; // выполняем перестановку.
  }
  return invP;
}

// Функция для применения перестановки p к строке s.
std::string Permutation(std::string& s, std::vector<int>& p) {
  int n = p.size();
  std::string result(n, ' '); // Создаём новую строку длины n, заполненную пробелами.
  for (int i = 0; i < n; i++) {
    // символ с позиции p[i] - 1 переносится на позицию i.
    result[i] = s[p[i] - 1];
  }
  return result;
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;

  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }

  std::string world;
  std::cin >> world;

  std::vector<int> invp = Iniverse(p); // вычисляем обратную перестановку.

  std::string result = world;
  for (int i = 0; i < k; i++) { // k раз применяем обратную перестановку.
    result = Permutation(result, invp);
  }

  std::cout << result << "\n";
  return 0;
}