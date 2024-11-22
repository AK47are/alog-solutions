# [236. Ugly Number](https://leetcode.cn/problems/ugly-number/)

## 思路解释：
如果 $n$ 为丑数，则一定有 $n = 2^x * 3^y * 5^z$ ，由于任何数都可以由质数表示，如果去除 $n$ 中的 2, 3, 5 因子后仍不为 1 则代表有其他质数因子。


## 代码：

```cpp
class Solution {
public:
    bool isUgly(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
    }
};
```
