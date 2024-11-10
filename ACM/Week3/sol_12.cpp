// Showering
#include <iostream>
using namespace std;

void Solve() {
  int n, s, m;
  cin >> n >> s >> m;
  bool is_yes = false;
  int prev_r = 0, l;
  while (n--) {
    cin >> l;
    if ((l - prev_r) >= s) is_yes = true;
    cin >> prev_r;
  }
  if ((m - prev_r) >= s) is_yes = true;
  if (is_yes)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
