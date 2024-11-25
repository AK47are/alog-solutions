# [A. Plus or Minus](https://codeforces.com/problemset/problem/1807/A)

## 题解
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b == c)
    cout << "+\n";
  else
    cout << "-\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
