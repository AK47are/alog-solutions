# [E. Interview](https://codeforces.com/problemset/problem/1807/E)

## 题解
我们知道每堆的石头数量，寻找哪个堆石头数量不等于对应重量。很显然使用折半。查询左半部分重量和，如果等于其石头数量，那么奇特石头在右半边。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool Check(ll low, ll high, vector<ll>& prefix) {
  cout << "? " << high - low + 1 << " ";
  for (ll i = low; i <= high; ++i) {
    cout << i << " ";
  }
  cout << "\n";
  fflush(stdout);
  ll x;
  cin >> x;
  return prefix[high + 1] - prefix[low] != x;
}

void Solve() {
  int n;
  cin >> n;
  vector<ll> prefix(n + 2);
  for (ll i = 2; i < n + 2; ++i) {
    cin >> prefix[i];
    prefix[i] += prefix[i - 1];
  }
  ll mid, high = n, low = 1;
  while (low < high) {
    mid = (high + low) / 2;
    if (Check(low, mid, prefix))
      high = mid;
    else
      low = mid + 1;
  }
  cout << "! " << low << "\n";
  fflush(stdout);
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
