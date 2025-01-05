---
title: Problem - 1703C - Codeforces
source: https://codeforces.com/problemset/problem/1703/C
tags:
  - 算法题/题型/数论/模运算
---

## 题目描述
Luca has a cypher made up of a sequence of $n$ wheels, each with a digit $a_{i}$ written on it. On the $i$\-th wheel, he made $b_{i}$ moves. Each move is one of two types:

- up move (denoted by $\mathtt{U}$): it increases the $i$\-th digit by $1$. After applying the up move on $9$, it becomes $0$.
- down move (denoted by $\mathtt{D}$): it decreases the $i$\-th digit by $1$. After applying the down move on $0$, it becomes $9$.

![](https://espresso.codeforces.com/9b0ef328d5e7fc3b82d7b2a05ae3e757d05c7c76.png) Example for $n = 4$. The current sequence is 0 0 0 0.

Luca knows the final sequence of wheels and the moves for each wheel. Help him find the original sequence and crack the cypher.

Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 100$) — the number of wheels.

The second line contains $n$ integers $a_{i}$ ($0 \leq a_{i} \leq 9$) — the digit shown on the $i$\-th wheel after all moves have been performed.

Then $n$ lines follow, the $i$\-th of which contains the integer $b_{i}$ ($1 \leq b_{i} \leq 10$) and $b_{i}$ characters that are either $\mathtt{U}$ or $\mathtt{D}$ — the number of moves performed on the $i$\-th wheel, and the moves performed. $\mathtt{U}$ and $\mathtt{D}$ represent an up move and a down move respectively.

Output

For each test case, output $n$ space-separated digits  — the initial sequence of the cypher.

Example

```
339 3 13 DDD4 UDUU2 DU20 99 DDDDDDDDD9 UUUUUUUUU50 5 9 8 310 UUUUUUUUUU3 UUD8 UUDUUDDD10 UUDUUDUDDU4 UUUU
```

Note

In the first test case, we can prove that initial sequence was $\left[\right. 2 , 1 , 1 \left]\right.$. In that case, the following moves were performed:

- On the first wheel: $2 \rightarrow_{\mathtt{D}}^{} 1 \rightarrow_{\mathtt{D}}^{} 0 \rightarrow_{\mathtt{D}}^{} 9$.
- On the second wheel: $1 \rightarrow_{\mathtt{U}}^{} 2 \rightarrow_{\mathtt{D}}^{} 1 \rightarrow_{\mathtt{U}}^{} 2 \rightarrow_{\mathtt{U}}^{} 3$.
- On the third wheel: $1 \rightarrow_{\mathtt{D}}^{} 0 \rightarrow_{\mathtt{U}}^{} 1$.

The final sequence was $\left[\right. 9 , 3 , 1 \left]\right.$, which matches the input.

## 题解

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> res(n);
  for (auto& value : res) cin >> value;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    while (b--) {
      char c;
      cin >> c;
      if (c == 'D')
        res[i] = (res[i] + 1) % 10;
      else
        res[i] = (res[i] + 9) % 10;
    }
  }
  for (auto value : res) cout << value << " ";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```