# [P2947 \[USACO09MAR\] Look Up S](https://www.luogu.com.cn/problem/P2947)

## 题解
使用单调递减栈。进栈元素如果不大于栈顶元素，代表该奶牛不为栈中任意元素的仰望对象。如果大于那就代表是栈中小于该元素的元素的最近仰望对象。让全部满足条件的元素出栈。最后剩下的元素没有仰望对象。

时间复杂度为 $O(n)$ 。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N), res(N);
  for (auto& value : a) cin >> value;
  stack<int> desc;
  for (int i = 0; i < N; ++i) {
    while (!desc.empty() && a[desc.top()] < a[i]) {
      res[desc.top()] = i + 1;
      desc.pop();
    }
    desc.push(i);
  }
  for (auto value : res) cout << value << "\n";
}
```

