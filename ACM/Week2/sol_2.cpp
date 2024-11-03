// 洛谷题 B3908
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  unsigned long x = 0, a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    x ^= a[i];
  }
  cout << x << " 0\n";
}
