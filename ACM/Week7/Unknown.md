---
title: Unknown
source: 未找到原题出处，似乎来源于 AtCoder
tags:
  - 算法题/题型/图/dijkstra算法 
---

## 问题描述

我们有一个无向图，图中有 $(N_1 + N_2)$ 个顶点和 $M$ 条边。对于每一条边 $i = 1, 2, \dots, M$，第 $i$ 条边连接顶点 $a_i$ 和顶点 $b_i$。给定的图具有以下特性：

1. 对于所有的整数 $u$ 和 $v$，如果 $1 \leq u, v \leq N_1$，则顶点 $u$ 和顶点 $v$ 之间是连通的。
2. 对于所有的整数 $u$ 和 $v$，如果 $N_1 + 1 \leq u, v \leq N_1 + N_2$，则顶点 $u$ 和顶点 $v$ 之间是连通的。
3. 顶点 $1$ 和顶点 $N_1 + N_2$ 是不连通的。

现在考虑执行以下操作：

选择一个整数 $u$，其中 $1 \leq u \leq N_1$，并选择一个整数 $v$，其中 $N_1 + 1 \leq v \leq N_1 + N_2$，并添加一条边连接顶点 $u$ 和顶点 $v$。

可以证明，添加这条边后，顶点 $1$ 和顶点 $N_1 + N_2$ 总是连通的；设 $d$ 为顶点 $1$ 和顶点 $N_1 + N_2$ 之间路径的最小长度（边数）。

求通过添加适当的边，得到的最大可能的 $d$。

### "连通"的定义

**连通**指的是在图中存在一条从一个顶点到另一个顶点的路径。

### 输入

输入格式如下：

```
N1 N2 M
a1 b1
a2 b2
...
aM bM
```

其中：
- $N_1$ 和 $N_2$ 分别是第一部分和第二部分的顶点数量。
- $M$ 是图中已有的边的数量。
- 接下来有 $M$ 行，每行包含两个整数 $a_i$ 和 $b_i$，表示图中一条边连接了顶点 $a_i$ 和顶点 $b_i$。

### 输出

输出一个整数，表示通过添加一条边后，从顶点 $1$ 到顶点 $N_1 + N_2$ 的最短路径的最大可能长度。

### 限制

- $1 \leq N_1, N_2 \leq 1.5 \times 10^5$
- $0 \leq M \leq 3 \times 10^5$
- $1 \leq a_i \leq b_i \leq N_1 + N_2$
- $(a_i, b_i) \neq (a_j, b_j)$ 如果 $i \neq j$
- 对于所有 $ 1 \leq u, v \leq N_1$，顶点 $u$ 和顶点 $v$ 之间是连通的。
- 对于所有 $N_1 + 1 \leq u, v \leq N_1 + N_2$，顶点 $u$ 和顶点 $v$ 之间是连通的。
- 顶点 $1$ 和顶点 $N_1 + N_2$ 是不连通的。

### 样例输入

```
3 3 3
1 2
2 3
4 5
```

### 样例输出

```
4
```

## 题解
就是添一个边让 $1 \to N_1 + N_2$ 的最短路径最长，求两个无向无权图的最短路径中的最大值，然后相加，再加一。
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N1, N2, M;
  cin >> N1 >> N2 >> M;
  vector<vector<pair<int, int>>> edges(N1 + N2 + 1);
  while (M--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back({1, b});
    edges[b].push_back({1, a});
  }
  vector<bool> visited(N1 + N2 + 1);
  vector<int> dist(N1 + N2 + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;

  dist[1] = 0;
  heap.push({0, 1});
  while (!heap.empty()) {
    auto cur = heap.top();
    heap.pop();
    if (visited[cur.second] == 1) continue;
    visited[cur.second] = true;
    for (auto i = edges[cur.second].begin(); i != edges[cur.second].end();
         ++i) {
      if (dist[i->second] > dist[cur.second] + i->first) {
        dist[i->second] = dist[cur.second] + i->first;
        heap.push({dist[i->second], i->second});
      }
    }
  }

  dist[N1 + N2] = 0;
  heap.push({0, N1 + N2});
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
  int ans = 1;
  ans += *max_element(dist.begin() + 1, dist.begin() + N1 + 1);
  ans += *max_element(dist.begin() + N1 + 1, dist.end());
  cout << ans << "\n";
}
```
