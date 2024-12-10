# [A. YES or YES?](https://codeforces.com/problemset/problem/1703/A)

## 题解
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  getline(cin, str);
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  if (str == "yes")
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  cin.get();
  while (t--) solve();
}
```
