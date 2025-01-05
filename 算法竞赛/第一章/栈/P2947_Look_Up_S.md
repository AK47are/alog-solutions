---
title: P2947 [USACO09MAR] Look Up S - 洛谷 | 计算机科学教育新生态
source: https://www.luogu.com.cn/problem/P2947
tags:
  - 算法题/数据结构/栈/单调栈 
---

## 题目描述

Farmer John's N (1 <= N <= 100,000) cows, conveniently numbered 1..N, are once again standing in a row. Cow i has height H\_i (1 <= H\_i <= 1,000,000).

Each cow is looking to her left toward those with higher index numbers. We say that cow i 'looks up' to cow j if i < j and H\_i < H\_j. For each cow i, FJ would like to know the index of the first cow in line looked up to by cow i.

Note: about 50% of the test data will have N <= 1,000.

约翰的 $N(1\le N\le10^5)$ 头奶牛站成一排，奶牛 $i$ 的身高是 $H_i(1\le H_i\le10^6)$。现在，每只奶牛都在向右看齐。对于奶牛 $i$，如果奶牛 $j$ 满足 $i<j$ 且 $H_i<H_j$，我们可以说奶牛 $i$ 可以仰望奶牛 $j$。 求出每只奶牛离她最近的仰望对象。

## 输入格式

1. \* Line 1: A single integer: N

\* Lines 2..N+1: Line i+1 contains the single integer: H\_i

第 $1$ 行输入 $N$，之后每行输入一个身高 $H_i$。

## 输出格式

\* Lines 1..N: Line i contains a single integer representing the smallest index of a cow up to which cow i looks. If no such cow exists, print 0.

共 $N$ 行，按顺序每行输出一只奶牛的最近仰望对象，如果没有仰望对象，输出 $0$。

## 输入输出样例

## 说明/提示

FJ has six cows of heights 3, 2, 6, 1, 1, and 2.

Cows 1 and 2 both look up to cow 3; cows 4 and 5 both look up to cow 6; and cows 3 and 6 do not look up to any cow.

【输入说明】$6$ 头奶牛的身高分别为 3,2,6,1,1,2。

【输出说明】奶牛 #1,#2 仰望奶牛 \#3，奶牛 #4,#5 仰望奶牛 \#6，奶牛 #3 和 #6 没有仰望对象。

【数据规模】

对于 $20\%$ 的数据：$1\le N\le10$；

对于 $50\%$ 的数据：$1\le N\le10^3$；

对于 $100\%$ 的数据：$1\le N\le10^5,1\le H_i\le10^6$。

## 题解
使用单调递减栈。进栈元素如果不大于栈顶元素，代表该奶牛不为栈中任意元素的仰望对象。如果大于那就代表是栈中小于该元素的元素的最近仰望对象。让全部满足条件的元素出栈。最后剩下的元素没有仰望对象。

时间复杂度为 $O(n)$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N), res(N);
  for (auto& value : a) cin >> value;
  stack<int> desc;
  for (int i = 0; i < N; ++i) {
    while (!desc.empty() && a[desc.top()] < a[i]) {
      res[desc.top()] = i + 1;
      desc.pop();
    }
    desc.push(i);
  }
  for (auto value : res) cout << value << "\n";
}
```

