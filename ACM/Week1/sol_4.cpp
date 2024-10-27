// 洛谷题 B2048
#include <iostream>

using namespace std;
int main() {
  unsigned x;
  char c;
  cin >> x >> c;
  unsigned postage = 8;
  if (c == 'y') postage += 5;
  if (x > 1000) postage += (x - 501) / 500 * 4;
  cout << postage << "\n";
}
