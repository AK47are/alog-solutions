// 洛谷 P9712
#include <iostream>
#include <string>

using namespace std;
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ++i) {
    str[i] = tolower(str[i]);
    if (str[i] == '_') str[i] = '-';
  }
  cout << "solution-" + str << "\n";
}
