// Slavic's Exam
#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  string s, t;
  for (int i = 0; i < T; ++i) {
    cin >> s >> t;
    auto temp = t.begin();
    for (auto cur = s.begin(); cur != s.end(); ++cur) {
      if (*cur == '?' || *cur == *temp) {
        *cur = *temp;
        ++temp;
      }
      if (temp == t.end()) break;
    }
    if (temp == t.end()) {
      for (auto cur = s.begin(); cur != s.end(); ++cur) {
        if (*cur == '?') *cur = 'a';
      }
      cout << "YES\n" << s << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
