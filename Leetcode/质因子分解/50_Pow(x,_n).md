---
title: 50. Pow(x, n) - 力扣（LeetCode）
source: https://leetcode.cn/problems/powx-n/
tags:
  - 算法题/题型/数论/质因子分解
---
## 题目描述
实现 [pow(_x_, _n_)](https://www.cplusplus.com/reference/valarray/pow/) ，即计算 `x` 的整数 `n` 次幂函数（即，`xn` ）。

**示例 1：**

> **输入：**x = 2.00000, n = 10
> **输出：**1024.00000

**示例 2：**

> **输入：**x = 2.10000, n = 3
> **输出：**9.26100

**示例 3：**

> **输入：**x = 2.00000, n = -2
> **输出：**0.25000
> **解释：**2-2 = 1/22 = 1/4 = 0.25

**提示：**

- `-100.0 < x < 100.0`
- `-231 <= n <= 231-1`
- `n` 是一个整数
- 要么 `x` 不为零，要么 `n > 0` 。
- `-104 <= xn <= 104`

## 题解

### 法二：快速幂
分治也可以，但要额外占用空间且不如快速幂使用位运算更快。

```cpp
class Solution {
public:
    double myPow(double x, int N) {
        long long n = N; // 防止溢出
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double res = 1;
        while (n != 0) {
            if (1 & n) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};
```