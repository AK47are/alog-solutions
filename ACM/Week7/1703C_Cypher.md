# [C. Cypher](https://codeforces.com/problemset/problem/1703/C)

## 题解
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> res(n);
  for (auto& value : res) cin >> value;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    while (b--) {
      char c;
      cin >> c;
      if (c == 'D')
        res[i] = (res[i] + 1) % 10;
      else
        res[i] = (res[i] + 9) % 10;
    }
  }
  for (auto value : res) cout << value << " ";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```

