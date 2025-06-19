#include <iostream>
#include <vector>

// Структура для хранения запроса.
struct Query {
  int type;
  int a;
  int b;
};

// Обработка всех запросов.
std::vector<int> process_queries(int n, const std::vector<Query>& queries) {
  std::vector<int> snow(n + 1, 0); // Вектор для хранения количества снега.
  std::vector<int> results; // Результаты для запросов типа 2.

  for (const Query& q : queries) {
    if (q.type == 1) {
      // Запрос: добавить снег на улице.
      snow[q.a] += q.b;
    } else if (q.type == 2) {
        // Запрос: посчитать сумму на отрезке.
        int sum = 0;
        for (int i = q.a; i <= q.b; ++i) {
          sum += snow[i];
        }
        results.push_back(sum); // Сохраняем результат.
    }
  }
  return results;
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;

  std::vector<Query> queries;

  // Считываем все запросы
  for (int i = 0; i < k; ++i) {
    int type, a, b;
    std::cin >> type >> a >> b;
    queries.push_back({type, a, b});
  }

  // Обрабатываем запросы и получаем результаты
  std::vector<int> results = process_queries(n, queries);

  // Выводим результаты
  for (int res : results) {
    std::cout << res << '\n';
  }

  return 0;
}
