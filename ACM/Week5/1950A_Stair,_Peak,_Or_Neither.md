---
title: Problem - 1950A - Codeforces
source: https://codeforces.com/problemset/problem/1950/A
tags:
  - 算法题/题型/其它
---

## 题目描述
You are given three digits $a$, $b$, and $c$. Determine whether they form a stair, a peak, or neither.

- A stair satisfies the condition $a < b < c$.
- A peak satisfies the condition $a < b > c$.

Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The only line of each test case contains three digits $a$, $b$, $c$ ($0 \leq a$, $b$, $c \leq 9$).

Output

For each test case, output "STAIR" if the digits form a stair, "PEAK" if the digits form a peak, and "NONE" otherwise (output the strings without quotes).

Example

```
71 2 33 2 11 5 33 4 10 0 04 1 74 5 7
```

```
STAIR
NONE
PEAK
PEAK
NONE
NONE
STAIR
```

## 题解
很简单
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int digit[3];
  for (auto& value : digit) cin >> value;
  if (digit[0] < digit[1] && digit[1] < digit[2])
    cout << "STAIR\n";
  else if (digit[0] < digit[1] && digit[2] < digit[1])
    cout << "PEAK\n";
  else
    cout << "NONE\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```

