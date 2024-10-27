// 洛谷 B4003
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  const char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int front = n % 26, i;
  for (i = front; (i + 1) % 26 != front; ++i) {
    cout << str[i % 26];
  }
  cout << str[i % 26] << "\n";
}
