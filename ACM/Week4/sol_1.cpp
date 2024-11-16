// 洛谷-B3625
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m;

bool Dfs(vector<string>& maze, pair<int, int> coord) {
  if (coord.first >= n || coord.second >= m || coord.first < 0 ||
      coord.second < 0 || maze[coord.first][coord.second] == '#')
    return false;
  else if (coord.first == n - 1 && coord.second == m - 1)
    return true;
  else {
    maze[coord.first][coord.second] = '#';
    return Dfs(maze, {coord.first - 1, coord.second}) ||
           Dfs(maze, {coord.first + 1, coord.second}) ||
           Dfs(maze, {coord.first, coord.second - 1}) ||
           Dfs(maze, {coord.first, coord.second + 1});
  }
}

int main() {
  cin >> n >> m;
  vector<string> maze(n);
  cin.ignore();
  for (auto& str : maze) getline(cin, str);
  if (Dfs(maze, {0, 0}))
    cout << "Yes\n";
  else
    cout << "No\n";
}
