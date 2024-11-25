# [C. Find and Replace](https://codeforces.com/problemset/problem/1807/C)

## 题解
直接暴力。

```cpp
#include <bits/stdc++.h>
using namespace std;

bool Func(string str, char init) {
  map<char, char> s;
  s[str[0]] = init;
  str[0] = init;
  for (int i = 1; i < str.size(); ++i) {
    if (s.find(str[i]) == s.end()) s[str[i]] = (str[i - 1] == '0') ? '1' : '0';
    str[i] = s[str[i]];
    if (str[i - 1] == str[i]) return false;
  }
  return true;
}

void Solve() {
  int n;
  string str;
  cin >> n;
  cin.ignore();
  getline(cin, str);
  if (Func(str, '0') || Func(str, '1'))
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

