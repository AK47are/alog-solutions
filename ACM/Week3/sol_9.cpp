#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void Solve() {
  int n, q, temp;
  cin >> n >> q;

  vector<int> candy(n);
  for (auto& value : candy) cin >> value;
  sort(candy.begin(), candy.end(), greater<int>());
  partial_sum(candy.begin(), candy.end(), candy.begin());

  while (q--) {
    cin >> temp;
    auto lb = lower_bound(candy.begin(), candy.end(), temp);
    if (lb == candy.end())
      cout << -1 << "\n";
    else
      cout << lb - candy.begin() + 1 << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
