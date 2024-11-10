// 洛谷-P7585
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> marble(M);
  for (auto& value : marble) cin >> value;
  auto max = max_element(marble.begin(), marble.end());

  int low = 1, high = *max;
  while (low != high) {
    long long mid = (low + high) / 2, n = 0;
    for (auto value : marble) n += (value + mid - 1) / mid;
    // cout << low << " " << high << " " << n << "\n";
    if (n > N)
      low = mid + 1;
    else
      high = mid;
  }
  cout << low << "\n";
}
