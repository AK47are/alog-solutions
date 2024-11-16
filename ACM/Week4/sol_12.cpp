#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n, temp;
  cin >> n;
  vector<int> arr(n);
  while (n--) {
    cin >> temp;
    ++arr[temp - 1];
  }
  int res = -1;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] >= 3) {
      res = i + 1;
      break;
    }
  }
  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
