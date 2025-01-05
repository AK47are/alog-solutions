---
title: Problem - 1062
source: https://acm.hdu.edu.cn/showproblem.php?pid=1062
tags:
  - 算法题/数据结构/栈 
---

## 题目描述
Ignatius likes to write words in reverse way. Given a single line of text which is written by Ignatius, you should reverse all the words and then output them.  

The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.  
Each test case contains a single line with several words. There will be at most 1000 characters in a line.  

For each test case, you should output the text which is processed.  

```
3
olleh !dlrow
m'I morf .udh
I ekil .mca
```

```
hello world!
I'm from hdu.
I like acm.
```

Remember to use getchar() to read '\\n' after the interger T, then you may use gets() to read a line and process it.

## 题解
栈的简单运用。

```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  stack<char> s;
  for (char c = cin.get(); c != '\n'; c = cin.get()) {
    if (c == ' ') {
      while (!s.empty()) {
        cout << s.top();
        s.pop();
      }
      cout << " ";
    } else {
      s.push(c);
    }
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << '\n';
}

int main() {
  int T;
  cin >> T;
  cin.get();
  while (T--) Solve();
}
```
