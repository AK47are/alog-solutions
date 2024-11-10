// 洛谷-B3694
#include <algorithm>
#include <iostream>
using namespace std;
int a[(int)1e5 + 10], b[(int)1e5 + 10];

void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  auto a_end = unique(a, a + n);
  for (int i = 0; i < n; ++i) {
    cout << lower_bound(a, a_end, b[i]) - a + 1 << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
