---
title: Problem - 1807C - Codeforces
source: https://codeforces.com/problemset/problem/1807/C
tags:
  - 算法题/思想/贪心
---

## 题目描述
You are given a string $s$ consisting of lowercase Latin characters. In an operation, you can take a character and replace all occurrences of this character with $\mathtt{0}$ or replace all occurrences of this character with $\mathtt{1}$.

Is it possible to perform some number of moves so that the resulting string is an alternating binary string$^{\dagger}$?

For example, consider the string $\mathtt{abacaba}$. You can perform the following moves:

- Replace $\mathtt{a}$ with $\mathtt{0}$. Now the string is $\mathtt{0} \mathtt{b} \mathtt{0} \mathtt{c} \mathtt{0} \mathtt{b} \mathtt{0}$.
- Replace $\mathtt{b}$ with $\mathtt{1}$. Now the string is $\mathtt{0} \mathtt{1} \mathtt{0} \mathtt{c} \mathtt{0} \mathtt{1} \mathtt{0}$.
- Replace $\mathtt{c}$ with $\mathtt{1}$. Now the string is $\mathtt{0} \mathtt{1} \mathtt{0} \mathtt{1} \mathtt{0} \mathtt{1} \mathtt{0}$. This is an alternating binary string.

$^{\dagger}$An alternating binary string is a string of $\mathtt{0}$s and $\mathtt{1}$s such that no two adjacent bits are equal. For example, $\mathtt{01010101}$, $\mathtt{101}$, $\mathtt{1}$ are alternating binary strings, but $\mathtt{0110}$, $\mathtt{0a0a0}$, $\mathtt{10100}$ are not.

Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2000$) — the length of the string $s$.

The second line of each test case contains a string consisting of $n$ lowercase Latin characters — the string $s$.

Output

For each test case, output "YES" (without quotes) if you can make the string into an alternating binary string, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example

```
87abacaba2aa1y4bkpt6ninfia6banana10codeforces8testcase
```

```
YES
NO
YES
YES
NO
YES
NO
NO
```

Note

The first test case is explained in the statement.

In the second test case, the only possible binary strings you can make are $\mathtt{00}$ and $\mathtt{11}$, neither of which are alternating.

In the third test case, you can make $\mathtt{1}$, which is an alternating binary string.

## 题解
直接暴力。

```cpp
#include <bits/stdc++.h>
using namespace std;

bool Func(string str, char init) {
  map<char, char> s;
  s[str[0]] = init;
  str[0] = init;
  for (int i = 1; i < str.size(); ++i) {
    if (s.find(str[i]) == s.end()) s[str[i]] = (str[i - 1] == '0') ? '1' : '0';
    str[i] = s[str[i]];
    if (str[i - 1] == str[i]) return false;
  }
  return true;
}

void Solve() {
  int n;
  string str;
  cin >> n;
  cin.ignore();
  getline(cin, str);
  if (Func(str, '0') || Func(str, '1'))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```

