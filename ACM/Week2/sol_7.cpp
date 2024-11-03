// 洛谷-P3397
#include <iostream>
using namespace std;
int diff[1024][1024];

int main() {
  int n, m;
  cin >> n >> m;
  int x1, y1, x2, y2;
  for (int i = 1; i <= m; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    ++diff[x1][y1];
    --diff[x1][y2 + 1];
    --diff[x2 + 1][y1];
    ++diff[x2 + 1][y2 + 1];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      diff[i][j] += diff[i - 1][j];
      diff[i][j] += diff[i][j - 1];
      diff[i][j] -= diff[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << diff[i][j];
      if (j != n) cout << " ";
    }
    cout << "\n";
  }
}
