# [P1507 NASA的食物计划](https://www.luogu.com.cn/problem/P1507)

## 题解
<!-- TODO: 重理解 -->
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Item {
  int volume;
  int weight;
  int calories;
};

int main() {
  int h, t, n;
  cin >> h >> t >> n;
  vector<Item> item(n);
  for (int i = 0; i < n; ++i) {
    int h, t, k;
    cin >> h >> t >> k;
    item[i] = {h, t, k};
  }

  vector<vector<int>> dp(h + 1, vector<int>(t + 1));
  for (int i = 0; i < n; ++i) {                    // 考虑第 i 个物品。
    for (int j = h; j >= item[i].volume; --j) {    // 体积为 j 时。
      for (int k = t; k >= item[i].weight; --k) {  // 质量为 k 时。
        dp[j][k] = max(dp[j][k], dp[j - item[i].volume][k - item[i].weight] +
                                     item[i].calories);
      }
    }
  }

  cout << dp[h][t] << "\n";
}
```

