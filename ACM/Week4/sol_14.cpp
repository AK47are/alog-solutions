// Codeforces Round #784 (Div. 4)A-H
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int i = 0;
  char target;
  while (true) {
    while (i < str.size() && str[i] == 'W') ++i;
    if (i == str.size()) break;
    int is_another = false;
    char first = str[i];
    while (i < str.size() && str[i] != 'W') {
      if (first == 'B' && str[i] == 'R')
        is_another = true;
      else if (first == 'R' && str[i] == 'B')
        is_another = true;
      ++i;
    }
    if (!is_another) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
