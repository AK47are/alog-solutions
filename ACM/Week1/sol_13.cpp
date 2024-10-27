// 洛谷 p10472
#include <iostream>
#include <stack>
#include <string>
using namespace std;
signed main() {
  string str;
  cin >> str;
  stack<char> stack;
  stack.push('!');
  int max_length = 0;
  for (int i = 0; i < str.size(); i++) {
    int now = 0;
    for (int j = i; j < str.size(); j++) {
      if (str[j] == '(' || str[j] == '[' || str[j] == '{') stack.push(str[j]);
      if (str[j] == ')') {
        if (stack.top() == '(')
          stack.pop(), now++;
        else
          break;
      }
      if (str[j] == ']') {
        if (stack.top() == '[')
          stack.pop(), now++;
        else
          break;
      }
      if (str[j] == '}') {
        if (stack.top() == '{')
          stack.pop(), now++;
        else
          break;
      }
      if (stack.size() == 1) max_length = max(max_length, now * 2);
    }
    while (stack.size() != 1) stack.pop();
  }
  cout << max_length << "\n";
  return 0;
}
