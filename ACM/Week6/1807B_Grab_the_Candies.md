# [B. Grab the Candies](https://codeforces.com/problemset/problem/1807/B)

## 题解
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n, tmp, even_sum = 0, odd_sum = 0;
  cin >> n;
  while (n--) {
    cin >> tmp;
    if (tmp % 2 == 0)
      even_sum += tmp;
    else
      odd_sum += tmp;
  }
  if (even_sum > odd_sum)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
