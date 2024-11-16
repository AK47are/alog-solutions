// 洛谷-P1706
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void Solve(vector<bool>& visited, vector<int>& path) {
  if (path.size() == visited.size()) {
    for (auto value : path) cout << setw(5) << value;
    cout << "\n";
    return;
  }
  for (int i = 0; i < visited.size(); ++i) {
    if (visited[i] == 0) {
      visited[i] = 1;
      path.push_back(i + 1);
      Solve(visited, path);
      visited[i] = 0;
      path.pop_back();
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<bool> visited(n, 0);
  vector<int> path;
  Solve(visited, path);
}
