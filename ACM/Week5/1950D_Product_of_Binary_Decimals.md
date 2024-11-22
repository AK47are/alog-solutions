# [Product of Binary Decimals](https://codeforces.com/problemset/problem/1950/D)

## 题解
和[分解质因子2](B3715_分解质因子2.md) 很像，区别仅在于这个质因子必须符合二进制十进制。除完判断。
<!-- TODO: 待补充factor 因子是否可以更小。 -->

```cpp
#include <bits/stdc++.h>
using namespace std;

bool IsBinary(int n) {
  string s = to_string(n);
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] != '0' && s[i] != '1') return false;
  }
  return true;
}

void Solve() {
  long long n;
  cin >> n;
  long long res = n;
  vector<int> factor{10, 11, 101, 111, 1001, 1011, 1101, 1111};
  for (auto value : factor)
    while (res % value == 0) res /= value;
  if (res == 1 || IsBinary(n))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  long long t;
  cin >> t;
  while (t--) Solve();
}
```

