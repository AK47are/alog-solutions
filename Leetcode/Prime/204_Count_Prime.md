# [204. Count Prime](https://leetcode.cn/problems/count-primes/)

## 思路：
核心在于判断素数的算法。

## 题解：

### 法一：暴力枚举（会超时）
```cpp
class Solution {
public:
    vector<int> prime;
    bool isPrime(int n) {
        if (n <= 1) return false;
        bool is_prime = true;
        for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); ++i) {
            if (n % prime[i] == 0) {
                is_prime = false;
                break;
            }
        }
        return is_prime;
    }

    int countPrimes(int n) {
        for (int i = 1; i < n; ++i) {
            if (isPrime(i)) prime.push_back(i);
        }
        return prime.size();
    }
};
```

### 法二：埃式筛
如果 $x$ 是质数，那么 $x$ 的倍数一定不是质数。如果不是，那倍数更不可能是。如果当前 is_prime[i] 为 0 则代表它无法被前面任何数整除，即它为素数。

```cpp
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> is_prime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (is_prime[i])  {
                ++count;
                // 由于 i ~ i * i 之前的数一定被 2, 3, ..., i - 1 经历过，所以不用管。
                for (long long j = (long long)i * i; j < n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
        return count;
    }
};
```

### 法三：线性筛（欧拉筛）
通过保证每个合数只会被其最小公因子筛去，使时间复杂度为 $O(n)$ 。因为每个数都可由质数表示，所以其最小公因子一定为素数。因此我们可以通过一个记录素数的数组和当前数相乘筛去后面的数。一个 $x$ 一定可以分解成其最小公因子和另一个数的乘积，且这两个数一定都小于 $x$ ，也就是说如果 x 不为素数，那么在遍历到它之前它一定会被筛掉，如果为质数就不可能被筛掉。

值得注意的是如果当前数为某个质数的倍数，那么其他质数（大于这个质数）和它相乘不属于最小公因子筛掉的。由于它的除模操作，在小数据反而更慢。

```cpp
class Solution {
public:
    // 包括 n
    int countPrimes(int n) {
        // 注意细节 n + 1
        vector<bool> is_prime(n + 1, 1);
        vector<int> prime;
        // 注意 i <= n
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i])  {
                prime.push_back(i);
            }
            // 注意 i * prime[j] <= n
            for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j) {
                is_prime[i * prime[j]] = 0; 
                // i 为 prime[j] 的倍数不要紧，再大 prime[j] 不可能是最小公因子。因为 i 已经明确可分为 prime[j] * prime[j]
                if (i % prime[j] == 0) break;
            }
        }
        return prime.size();
    }
};

```
