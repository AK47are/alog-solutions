# [D. Odd Queries](https://codeforces.com/problemset/problem/1807/D)

## 题解
直接暴力，百分百超，使用前缀和，将数组分成三部分$[0, l), [l, r], (l, n)$，当且仅当和都是奇数或其中一个为奇数时它们的和为奇数。复杂度为 $O(t(n + q))$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void Solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> prefix(n + 2);
  for (int i = 2; i < n + 2; ++i) {
    cin >> prefix[i];
    prefix[i] += prefix[i - 1];
  }
  ll l, r, k;
  while (q--) {
    cin >> l >> r >> k;
    if ((prefix[l] + prefix[n + 1] - prefix[r + 1] + (r - l + 1) * k) % 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```

