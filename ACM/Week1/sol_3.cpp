// 洛谷 B044
#include <iostream>

using namespace std;
int main() {
  int score[3], count = 0;
  for (int i = 0; i < 3; ++i) {
    cin >> score[i];
    if (score[i] < 60) ++count;
  }
  if (count == 1)
    cout << 1 << "\n";
  else
    cout << 0 << "\n";
}
