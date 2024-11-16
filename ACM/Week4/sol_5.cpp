// 洛谷-P1451
#include <iostream>
using namespace std;

int n, m;
int res;
char matrix[105][105];
void Dfs(int x, int y) {
  if (x > n || x < 1 || y > m || y < 1 || matrix[x][y] == '0') return;
  matrix[x][y] = '0';
  Dfs(x + 1, y);
  Dfs(x, y + 1);
  Dfs(x - 1, y);
  Dfs(x, y - 1);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> matrix[i][j];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (matrix[i][j] != '0') {
        ++res;
        Dfs(i, j);
      }
    }
  }
  cout << res << "\n";
}
