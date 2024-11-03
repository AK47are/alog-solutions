// 洛谷-P2004
#include <iostream>
using namespace std;
long long prefix[1024][1024];

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> prefix[i][j];
      prefix[i][j] +=
          prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
  }

  long X = 0, Y = 0, max = 0, temp = 0;
  for (int x = 0; x + C <= N; ++x) {
    for (int y = 0; y + C <= M; ++y) {
      temp = prefix[x + C][y + C] - prefix[x + C][y] - prefix[x][y + C] +
             prefix[x][y];
      if (max < temp) {
        X = x;
        Y = y;
        max = temp;
      }
    }
  }
  cout << X + 1 << " " << Y + 1 << "\n";
}
