[B3647 【模板】Floyd](https://www.luogu.com.cn/problem/B3647)

## 题解
使用 Floyd 算法。重边选最短的。 $NO\_EDGE$ 开太小测试点 7 会过不了，因为实际路径和会大于 $NO\_EDGE$ 但是如果刚好和真正的 $NO\_EDGE$ 值比较，$edges[j][k]$ 就会被错误赋值成 $NO\_EDGE$ 。我们必须保证路径和不能大于 $NO\_EDGE$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;
enum { NO_EDGE = (int)1e6 };

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(n + 1, vector<int>(n + 1, NO_EDGE));
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u][v] = min(edges[u][v], w);
    edges[v][u] = min(edges[v][u], w);
  }
  for (int i = 1; i <= n; ++i) edges[i][i] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << edges[i][j] << " ";
    }
    cout << "\n";
  }
}
```

