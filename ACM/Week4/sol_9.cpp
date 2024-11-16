// 洛谷-P1162
#include <bits/stdc++.h>

using namespace std;
int n;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int matrix[35][35];

void Dfs(int x, int y) {
  if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || matrix[x][y] != 0) return;
  matrix[x][y] = -1;
  for (int i = 0; i < 4; ++i) {
    Dfs(x + dx[i], y + dy[i]);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> matrix[i][j];
    }
  }

  Dfs(0, 0);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (matrix[i][j] == -1)
        cout << "0 ";
      else if (matrix[i][j] == 0)
        cout << "2 ";
      else
        cout << "1 ";
    }
    cout << "\n";
  }
}
