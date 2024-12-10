# [B. ICPC Balloons](https://codeforces.com/problemset/problem/1703/B)

## 题解
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> visited(26);
  int n, res = 0;
  cin >> n;
  res += n;
  while (n--) {
    char c;
    cin >> c;
    if (visited[c - 'A'] == 0) {
      ++res;
      visited[c - 'A'] = 1;
    }
  }
  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```

