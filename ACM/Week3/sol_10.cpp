// A+B Again?
#include <iostream>
using namespace std;

void Solve() {
  char a, b;
  cin >> a >> b;
  cout << a + b - 2 * '0' << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
