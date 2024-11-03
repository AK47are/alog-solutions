// 洛谷-P2367
#include <iostream>
using namespace std;
int diff[size_t(5e6 + 10)];

int main() {
  int n, p, x, y, z;
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) cin >> diff[i];
  for (int i = n; 0 < i; --i) diff[i] -= diff[i - 1];
  for (int i = 0; i < p; ++i) {
    cin >> x >> y >> z;
    diff[x] += z;
    diff[y + 1] -= z;
  }
  unsigned min = ~0;
  for (int i = 1; i <= n; ++i) {
    diff[i] += diff[i - 1];
    if (diff[i] < min) min = diff[i];
  }
  cout << min << "\n";
}
