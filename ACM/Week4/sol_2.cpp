// 洛谷-B3643
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  vector<pair<int, priority_queue<int, vector<int>, greater<int>>>> list(n);
  while (m--) {
    cin >> u >> v;
    matrix[u - 1][v - 1] = matrix[v - 1][u - 1] = 1;
    ++list[u - 1].first;
    ++list[v - 1].first;
    list[u - 1].second.push(v);
    list[v - 1].second.push(u);
  }

  for (auto& v : matrix) {
    for (auto value : v) cout << value << " ";
    cout << "\n";
  }

  for (auto& p : list) {
    cout << p.first << " ";
    while (!p.second.empty()) {
      cout << p.second.top() << " ";
      p.second.pop();
    }
    cout << "\n";
  }
}
