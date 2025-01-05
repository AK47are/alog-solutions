---
title: Problem - 1444A - Codeforces
source: https://codeforces.com/problemset/problem/1444/A
tags:
  - 算法题/题型/数论/质因子分解 
---

## 题目描述
Oleg's favorite subjects are History and Math, and his favorite branch of mathematics is division.

To improve his division skills, Oleg came up with $t$ pairs of integers $p_{i}$ and $q_{i}$ and for each pair decided to find the greatest integer $x_{i}$, such that:

- $p_{i}$ is divisible by $x_{i}$;
- $x_{i}$ is not divisible by $q_{i}$.

Oleg is really good at division and managed to find all the answers quickly, how about you?

Input

The first line contains an integer $t$ ($1 \leq t \leq 50$) — the number of pairs.

Each of the following $t$ lines contains two integers $p_{i}$ and $q_{i}$ ($1 \leq p_{i} \leq \left(10\right)^{18}$; $2 \leq q_{i} \leq \left(10\right)^{9}$) — the $i$\-th pair of integers.

Output

Print $t$ integers: the $i$\-th integer is the largest $x_{i}$ such that $p_{i}$ is divisible by $x_{i}$, but $x_{i}$ is not divisible by $q_{i}$.

One can show that there is always at least one value of $x_{i}$ satisfying the divisibility conditions for the given constraints.

Note

For the first pair, where $p_{1} = 10$ and $q_{1} = 4$, the answer is $x_{1} = 10$, since it is the greatest divisor of $10$ and $10$ is not divisible by $4$.

For the second pair, where $p_{2} = 12$ and $q_{2} = 6$, note that

- $12$ is not a valid $x_{2}$, since $12$ is divisible by $q_{2} = 6$;
- $6$ is not valid $x_{2}$ as well: $6$ is also divisible by $q_{2} = 6$.

The next available divisor of $p_{2} = 12$ is $4$, which is the answer, since $4$ is not divisible by $6$.

## 题解
如果 $p_i\ mod\ q_i \not= 0$, 那么 $x = p_i$ 。否则 $p_i 可以被 q_i$ 整除，这代表 $p_i$ 的任意质因子大小都一定不小于 $q_i$ 对应的质因子个数。同理 $x$ 可除尽 $p_i$ 。所以 $q_i 和 x$ 拥有相同的质因子（都是 $p_i$ 有的)，唯一有区别的是质因子的幂大小，为了满足 $x\ mod\ q_i \not= 0$，$x$ 中应存在一个质因子其幂小于 $q_i$ 对应的质因子幂大小。我们希望得到最大的 $x$ ，先找到 $q_i$ 最小的质因子。它的幂减一，然后其他质因子幂大小和 $p_i$ 同。

注意使用的是 powl(), pow() 可能溢出。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void Solve() {
  ll p, q;
  cin >> p >> q;
  if (p % q != 0) {
    cout << p << "\n";
  } else {
    ll res = p, min_factor = LONG_LONG_MAX;
    for (ll i = 2; i <= sqrt(q); ++i) {
      ll p_count = 0, q_count = 0;
      while (p % i == 0) {
        p /= i;
        ++p_count;
      }
      while (q % i == 0) {
        q /= i;
        ++q_count;
      }
      if (q_count != 0) {
        ll reduce = powl(i, p_count - q_count + 1);
        if (reduce < min_factor) min_factor = reduce;
      }
    }
    if (q != 1 && q < min_factor) {
      ll p_count = 0, tmp = res;
      while (tmp % q == 0) {
        tmp /= q;
        ++p_count;
      }
      ll reduce = powl(q, p_count);
      if (reduce < min_factor) min_factor = reduce;
    }
    cout << res / min_factor << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
