---
title: Problem - 1703F - Codeforces
source: https://codeforces.com/problemset/problem/1703/F
tags:
  - 算法题/题型/差分
  - 算法题/题型/前缀和 
---

## 题目描述
You are given an array $a_{1} , a_{2} , \ldots a_{n}$. Count the number of pairs of indices $1 \leq i , j \leq n$ such that $a_{i} < i < a_{j} < j$.

Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains an integer $n$ ($2 \leq n \leq 2 \cdot \left(10\right)^{5}$) — the length of the array.

The second line of each test case contains $n$ integers $a_{1} , a_{2} , \ldots , a_{n}$ ($0 \leq a_{i} \leq \left(10\right)^{9}$) — the elements of the array.

It is guaranteed that the sum of $n$ across all test cases does not exceed $2 \cdot \left(10\right)^{5}$.

Output

For each test case, output a single integer — the number of pairs of indices satisfying the condition in the statement.

Please note, that the answer for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).

Example

```
581 1 2 3 8 2 1 421 2100 2 1 6 3 4 1 2 8 321 100000000030 1000000000 2
```

Note

For the first test cases the pairs are $\left(\right. i , j \left.\right)$ = $\left{\right. \left(\right. 2 , 4 \left.\right) , \left(\right. 2 , 8 \left.\right) , \left(\right. 3 , 8 \left.\right) \left.\right}$.

- The pair $\left(\right. 2 , 4 \left.\right)$ is true because $a_{2} = 1$, $a_{4} = 3$ and $1 < 2 < 3 < 4$.
- The pair $\left(\right. 2 , 8 \left.\right)$ is true because $a_{2} = 1$, $a_{8} = 4$ and $1 < 2 < 4 < 8$.
- The pair $\left(\right. 3 , 8 \left.\right)$ is true because $a_{3} = 2$, $a_{8} = 4$ and $2 < 3 < 4 < 8$.

## 题解
如果使用暴力法，要花费 $O(n)$ 以不同下标为起点，花费 $O(n)$ 遍历 $i$ 后面的下标判断是否符合条件。很显然我们需要找到一个办法以不超过 $O(log(n))$ 得到符合条件的个数。

我们可以使用一个数组记录以 $i$ 为起点时满足 $i < a_j$ 的个数，我们可以发现满足 $i < a_i$ 下标一定有 $0 \sim a_i - 1$ ，这是区间覆盖，因此我们可以使用差分数组，最后通过前缀和即可得到满足 $i < a_j$ 的个数。

由于条件还要求 $a_i < i$ 我们在以不同下标为起点和差分数组修改时要判断一下是否满足。

时间复杂度为 $O(n)$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long long> diff(n + 1), a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i <= a[i]) continue;
    ++diff[1];
    --diff[a[i]];
  }
  long long ans = 0;
  partial_sum(diff.begin(), diff.end(), diff.begin());
  for (int i = 1; i <= n; ++i) {
    if (i <= a[i]) continue;
    ans += diff[i];
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```

