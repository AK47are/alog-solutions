// 洛谷-P8648
#include <iostream>
using namespace std;
int diff[10001][10001];

int main() {
  int n, x1, y1, x2, y2;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    ++diff[x1][y1];
    --diff[x2][y1];
    --diff[x1][y2];
    ++diff[x2][y2];
  }
  // 求差分数组前缀和。
  int res = 0;
  for (int i = 0; i < 10001; ++i) {
    for (int j = 0; j < 10001; ++j) {
      if (i != 0) diff[i][j] += diff[i - 1][j];
      if (j != 0) diff[i][j] += diff[i][j - 1];
      if (i != 0 && j != 0) diff[i][j] -= diff[i - 1][j - 1];
    }
  }
  for (int i = 0; i < 10001; ++i) {
    for (int j = 0; j < 10001; ++j) {
      if (diff[i][j] > 0) ++res;
    }
  }
  cout << res << "\n";
}
