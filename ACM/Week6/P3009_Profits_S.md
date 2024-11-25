# [P3009 [USACO11JAN] Profits S](https://www.luogu.com.cn/problem/P3009)

## 题解
$dp[i]$ 代表以 $i$ 为结尾的最大和。$dp[i] = max(dp[i - 1] + a[i], a[i])$

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> dp(N, 0);
  for (auto& value : dp) cin >> value;
  for (int i = 0; i < N; ++i) {
    dp[i] = max(dp[i - 1] + dp[i], dp[i]);
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
}
```
