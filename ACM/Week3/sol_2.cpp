// 洛谷-P1678
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  vector<int> school, student;
  school.resize(m);
  student.resize(n);

  for (int& value : school) cin >> value;
  sort(school.begin(), school.end());

  long long ans = 0;
  for (int& value : student) {
    cin >> value;
    auto lb = lower_bound(school.begin(), school.end(), value);
    if (lb == school.begin())
      ans += *lb - value;
    else if (lb == school.end())
      ans += value - *(lb - 1);
    else
      ans += min(*lb - value, value - *(lb - 1));
  }
  cout << ans << "\n";
}
