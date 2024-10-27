// 洛谷 p1012
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string str[n];
  for (int i = 0; i < n; ++i) cin >> str[i];
  sort(str, str + n, [](string& s1, string& s2) { return s1 + s2 > s2 + s1; });
  for (int i = 0; i < n; ++i) cout << str[i];
  cout << "\n";
}
