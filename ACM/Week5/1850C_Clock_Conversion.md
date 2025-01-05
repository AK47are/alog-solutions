---
title: Problem - 1950C - Codeforces
source: https://codeforces.com/problemset/problem/1950/C
tags:
  - 算法题/数据结构/字符串 
---

## 题目描述
Given the time in 24-hour format, output the equivalent time in 12-hour format.

- [24-hour format](https://en.wikipedia.org/wiki/24-hour_clock#Description) divides the day into 24 hours from $00$ to $23$, each of which has 60 minutes from $00$ to $59$.
- [12-hour format](https://en.wikipedia.org/wiki/12-hour_clock#Description) divides the day into two halves: the first half is $A M$, and the second half is $P M$. In each half, the hours are numbered in the order $12 , 01 , 02 , 03 , \ldots , 11$. Each hour has 60 minutes numbered from $00$ to $59$.

Input

The first line contains a single integer $t$ ($1 \leq t \leq 1440$) — the number of test cases.

The only line of each test case contains a string $s$ of length $5$ with format hh:mm representing a valid time in the 24-hour format. hh represents the hour from $00$ to $23$, and mm represents the minute from $00$ to $59$.

The input will always be a valid time in 24-hour format.

Output

For each test case, output two strings separated by a space ("hh:mm AM" or "hh:mm PM"), which are the 12-hour equivalent to the time provided in the test case (without quotes).

You should output the time exactly as indicated; in particular, you should not remove leading zeroes.

Example

```
1109:4118:0612:1400:5900:0014:3401:0119:0711:5912:0021:37
```

```
09:41 AM
06:06 PM
12:14 PM
12:59 AM
12:00 AM
02:34 PM
01:01 AM
07:07 PM
11:59 AM
12:00 PM
09:37 PM
```

## 题解
很简单。
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  string time;
  string flag = "AM";
  cin >> time;
  if (time[0] == '1' && time[1] >= '2') {
    if (time[1] > '2') {
      time[0] -= 1;
      time[1] -= 2;
    }
    flag = "PM";
  } else if (time[0] == '2') {
    time[0] -= 1;
    flag = "PM";
    if (time[1] >= '2') {
      time[1] -= 2;
    } else {
      time[0] -= 1;
      time[1] = time[1] + 8;
    }
  } else if (time[0] == '0' && time[1] == '0') {
    time[0] = '1';
    time[1] = '2';
  }
  cout << time << " " << flag << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
