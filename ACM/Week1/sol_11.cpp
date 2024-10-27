// 洛谷题 B3956
#include <cctype>
#include <iostream>
using namespace std;

int main() {
  int n, sum = 0;
  char temp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    sum += (isupper(temp)) ? ~temp + 1 : temp - 'a' + 1;
  }
  cout << sum << "\n";
}
