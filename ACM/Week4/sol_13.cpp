#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& value : arr) cin >> value;
  for (int i = 2; i < arr.size(); i += 2) {
    if (arr[i - 2] % 2 != arr[i] % 2) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 3; i < arr.size(); i += 2) {
    if (arr[i - 2] % 2 != arr[i] % 2) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
