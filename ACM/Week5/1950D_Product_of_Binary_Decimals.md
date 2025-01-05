---
title: Problem - 1950D - Codeforces
source: https://codeforces.com/problemset/problem/1950/D
tags:
  - 算法题/题型/数论/质因子分解 
---

## 题目描述
Let's call a number a binary decimal if it is a positive integer and all digits in its decimal notation are either $0$ or $1$. For example, $1 010 111$ is a binary decimal, while $10 201$ and $787 788$ are not.

Given a number $n$, you are asked whether or not it is possible to represent $n$ as a product of some (not necessarily distinct) binary decimals.

Input

The first line contains a single integer $t$ ($1 \leq t \leq 5 \cdot \left(10\right)^{4}$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($1 \leq n \leq \left(10\right)^{5}$).

Output

For each test case, output "YES" (without quotes) if $n$ can be represented as a product of binary decimals, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yES", "yes", and "Yes" will be recognized as a positive response).

Example

```
111211146411222110110100000991122024124211001
```

```
YES
YES
YES
YES
YES
YES
NO
NO
NO
NO
YES
```

Note

The first five test cases can be represented as a product of binary decimals as follows:

- $121 = 11 \times 11$.
- $1 = 1$ is already a binary decimal.
- $14 641 = 11 \times 11 \times 11 \times 11$.
- $12 221 = 11 \times 11 \times 101$.
- $10 110 = 10 110$ is already a binary decimal.

## 题解
和[分解质因子2](B3715_分解质因子2.md) 很像，区别仅在于这个质因子必须符合二进制十进制。除完判断。
<!-- TODO: 待补充factor 因子是否可以更小。 -->

```cpp
#include <bits/stdc++.h>
using namespace std;

bool IsBinary(int n) {
  string s = to_string(n);
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] != '0' && s[i] != '1') return false;
  }
  return true;
}

void Solve() {
  long long n;
  cin >> n;
  long long res = n;
  vector<int> factor{10, 11, 101, 111, 1001, 1011, 1101, 1111};
  for (auto value : factor)
    while (res % value == 0) res /= value;
  if (res == 1 || IsBinary(n))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  long long t;
  cin >> t;
  while (t--) Solve();
}
```

