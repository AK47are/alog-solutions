// 洛谷题 P1100
#include <iostream>
using namespace std;

int main() {
  unsigned value, left, right;
  cin >> value;
  left = value << 16;
  right = value >> 16;
  cout << (left | right) << "\n";
}
