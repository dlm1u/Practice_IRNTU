#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0; // количество строк.
  std::cin >> n;
  std::vector<int> otvet; // вектор для ответа, подсчитанного количества пар.
  for (int i = 0; i < n; i++) {
    int a, b, x, y; // объявление переменных.
    std::cin >> a >> b >> x >> y;

    int min_bx = std::min(b, x); // контроллеры B используют модули типа 1.
    int diff = x - min_bx; // Оставшиеся модули типа 1.
    int used_a = std::min(a, diff + y); // контроллеры А для оставшихся модулей.

    int result = min_bx + used_a;
    otvet.push_back(result);
  }
  for (int var : otvet) {
    std::cout << var << " ";
  }
  return 0;
}
