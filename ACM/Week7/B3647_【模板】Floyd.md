---
title: B3647 【模板】Floyd - 洛谷 | 计算机科学教育新生态
source: https://www.luogu.com.cn/problem/B3647
tags:
  - 算法题/题型/图/Flody算法
---

## 题目描述

给出一张由 $n$ 个点 $m$ 条边组成的无向图。

求出所有点对 $(i,j)$ 之间的最短路径。

## 输入格式

第一行为两个整数 $n,m$，分别代表点的个数和边的条数。

接下来 $m$ 行，每行三个整数 $u,v,w$，代表 $u,v$ 之间存在一条边权为 $w$ 的边。

## 输出格式

输出 $n$ 行每行 $n$ 个整数。

第 $i$ 行的第 $j$ 个整数代表从 $i$ 到 $j$ 的最短路径。

## 输入输出样例

**输入 #1**

```
4 4
1 2 1
2 3 1
3 4 1
4 1 1
```

**输出 #1**

```
0 1 2 1
1 0 1 2
2 1 0 1
1 2 1 0
```

## 说明/提示

对于 $100\%$ 的数据，$n \le 100$，$m \le 4500$，任意一条边的权值 $w$ 是正整数且 $1 \leqslant w \leqslant 1000$。

**数据中可能存在重边。**

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