# [1175. Prime Arrangements](https://leetcode.cn/problems/prime-arrangements/)

## 题解
用[朴素、埃式筛、线性筛](204_Count_Prime.md)等方法得到素数个数，然后排列组合。

```cpp
class Solution {
const int MOD = 1e9 + 7;
public:
    int numPrimeArrangements(int n) {
        vector<bool> is_prime(n + 1, true);
        vector<int> prime;
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i])
                prime.push_back(i);
            for (int j = 0; j < prime.size() && prime[j] * i <= n; ++j) {
                is_prime[prime[j] * i] = false;
                if (i % prime[j] == 0) break;
            }
        }
        cout << prime.size() << "\n";
        return int((factorial(prime.size()) * factorial(n - prime.size())) % MOD);
    }
    long long factorial(int n) {
        long long res = 1;
        for (int i = 1; i <= n; ++i) {
            res *= i;
            res %= MOD;
        }
        return res;
    }
};
```
