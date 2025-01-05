---
title: Problem - 1703B - Codeforces
source: https://codeforces.com/problemset/problem/1703/B
tags:
  - 算法题/思想/贪心 
---

## 题目描述
In an ICPC contest, balloons are distributed as follows:

- Whenever a team solves a problem, that team gets a balloon.
- The first team to solve a problem gets an additional balloon.

A contest has 26 problems, labelled $\text{A}$, $\text{B}$, $\text{C}$, ..., $\text{Z}$. You are given the order of solved problems in the contest, denoted as a string $s$, where the $i$\-th character indicates that the problem $s_{i}$ has been solved by some team. No team will solve the same problem twice.

Determine the total number of balloons that the teams received. Note that some problems may be solved by none of the teams.

Input

The first line of the input contains an integer $t$ ($1 \leq t \leq 100$) — the number of testcases.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 50$) — the length of the string.

The second line of each test case contains a string $s$ of length $n$ consisting of uppercase English letters, denoting the order of solved problems.

Output

For each test case, output a single integer — the total number of balloons that the teams received.

Example

```
63ABA1A3ORZ5BAAAA4BKPT10CODEFORCES
```

Note

In the first test case, $5$ balloons are given out:

- Problem $\text{A}$ is solved. That team receives $2$ balloons: one because they solved the problem, an an additional one because they are the first team to solve problem $\text{A}$.
- Problem $\text{B}$ is solved. That team receives $2$ balloons: one because they solved the problem, an an additional one because they are the first team to solve problem $\text{B}$.
- Problem $\text{A}$ is solved. That team receives only $1$ balloon, because they solved the problem. Note that they don't get an additional balloon because they are not the first team to solve problem $\text{A}$.

The total number of balloons given out is $2 + 2 + 1 = 5$.

In the second test case, there is only one problem solved. The team who solved it receives $2$ balloons: one because they solved the problem, an an additional one because they are the first team to solve problem $\text{A}$.

## 题解
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> visited(26);
  int n, res = 0;
  cin >> n;
  res += n;
  while (n--) {
    char c;
    cin >> c;
    if (visited[c - 'A'] == 0) {
      ++res;
      visited[c - 'A'] = 1;
    }
  }
  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```

