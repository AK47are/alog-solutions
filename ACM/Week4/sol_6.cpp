// 洛谷-P1219
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int n = 0;
int count = 0;
vector<int> path;

bool IsAttack(pair<int, int> p) {
  for (int i = 0; i < path.size(); ++i) {
    if (p.second == path[i] || p.first - i == abs(p.second - path[i])) {
      return true;
    }
  }
  return false;
}

void Sol(int row) {
  if (row > n) return;
  if (path.size() == n) {
    if (count < 3) {
      for (auto value : path) cout << value + 1 << " ";
      cout << "\n";
    }
    ++count;
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (!IsAttack({row, i})) {
      path.push_back(i);
      Sol(row + 1);
      path.pop_back();
    }
  }
}

int main() {
  cin >> n;
  Sol(0);
  cout << count << "\n";
}
