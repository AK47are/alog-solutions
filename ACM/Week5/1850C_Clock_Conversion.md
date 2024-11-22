# [Clock Conversion](https://codeforces.com/problemset/problem/1950/C)

## 题解
很简单。
```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  string time;
  string flag = "AM";
  cin >> time;
  if (time[0] == '1' && time[1] >= '2') {
    if (time[1] > '2') {
      time[0] -= 1;
      time[1] -= 2;
    }
    flag = "PM";
  } else if (time[0] == '2') {
    time[0] -= 1;
    flag = "PM";
    if (time[1] >= '2') {
      time[1] -= 2;
    } else {
      time[0] -= 1;
      time[1] = time[1] + 8;
    }
  } else if (time[0] == '0' && time[1] == '0') {
    time[0] = '1';
    time[1] = '2';
  }
  cout << time << " " << flag << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
