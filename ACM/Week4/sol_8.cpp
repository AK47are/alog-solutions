// 洛谷-P1379 值得重看
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  // 使用无序图同时完成找当前层数和是否走过这个状态两个事情
  unordered_map<string, int> dict;
  string str;
  string target("123804765");
  getline(cin, str);
  queue<string> q;
  q.push(str);
  while (!q.empty()) {
    str = q.front();
    q.pop();
    if (str == target) {
      cout << dict[str] << "\n";
      break;
    }
    int zero_pos = str.find('0');
    int x = zero_pos / 3, y = zero_pos % 3;
    for (int i = 0; i < 4; ++i) {
      int x1 = x + dx[i], y1 = y + dy[i];
      if (x1 < 0 || x1 >= 3 || y1 < 0 || y1 >= 3) continue;
      int dis = dict[str];
      swap(str[zero_pos], str[x1 * 3 + y1]);
      if (!dict.count(str)) {
        dict[str] = dis + 1;
        q.push(str);
      }
      swap(str[zero_pos], str[x1 * 3 + y1]);
    }
  }
}
