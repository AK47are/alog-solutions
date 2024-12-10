# [E. Mirror Grid](https://codeforces.com/problemset/problem/1703/E)

## 题解
注意判定的格子坐标。

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<char>> matrix(n, vector<char>(n));
  for (auto& line : matrix) {
    for (auto& value : line) {
      cin >> value;
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int count0 = 0, count1 = 0;
      int dx[4] = {i, j, n - j - 1, n - i - 1};
      int dy[4] = {j, n - i - 1, i, n - j - 1};
      for (int k = 0; k < 4; ++k) {
        if (matrix[dx[k]][dy[k]] == '0')
          ++count0;
        else
          ++count1;
      }
      count += min(count0, count1);
    }
  }
  cout << count / 4 << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```

