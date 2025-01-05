---
title: Problem - 1703D - Codeforces
source: https://codeforces.com/problemset/problem/1703/D
tags:
  - 算法题/数据结构/unordered_map
  - 算法题/数据结构/字符串 
---

## 题目描述
You are given $n$ strings $s_{1} , s_{2} , \ldots , s_{n}$ of length at most $8$.

For each string $s_{i}$, determine if there exist two strings $s_{j}$ and $s_{k}$ such that $s_{i} = s_{j} + s_{k}$. That is, $s_{i}$ is the concatenation of $s_{j}$ and $s_{k}$. Note that $j$ can be equal to $k$.

Recall that the concatenation of strings $s$ and $t$ is $s + t = s_{1} s_{2} \ldots s_{p} t_{1} t_{2} \ldots t_{q}$, where $p$ and $q$ are the lengths of strings $s$ and $t$ respectively. For example, concatenation of "code" and "forces" is "codeforces".

Input

The first line contains a single integer $t$ ($1 \leq t \leq \left(10\right)^{4}$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq \left(10\right)^{5}$) — the number of strings.

Then $n$ lines follow, the $i$\-th of which contains non-empty string $s_{i}$ of length at most $8$, consisting of lowercase English letters. Among the given $n$ strings, there may be equal (duplicates).

The sum of $n$ over all test cases doesn't exceed $\left(10\right)^{5}$.

Output

For each test case, output a binary string of length $n$. The $i$\-th bit should be $\mathtt{1}$ if there exist two strings $s_{j}$ and $s_{k}$ where $s_{i} = s_{j} + s_{k}$, and $\mathtt{0}$ otherwise. Note that $j$ can be equal to $k$.

Example

```
35ababababcabacbc3xxxxxx8codeforcescodescodforcforcesecode
```

Note

In the first test case, we have the following:

- $s_{1} = s_{2} + s_{2}$, since $\mathtt{abab} = \mathtt{ab} + \mathtt{ab}$. Remember that $j$ can be equal to $k$.
- $s_{2}$ is not the concatenation of any two strings in the list.
- $s_{3} = s_{2} + s_{5}$, since $\mathtt{abc} = \mathtt{ab} + \mathtt{c}$.
- $s_{4}$ is not the concatenation of any two strings in the list.
- $s_{5}$ is not the concatenation of any two strings in the list.

Since only $s_{1}$ and $s_{3}$ satisfy the conditions, only the first and third bits in the answer should be $\mathtt{1}$, so the answer is $\mathtt{10100}$.

## 题解
哈希表的运用，不要使用无序图，占用空间大还更慢，[原因](https://codeforces.com/blog/entry/50626)很可能是由于一些特殊的测试数据导致桶冲突严重，查看可以发现一些测试点耗时会突然变得非常高（ 600ms ）。

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<string> str(1e5);
unordered_map<string, int> str_count(1e5 * 4);

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
    ++str_count[str[i]];
  }
  for (int i = 0; i < n; ++i) {
    if (str_count[str[i]] > 1) {
      cout << 1;
    } else {
      bool is_exist = 0;
      for (int j = 1; j < str[i].size(); ++j) {
        if (str_count[str[i].substr(0, j)] != 0 &&
            str_count[str[i].substr(j, str[i].size() - j)] != 0) {
          is_exist = 1;
        }
      }
      cout << is_exist;
    }
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

```
