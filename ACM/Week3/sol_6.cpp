// 洛谷-P2249
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> nums;

int main() {
  int n, m, temp;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> temp;
    if (nums[temp] == 0) nums[temp] = i;
  }
  while (m--) {
    cin >> temp;
    if (nums[temp] == 0)
      cout << -1 << " ";
    else
      cout << nums[temp] << " ";
  }
  cout << "\n";
}
