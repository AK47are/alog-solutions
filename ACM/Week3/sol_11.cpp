// Card Game
#include <iostream>
using namespace std;

void Solve() {
  int a1, a2, b1, b2, res = 0;
  cin >> a1 >> a2 >> b1 >> b2;
  if (a1 > b1 && a2 >= b2)
    res += 2;
  else if (a1 == b1 && a2 > b2)
    res += 2;
  if (a2 > b1 && a1 >= b2)
    res += 2;
  else if (a2 == b1 && a1 > b2)
    res += 2;
  cout << res << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
