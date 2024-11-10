// Triple Operations 待重理解
#include <iostream>
using namespace std;

void Solve() {
  int l, r, res = 0;
  cin >> l >> r;
  int now_3 = 1, prev_3 = l, count = 0;

  while (now_3 <= l) {
    now_3 *= 3;
    ++count;
  }

  res += count;
  while (prev_3 <= r) {
    if (now_3 - 1 <= r)
      res += count * (now_3 - prev_3);
    else
      res += count * (r - prev_3 + 1);
    prev_3 = now_3;
    now_3 *= 3;
    ++count;
  }
  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
