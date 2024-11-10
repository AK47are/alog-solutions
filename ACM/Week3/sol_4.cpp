// 洛谷-P1571
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, int> num;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> science;
  science.resize(n);
  for (int& value : science) {
    cin >> value;
    ++num[value];
  }

  int temp;
  while (m--) {
    cin >> temp;
    ++num[temp];
  }

  for (int value : science)
    if (num[value] == 2) cout << value << " ";
  cout << "\n";
}
