# [Max Sum](https://acm.hdu.edu.cn/showproblem.php?pid=1003)

## 题解
不定长最大和子序列经典题。时间复杂度均为 $O(n)$ 。

### 法一：贪心
选择尽可能多的元素，记录最大值和。但如果和为负数，则舍弃全部元素。证明最大和子序列就在这些序列中，由于如果和为负数会舍弃全部元素，所找的序列的左边外侧第一个值没有或为负数，内侧不小于 0。假设最大和序列不在其中，则代表最大和序列左边值应该大于 0。那么最大和序列应该包含这个值，矛盾。

```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve(int n) {
  int N, res = INT_MIN, sum = 0, begin = 1, end = 1, tmp_begin = 1;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int x;
    cin >> x;
    sum += x;
    if (res < sum) {
      res = sum;
      begin = tmp_begin;
      end = i;
    }
    if (sum < 0) {
      sum = 0;
      tmp_begin = i + 1;
    }
  }
  cout << "Case " << n << ":\n" << res << " " << begin << " " << end << "\n\n";
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) Solve(i);
}
```

<!-- TODO: #### 扩展：拟阵理论证明 -->

### 法二：动态规划
$dp[i] = max(k, dp[i - 1] + k)$ 。$dp[i]$ 为以第 $i$ 个元素为结尾的最大序列和。实际上和贪心一样。

```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve(int n) {
  int N, res = INT_MIN, begin, end;
  cin >> N;
  pair<int, int> prev{-1, 0}, dp;
  for (int i = 1; i <= N; ++i) {
    cin >> dp.first;
    dp.second = i;
    if (prev.first >= 0) {
      dp.first += prev.first;
      dp.second = prev.second;
    }
    if (res < dp.first) {
      res = dp.first;
      begin = dp.second;
      end = i;
    }
    prev = dp;
  }
  cout << "Case " << n << ":\n" << res << " " << begin << " " << end << "\n\n";
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) Solve(i);
}
```

### 法三：单调队列
用暴力法很容易想到使用前缀和来遍历所有可能的序列和，从中找到最大的一个。时间复杂度为 $O(n^2)$ 。有什么办法可以简化吗，我们注意到有 $O(n)$ 的时间复杂度是用来找 $i \sim n$ 中的最大前缀和了。$i$ 会不断右移，这就是滑动窗口，我们参考[滑动窗口](P1886_滑动窗口_单调队列.md)一题可以在 $O(1)$ 的复杂度得到当前窗口的最大值。这样时间复杂度将会被简化到 $O(n)$，空间复杂度 $O(n)$ 。

注意这道题只需要删头、去尾其中一个操作即可。这个解法的优点在于即使限定子序列大小也可以使用。本质为单调队列优化 DP 。

```cpp
#include <bits/stdc++.h>
using namespace std;

void Solve(int n) {
  int N;
  cin >> N;
  vector<int> arr(N + 1);
  deque<int> win;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
    while (!win.empty() && arr[win.back()] < arr[i]) win.pop_back();
    win.push_back(i);
  }

  int max = INT_MIN, begin, end;
  for (int i = 0; i < N; ++i) {
    if (max < arr[win.front()] - arr[i]) {
      max = arr[win.front()] - arr[i];
      begin = i + 1;
      end = win.front();
    }
    if (i + 1 >= win.front()) win.pop_front();
  }

  cout << "Case " << n << ":\n" << max << " " << begin << " " << end << "\n\n";
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) Solve(i);
}
```
