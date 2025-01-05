---
title: Problem - 1703A - Codeforces
source: https://codeforces.com/problemset/problem/1703/A
tags:
  - 算法题/数据结构/字符串
---

## 题目描述
There is a string $s$ of length $3$, consisting of uppercase and lowercase English letters. Check if it is equal to "YES" (without quotes), where each letter can be in any case. For example, "yES", "Yes", "yes" are all allowable.

Input

The first line of the input contains an integer $t$ ($1 \leq t \leq \left(10\right)^{3}$) — the number of testcases.

The description of each test consists of one line containing one string $s$ consisting of three characters. Each character of $s$ is either an uppercase or lowercase English letter.

Output

For each test case, output "YES" (without quotes) if $s$ satisfies the condition, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yES", "yes" and "Yes" will be recognized as a positive response).

Example

```
10YESyESyesYesYeSNooorZyEzYasXES
```

```
YES
YES
YES
YES
YES
NO
NO
NO
NO
NO
```

Note

The first five test cases contain the strings "YES", "yES", "yes", "Yes", "YeS". All of these are equal to "YES", where each character is either uppercase or lowercase.

## 题解
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  getline(cin, str);
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  if (str == "yes")
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  cin.get();
  while (t--) solve();
}
```
