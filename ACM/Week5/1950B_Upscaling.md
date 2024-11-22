# [Upscaling](https://codeforces.com/problemset/problem/1950/B)

## 题解
很简单
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      if (((i / 2) + (j / 2)) % 2 == 0)
        cout << "#";
      else
        cout << ".";
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
