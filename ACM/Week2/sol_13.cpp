#include <iostream>
using namespace std;

int main() {
  long long t, x, y, k, count;
  cin >> t;
  while (t--) {
    cin >> x >> y >> k;
    count = (max(x, y) + k - 1) / k * 2;
    // 不能单纯 x > y ，必须是 到 x 的最小步数大于 y 的最小步数
    // x > y 不代表步数大于 y 。
    if ((x + k - 1) / k > (y + k - 1) / k) --count;
    cout << count << "\n";
  }
}
