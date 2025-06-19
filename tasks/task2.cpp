#include <iostream>
#include <vector>
#include <list>

// используем функцию DFS для обхода графа в глубину и поиска всех вершин.
void DFS(int v, const std::vector<std::list<int>>& adj, std::vector<bool>& visited) {
  visited[v] = true; // стартовая вершина изначально считается посещенной.
  for (int u : adj[v]) { // проходим по всем соседям вершины v.
    if (!visited[u]) { // если сосед еще не посещен, запускаем рекурсию.
      DFS(u, adj, visited);
    }
  }
}

// Функция для подсчета количества компонент связности.
int CountConnectedComponents(int N, const std::vector<std::pair<int, int>>& edges) {
  // Создаем список смежности.
  std::vector<std::list<int>> adj(N + 1); // Нумерация узлов с 1 до N.
    
  // Заполняем список смежности
  for (const auto& edge : edges) {
    int u = edge.first;
    int v = edge.second;
    adj[u].push_back(v);
    adj[v].push_back(u); // граф неориентированный.
  }
    
  std::vector<bool> visited(N + 1, false); // массив для отслеживания посещенных вершин.
  int components = 0; // счетчик компонент.
    
  // запускаем DFS из каждой непосещенной вершины.
  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) {
      DFS(i, adj, visited); 
      components++; // увеличиваем количество компонент.
    }
  }
  return components;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  
  //заполнения списка ребер
  std::vector<std::pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    edges.emplace_back(u, v);
  }
    
  int components = CountConnectedComponents(n, edges);
  // Чтобы объединить все компоненты, нужно (components - 1) новых рёбер
  std::cout << components - 1 << "\n";
  return 0;
}