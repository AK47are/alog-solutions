---
title: P1507 NASA的食物计划 - 洛谷 | 计算机科学教育新生态
source: https://www.luogu.com.cn/problem/P1507
tags:
  - 算法题/思想/动态规划
---

## 题目背景

NASA（美国航空航天局）因为航天飞机的隔热瓦等其他安全技术问题一直大伤脑筋，因此在各方压力下终止了航天飞机的历史，但是此类事情会不会在以后发生，谁也无法保证。所以，在遇到这类航天问题时，也许只能让航天员出仓维修。但是过多的维修会消耗航天员大量的能量，因此 NASA 便想设计一种食品方案，使体积和承重有限的条件下多装载一些高卡路里的食物。

## 题目描述

航天飞机的体积有限，当然如果载过重的物品，燃料会浪费很多钱，每件食品都有各自的体积、质量以及所含卡路里。在告诉你体积和质量的最大值的情况下，请输出能达到的食品方案所含卡路里的最大值，当然每个食品只能使用一次。

## 输入格式

第一行 $2$ 个整数，分别代表体积最大值 $h$ 和质量最大值 $t$。

第二行 $1$ 个整数代表食品总数 $n$。

接下来 $n$ 行每行 $3$ 个数 体积 $h_i$，质量 $t_i$，所含卡路里 $k_i$。

## 输出格式

一个数，表示所能达到的最大卡路里（`int` 范围内）

## 输入输出样例

**输入 #1**

```
320 350
4
160 40 120
80 110 240
220 70 310
40 400 220
```

## 说明/提示

对于 $100\%$ 的数据，$h,t,h_i,t_i \le 400$，$n \le 50$，$k_i \le 500$。

## 题解
<!-- TODO: 重理解 -->
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Item {
  int volume;
  int weight;
  int calories;
};

int main() {
  int h, t, n;
  cin >> h >> t >> n;
  vector<Item> item(n);
  for (int i = 0; i < n; ++i) {
    int h, t, k;
    cin >> h >> t >> k;
    item[i] = {h, t, k};
  }

  vector<vector<int>> dp(h + 1, vector<int>(t + 1));
  for (int i = 0; i < n; ++i) {                    // 考虑第 i 个物品。
    for (int j = h; j >= item[i].volume; --j) {    // 体积为 j 时。
      for (int k = t; k >= item[i].weight; --k) {  // 质量为 k 时。
        dp[j][k] = max(dp[j][k], dp[j - item[i].volume][k - item[i].weight] +
                                     item[i].calories);
      }
    }
  }

  cout << dp[h][t] << "\n";
}
```

