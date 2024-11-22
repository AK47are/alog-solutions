# [Lonely Numbers](https://codeforces.com/problemset/problem/1424/J)

## 题解
先用几个案例寻找规律：
- $n = 1$，孤独数字有 $1$ ，结果为 $1$ 。
- $n = 2$，孤独数字有 $1, 2$ ，结果为 $2$ 。
- $n = 3$，孤独数字有 $1, 2, 3$ ，结果为 $3$ 。
- $n = 4$，孤独数字有 $1, 3$ ，结果为 $2$ 。
- $n = 5$，孤独数字有 $1, 3, 5$ ，结果为 $3$ 。
- $n = 6$，孤独数字有 $1, 3, 5$ ，结果为 $3$ 。
- $n = 7$，孤独数字有 $1, 3, 5, 7$ ，结果为 $4$ 。
- $n = 8$，孤独数字有 $1, 3, 5, 7$ ，结果为 $4$ 。
- $n = 9$，孤独数字有 $1, 5, 7$ ，结果为 $3$ 。
- $n = 10$，孤独数字有 $1, 5, 7$ ，结果为 $3$ 。

在观察时发现如果两个数互素那么一定不是朋友。且似乎所有合数都一定不孤独。

我们考虑如果 $a$ 恰好为质数且 $b$ 为 $a$ 的倍数，那么有 $1, a, b / a = k$ 这三条边，根据三角形成立的条件，有 $a + 1 > k > a - 1$，即当 $k = a$ 时三角形成立。这说明如果 $a$ 为质数且 $a, a^2 \in [1, n]$，即$a \le \sqrt{n}$ 时 $a$ 一定不孤独。反之 $a$ 一定孤独。

我们再考虑合数，假设合数是 $m$，根据 [分解质因子2](B3715_分解质因子2.md) 一题的证明，可以发现一个合数只能由不大于 $\sqrt{m}$ 的质数构成，假设其中一个质因子为 $x$ ，则有 $m = ax\ a \in [2, \frac{x}{n}]$ 寻找是否有一个数 $b$ ，使得 $bx, ax$ 是朋友。保证 $a, b$ 一定互素，有 $gcd(ax, bx) = x$，根据三角形成立条件，有 $a, b, x$ 三条边，且 $x + a > b, x + b > a, a + b > x, gcd(a, b) = 1$ 即 $a - x < b < a + x$ 。当 $a > x$ 时 $b = a - 1$ 三角形成立；当 $a < x$ 时 $b = x$ 三角形成立。$a - 1, x < m$所以合数一定不孤独。

因此我们只需要处理质数是否孤独。我们使用二分来查找最后不孤独的质数。会超时。

我们换用前缀和，这样就可以以 $O(1)$ 的速度计算。还是会超，可能是由于 vector<ll> prime 的扩容操作，还需要优化，我们使用 list 类。还是会超，改用埃式筛试试。依旧过不了，优化输入输出试试。过了。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6;
vector<ll> is_prime(N + 1, true);
vector<ll> prefix(N + 1, 0);

void GetPrime() {
  for (ll i = 2; i <= N; ++i)
    if (is_prime[i]) {
      for (ll j = i * i; j <= N; j += i) {
        is_prime[j] = 0;
      }
    }
}

void Solve() {
  ll n;
  scanf("%lld", &n);
  cout << prefix[n] - prefix[sqrt(n)] + 1 << "\n";
}

int main() {
  GetPrime();
  is_prime[0] = is_prime[1] = 0;
  partial_sum(is_prime.begin() + 1, is_prime.end(), prefix.begin() + 1);
  int T;
  cin >> T;
  while (T--) Solve();
}
```
