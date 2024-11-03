// 洛谷-B3919
#include <iostream>
using namespace std;

int main() {
  unsigned n, q, k;
  long sum = 0;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    cin >> k;
    if (!((1 << (k - 1)) & n)) {
      sum -= n;
      n >>= (k - 1);
      ++n;
      n <<= (k - 1);
      sum += n;
    }
  }
  cout << sum << "\n";
}
