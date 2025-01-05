---
title: 172. Factorial Trailing Zeroes - 力扣（LeetCode）
source: https://leetcode.cn/problems/factorial-trailing-zeroes/
tags:
  - 算法题/题型/数论/质因子分解
---

## 题目描述
给定一个整数 `n` ，返回 `n!` 结果中尾随零的数量。

提示 `n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1`

**示例 1：**

> **输入：**n = 3
> **输出：**0
> **解释：**3! = 6 ，不含尾随 0

**示例 2：**

> **输入：**n = 5
> **输出：**1
> **解释：**5! = 120 ，有一个尾随 0

**示例 3：**

> **输入：**n = 0
> **输出：**0

**提示：**

- `0 <= n <= 104`

**进阶：**你可以设计并实现对数时间复杂度的算法来解决此问题吗？

## 题解
注意到 $0 <= n <= 10^4$ 所以没办法直接暴力计算。因为 $n!$ 最大因子为 $n$，那么 $n$ 一定可以由小于 $n$ 的质数表示。我们想知道有几个尾零，即 $n!$ 可以分解出几个 10 出来。可以发现 $10$ 只能由质数 2 * 5 得到。问题就转化成了 $n!$ 中有几个 2 和 5 ，计算一下即可得到。

### 法一：暴力枚举
```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int temp = 0, num2 = 0, num5 = 0;
        for (int i = 1; i <= n; ++i) {
            temp = i;
            while (temp % 2 == 0) {
                temp /= 2;
                ++num2;
            }
            temp = i;
            while (temp % 5 == 0) {
                temp /= 5;
                ++num5;
            }
        }
        return min(num2, num5);
    }
};
```
时间复杂度为 $O(nlog_2{n})$

由于质因子 5 的个数大小一定不大于质因子 2 的个数且质因数有 5 的一定是五的倍数 ，所以我们可以只求质因子 5 的个数。
```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int temp = 0, num2 = 0, num5 = 0;
        for (int i = 5; i <= n; i += 5) {
            temp = i;
            while (temp % 5 == 0) {
                temp /= 5;
                ++num5;
            }
        }
        return num5;
    }
};
```
时间复杂度为 $O(n)$ 

### 法二：
<!-- TODO: 待补充 -->
```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
```
