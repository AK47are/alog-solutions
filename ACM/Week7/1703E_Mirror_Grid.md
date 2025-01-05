---
title: Problem - 1703E - Codeforces
source: https://codeforces.com/problemset/problem/1703/E
tags:
  - 算法题/题型/矩阵
---

## 题目描述
You are given a square grid with $n$ rows and $n$ columns. Each cell contains either $0$ or $1$.

In an operation, you can select a cell of the grid and flip it (from $0 \rightarrow 1$ or $1 \rightarrow 0$). Find the minimum number of operations you need to obtain a square that remains the same when rotated $0^{\circ}$, $\left(90\right)^{\circ}$, $\left(180\right)^{\circ}$ and $\left(270\right)^{\circ}$.

The picture below shows an example of all rotations of a grid.

![](https://espresso.codeforces.com/f4ea902a0842cdc893443b5668697e06a2a3c42c.png)

Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 100$) — the size of the grid.

Then $n$ lines follow, each with $n$ characters $a_{i , j}$ ($0 \leq a_{i , j} \leq 1$) — the number written in each cell.

Output

For each test case output a single integer  — the minimum number of operations needed to make the square look the same rotated $0^{\circ}$, $\left(90\right)^{\circ}$, $\left(180\right)^{\circ}$ and $\left(270\right)^{\circ}$.

Example

```
5301011001010511100110110101110011110005010001010101010000100100151100100000111111011001111
```

Note

In the first test case, we can perform one operations to make the grid $0 & 1 & 0 \\ 1 & 1 & 1 \\ 0 & 1 & 0$. Now, all rotations of the square are the same.

In the second test case, all rotations of the square are already the same, so we don't need any flips.

## 题解
注意判定的格子坐标。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<char>> matrix(n, vector<char>(n));
  for (auto& line : matrix) {
    for (auto& value : line) {
      cin >> value;
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int count0 = 0, count1 = 0;
      int dx[4] = {i, j, n - j - 1, n - i - 1};
      int dy[4] = {j, n - i - 1, i, n - j - 1};
      for (int k = 0; k < 4; ++k) {
        if (matrix[dx[k]][dy[k]] == '0')
          ++count0;
        else
          ++count1;
      }
      count += min(count0, count1);
    }
  }
  cout << count / 4 << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```

