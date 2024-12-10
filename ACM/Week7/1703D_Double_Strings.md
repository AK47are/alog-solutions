# [D. Double Strings](https://codeforces.com/problemset/problem/1703/D)

## 题解
哈希表的运用，不要使用无序图，占用空间大还更慢，[原因](https://codeforces.com/blog/entry/50626)很可能是由于一些特殊的测试数据导致桶冲突严重，查看可以发现一些测试点耗时会突然变得非常高（ 600ms ）。

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<string> str(1e5);
unordered_map<string, int> str_count(1e5 * 4);

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
    ++str_count[str[i]];
  }
  for (int i = 0; i < n; ++i) {
    if (str_count[str[i]] > 1) {
      cout << 1;
    } else {
      bool is_exist = 0;
      for (int j = 1; j < str[i].size(); ++j) {
        if (str_count[str[i].substr(0, j)] != 0 &&
            str_count[str[i].substr(j, str[i].size() - j)] != 0) {
          is_exist = 1;
        }
      }
      cout << is_exist;
    }
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

```
