# [HDU-1062 Text Reverse](https://vjudge.net/problem/HDU-1062/origin)

## 题解
栈的简单运用。

```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  stack<char> s;
  for (char c = cin.get(); c != '\n'; c = cin.get()) {
    if (c == ' ') {
      while (!s.empty()) {
        cout << s.top();
        s.pop();
      }
      cout << " ";
    } else {
      s.push(c);
    }
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << '\n';
}

int main() {
  int T;
  cin >> T;
  cin.get();
  while (T--) Solve();
}
```
