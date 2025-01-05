---
title: Problem - 1807D - Codeforces
source: https://codeforces.com/problemset/problem/1807/D
tags:
  - 算法题/题型/前缀和
---

## 题目描述
You have an array $a_{1} , a_{2} , \ldots , a_{n}$. Answer $q$ queries of the following form:

- If we change all elements in the range $a_{l} , a_{l + 1} , \ldots , a_{r}$ of the array to $k$, will the sum of the entire array be odd?

Note that queries are independent and do not affect future queries.

Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq \left(10\right)^{4}$). The description of the test cases follows.

The first line of each test case consists of $2$ integers $n$ and $q$ ($1 \leq n \leq 2 \cdot \left(10\right)^{5}$; $1 \leq q \leq 2 \cdot \left(10\right)^{5}$) — the length of the array and the number of queries.

The second line of each test case consists of $n$ integers $a_{i}$ ($1 \leq a_{i} \leq \left(10\right)^{9}$) — the array $a$.

The next $q$ lines of each test case consists of $3$ integers $l , r , k$ ($1 \leq l \leq r \leq n$; $1 \leq k \leq \left(10\right)^{9}$) — the queries.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot \left(10\right)^{5}$, and the sum of $q$ doesn't exceed $2 \cdot \left(10\right)^{5}$.

Output

For each query, output "YES" if the sum of the entire array becomes odd, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example

```
25 52 2 1 3 22 3 32 3 41 5 51 4 92 4 310 51 1 1 1 1 1 1 1 1 13 8 132 5 103 8 101 10 21 9 100
```

```
YES
YES
YES
NO
YES
NO
NO
NO
NO
YES
```

Note

- If the elements in the range $\left( 2 , 3 \right)$ would get set to $3$, the array would become $\left[ 2 , 3 , 3 , 3 , 2 \right]$, the sum would be $2 + 3 + 3 + 3 + 2 = 13$, which is odd, so the answer is "YES".  
- If the elements in the range $\left( 2 , 3 \right)$ would get set to $4$, the array would become $\left[ 2 , 4 , 4 , 3 , 2 \right]$, the sum would be $2 + 4 + 4 + 3 + 2 = 15$, which is odd, so the answer is "YES".  
- If the elements in the range $\left( 1 , 5 \right)$ would get set to $5$, the array would become $\left[ 5 , 5 , 5 , 5 , 5 \right]$, the sum would be $5 + 5 + 5 + 5 + 5 = 25$, which is odd, so the answer is "YES".  
- If the elements in the range $\left( 1 , 4 \right)$ would get set to $9$, the array would become $\left[ 9 , 9 , 9 , 9 , 2 \right]$, the sum would be $9 + 9 + 9 + 9 + 2 = 38$, which is even, so the answer is "NO".  
- If the elements in the range $\left( 2 , 4 \right)$ would get set to $3$, the array would become $\left[ 2 , 3 , 3 , 3 , 2 \right]$, the sum would be $2 + 3 + 3 + 3 + 2 = 13$, which is odd, so the answer is "YES".  

## 题解
直接暴力，百分百超，使用前缀和，将数组分成三部分$[0, l), [l, r], (l, n)$，当且仅当和都是奇数或其中一个为奇数时它们的和为奇数。复杂度为 $O(t(n + q))$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void Solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> prefix(n + 2);
  for (int i = 2; i < n + 2; ++i) {
    cin >> prefix[i];
    prefix[i] += prefix[i - 1];
  }
  ll l, r, k;
  while (q--) {
    cin >> l >> r >> k;
    if ((prefix[l] + prefix[n + 1] - prefix[r + 1] + (r - l + 1) * k) % 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```

