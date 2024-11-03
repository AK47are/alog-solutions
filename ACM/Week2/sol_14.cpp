// 因为 x 一定小于 n 所以一定其实可以用布尔型数组来判断，更简单。
// 这里就用我自己的原方案了。
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long t;
  vector<long long> y0, y1;
  cin >> t;
  while (t--) {
    long long n, count;
    cin >> n;
    count = 0;
    while (n--) {
      long long x, y;
      cin >> x >> y;
      if (y == 0)
        y0.push_back(x);
      else
        y1.push_back(x);
    }
    sort(y1.begin(), y1.end());
    sort(y0.begin(), y0.end());

    // 计算平线直角。
    long long y1_index = 0;
    for (long long i = 0; i < y0.size(); ++i) {
      while (y1_index < y1.size() && y1[y1_index] < y0[i]) ++y1_index;
      if (y1_index == y1.size()) break;
      if (y1[y1_index] == y0[i]) count += y0.size() + y1.size() - 2;
      if (y1_index - 1 >= 0) {
        if (y1[y1_index] == y0[i] && y1_index + 1 < y1.size()) {
          if (y1[y1_index - 1] == y0[i] - 1 && y1[y1_index + 1] == y0[i] + 1)
            ++count;
        } else {
          if (y1[y1_index - 1] == y0[i] - 1 && y1[y1_index] == y0[i] + 1)
            ++count;
        }
      }
    }
    long long y0_index = 0;
    for (long long i = 0; i < y1.size(); ++i) {
      while (y0_index < y0.size() && y0[y0_index] < y1[i]) ++y0_index;
      if (y0_index == y0.size()) break;
      if (y0_index - 1 >= 0) {
        if (y0[y0_index] == y1[i] && y0_index + 1 < y0.size()) {
          if (y0[y0_index - 1] == y1[i] - 1 && y0[y0_index + 1] == y1[i] + 1)
            ++count;
        } else {
          if (y0[y0_index - 1] == y1[i] - 1 && y0[y0_index] == y1[i] + 1)
            ++count;
        }
      }
    }
    cout << count << "\n";
    y0.clear();
    y1.clear();
  }
}
