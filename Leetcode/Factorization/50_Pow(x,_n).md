# [50. Pow(x, n)](https://leetcode.cn/problems/powx-n/)

## 题解
### 法一：暴力计算
略

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
