#include <iostream>
#include <stack>
using namespace std;
stack<int> s;

int main() {
  int t, n;
  string col;
  cin >> t;
  while (t--) {
    cin >> n;
    while (n--) {
      cin >> col;
      s.push(col.find('#') + 1);
    }
    while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << "\n";
  }
}
