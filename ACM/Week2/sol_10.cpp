// 洛谷-P1719
#include <iostream>
using namespace std;
long prefix[128][128];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> prefix[i][j];
      prefix[i][j] +=
          prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
  }
  long max = 0, temp = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = i; k <= n; ++k) {
        for (int l = j; l <= n; ++l) {
          temp = prefix[k][l] - prefix[i][l] - prefix[k][j] + prefix[i][j];
          if (max < temp) max = temp;
        }
      }
    }
  }
  cout << max << "\n";
}
