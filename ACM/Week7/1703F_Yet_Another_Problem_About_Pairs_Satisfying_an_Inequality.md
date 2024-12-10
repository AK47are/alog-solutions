# [F. Yet Another Problem About Pairs Satisfying an Inequality](https://codeforces.com/problemset/problem/1703/F)

## 题解
如果使用暴力法，要花费 $O(n)$ 以不同下标为起点，花费 $O(n)$ 遍历 $i$ 后面的下标判断是否符合条件。很显然我们需要找到一个办法以不超过 $O(log(n))$ 得到符合条件的个数。

我们可以使用一个数组记录以 $i$ 为起点时满足 $i < a_j$ 的个数，我们可以发现满足 $i < a_i$ 下标一定有 $0 \sim a_i - 1$ ，这是区间覆盖，因此我们可以使用差分数组，最后通过前缀和即可得到满足 $i < a_j$ 的个数。

由于条件还要求 $a_i < i$ 我们在以不同下标为起点和差分数组修改时要判断一下是否满足。

时间复杂度为 $O(n)$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long long> diff(n + 1), a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i <= a[i]) continue;
    ++diff[1];
    --diff[a[i]];
  }
  long long ans = 0;
  partial_sum(diff.begin(), diff.end(), diff.begin());
  for (int i = 1; i <= n; ++i) {
    if (i <= a[i]) continue;
    ans += diff[i];
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```

