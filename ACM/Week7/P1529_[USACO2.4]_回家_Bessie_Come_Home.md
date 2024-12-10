# [P1529 \[USACO2.4\] 回家 Bessie Come Home](https://www.luogu.com.cn/problem/P1529)

## 题解
注意编码，以及这道题会输入两个点的不同长度的距离。

```cpp
#include <bits/stdc++.h>
using namespace std;
enum { NO_EDGE = (int)1e3 + 10 };

int main() {
  map<char, int> m;
  char c = 'A';
  for (int i = 0; i < 26; ++i) m[c + i] = i;
  c = 'a';
  for (int i = 0; i < 26; ++i) m[c + i] = i + 26;
  vector<vector<int>> edges(52, vector<int>(52, NO_EDGE));
  int P;
  cin >> P;
  while (P--) {
    char from, to;
    int length;
    cin >> from >> to >> length;
    edges[m[from]][m[to]] = min(edges[m[from]][m[to]], length);
    edges[m[to]][m[from]] = min(edges[m[to]][m[from]], length);
  }

  vector<bool> visited(52, false);
  vector<int> dist(52, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
  dist[m['Z']] = 0;
  heap.push({0, m['Z']});
  while (!heap.empty()) {
    auto cur = heap.top();
    heap.pop();
    if (visited[cur.second] == true) continue;
    visited[cur.second] = true;
    for (int i = 0; i < 52; ++i) {
      if (edges[cur.second][i] == NO_EDGE) continue;
      if (dist[i] > dist[cur.second] + edges[cur.second][i]) {
        dist[i] = dist[cur.second] + edges[cur.second][i];
        heap.push({dist[i], i});
      }
    }
  }
  int min_index = m['A'];
  for (int i = m['A'] + 1; i < m['Z']; ++i) {
    if (dist[i] < dist[min_index]) min_index = i;
  }
  cout << char(min_index + 'A') << " " << dist[min_index] << "\n";
}
```

