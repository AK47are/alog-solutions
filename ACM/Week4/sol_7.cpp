// 洛谷--P8605 很巧妙
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> degree(N + 10), u(M + 10), v(M + 10);
  for (int i = 0; i < M; ++i) {
    cin >> u[i] >> v[i];
    ++degree[u[i]];
    ++degree[v[i]];
  }
  long long sum = 0;
  for (int i = 0; i < M; ++i) {
    // 以每个边为基准寻找，小于 1 代表不可能形成 4 个结点的路线。
    if (degree[u[i]] > 1 && degree[v[i]] > 1)
      sum += (degree[u[i]] - 1) * (degree[v[i]] - 1) * 2;
  }
  cout << sum << "\n";
}
