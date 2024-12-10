# [P2984 \[USACO10FEB\] Chocolate Giving S](https://www.luogu.com.cn/problem/P2984)

## 题解
最短路径算法的使用。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, B;
  cin >> N >> M >> B;
  vector<vector<pair<int, int>>> edges(N + 1);
  while (M--) {
    int R, S, L;
    cin >> R >> S >> L;
    edges[R].push_back({L, S});
    edges[S].push_back({L, R});
  }

  vector<int> dist(N + 1, INT_MAX);
  vector<bool> visited(N + 1, false);
  dist[1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
  heap.push({0, 1});

  while (!heap.empty()) {
    auto cur = heap.top();
    heap.pop();
    if (visited[cur.second] == 1) continue;
    visited[cur.second] = 1;

    for (auto i = edges[cur.second].begin(); i != edges[cur.second].end();
         ++i) {
      if (dist[i->second] > dist[cur.second] + i->first) {
        dist[i->second] = dist[cur.second] + i->first;
        heap.push({dist[i->second], i->second});
      }
    }
  }

  while (B--) {
    int P, Q;
    cin >> P >> Q;
    cout << dist[P] + dist[Q] << "\n";
  }
}
```

