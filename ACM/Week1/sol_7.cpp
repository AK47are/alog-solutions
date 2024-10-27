// 洛谷题 P1138
#include <iostream>
#include <queue>
#include <set>

using namespace std;
int main() {
  int n, k, temp;
  cin >> n >> k;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    s.insert(temp);
  }
  priority_queue<int, vector<int>, greater<int>> q;
  for (auto cur = s.begin(); cur != s.end(); ++cur) q.push(*cur);
  if (q.size() < k) {
    cout << "NO RESULT\n";
  } else {
    for (int i = 1; i < k; ++i) q.pop();
    cout << q.top() << "\n";
  }
}
