---
title: Problem - 1950B - Codeforces
source: https://codeforces.com/problemset/problem/1950/B
tags:
  - 算法题/题型/其它 
---

## 题目描述
You are given an integer $n$. Output a $2 n \times 2 n$ checkerboard made of $2 \times 2$ squares alternating '$\#$' and '$.$', with the top-left cell being '$\#$'.

![](https://espresso.codeforces.com/3db665ec1ddded3e1be3e030c4bc89a9f297439c.png)

The picture above shows the answers for $n = 1 , 2 , 3 , 4$.

Input

The first line contains an integer $t$ ($1 \leq t \leq 20$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($1 \leq n \leq 20$) — it means you need to output a checkerboard of side length $2 n$.

Output

For each test case, output $2 n$ lines, each containing $2 n$ characters without spaces — the checkerboard, as described in the statement. Do not output empty lines between test cases.

Example

```
##
##
##..
##..
..##
..##
##..##
##..##
..##..
..##..
##..##
##..##
##..##..
##..##..
..##..##
..##..##
##..##..
##..##..
..##..##
..##..##
```

## 题解
很简单
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      if (((i / 2) + (j / 2)) % 2 == 0)
        cout << "#";
      else
        cout << ".";
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
