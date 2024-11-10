// 洛谷-P1918
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n, key;
  cin >> n;
  unordered_map<int, int> nums;
  for (int i = 1; i <= n; ++i) {
    cin >> key;
    nums[key] = i;
  }
  int Q, m;
  cin >> Q;
  while (Q--) {
    cin >> m;
    cout << nums[m] << "\n";
  }
}
