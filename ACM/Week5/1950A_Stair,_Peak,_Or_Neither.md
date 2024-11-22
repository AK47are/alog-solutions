# [Stair, Peak, or Neither?](https://codeforces.com/problemset/problem/1950/A)

## 题解
很简单
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int digit[3];
  for (auto& value : digit) cin >> value;
  if (digit[0] < digit[1] && digit[1] < digit[2])
    cout << "STAIR\n";
  else if (digit[0] < digit[1] && digit[2] < digit[1])
    cout << "PEAK\n";
  else
    cout << "NONE\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```

