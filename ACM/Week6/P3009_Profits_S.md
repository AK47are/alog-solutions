---
title: P3009 [USACO11JAN] Profits S - 洛谷 | 计算机科学教育新生态
source: https://www.luogu.com.cn/problem/P3009
tags:
  - 算法题/思想/动态规划
---

## 题目描述

The cows have opened a new business, and Farmer John wants to see how well they are doing. The business has been running for N (1 <= N <= 100,000) days, and every day i the cows recorded their net profit P\_i (-1,000 <= P\_i <= 1,000).

Farmer John wants to find the largest total profit that the cows have made during any consecutive time period. (Note that a consecutive time period can range in length from one day through N days.) Help him by writing a program to calculate the largest sum of consecutive profits.

奶牛们开始了新的生意，它们的主人约翰想知道它们到底能做得多好。这笔生意已经做了N（1≤N≤100,000）天，每天奶牛们都会记录下这一天的利润Pi（-1,000≤Pi≤1,000）。

约翰想要找到奶牛们在连续的时间期间所获得的最大的总利润。（注：连续时间的周期长度范围从第一天到第N天）。

请你写一个计算最大利润的程序来帮助他。

## 输入格式

\* Line 1: A single integer: N

\* Lines 2..N+1: Line i+1 contains a single integer: P\_i

## 输出格式

\* Line 1: A single integer representing the value of the maximum sum of profits for any consecutive time period.

## 输入输出样例

**输入 #1**

```
7 
-3 
4 
9 
-2 
-5 
8 
-3 
```

## 说明/提示

The maximum sum is obtained by taking the sum from the second through the sixth number (4, 9, -2, -5, 8) => 14.

感谢@smartzzh 提供的翻译。

## 题解
$dp[i]$ 代表以 $i$ 为结尾的最大和。$dp[i] = max(dp[i - 1] + a[i], a[i])$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> dp(N, 0);
  for (auto& value : dp) cin >> value;
  for (int i = 0; i < N; ++i) {
    dp[i] = max(dp[i - 1] + dp[i], dp[i]);
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
}
```
