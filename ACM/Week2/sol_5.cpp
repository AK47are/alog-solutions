// 洛谷-P8218
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  a[0] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  int m, l, r;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r;
    cout << a[r] - a[l - 1] << "\n";
  }
}
