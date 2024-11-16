#include <bits/stdc++.h>  // 值得回看 codeforce-Add Zeros
// 数据测试非常丧心病狂，过的很极限。

#include <unordered_map>
using namespace std;
using ll = long long;
unordered_map<ll, ll> dp;
unordered_map<ll, vector<ll>> arr;

// 状态为当添加 i 个零时可添加的最大 0 的个数。
// dp[i] = max(dp[zero_num + value]) value 为当前可添加的 0 的个数。
// 使用记忆化搜索，因为可以添加 0 的个数范围非常大。
ll Dfs(unordered_map<ll, vector<ll>>& arr, unordered_map<ll, ll>& dp,
       ll zero_num) {
  if (dp[zero_num] != 0) return dp[zero_num];
  ll res = zero_num;
  for (auto value : arr[zero_num])
    res = max(res, Dfs(arr, dp, zero_num + value));
  dp[zero_num] = res;
  return res;
}

void Solve() {
  dp.clear(), arr.clear();

  int size;
  cin >> size;
  ll temp;
  cin >> temp;
  for (int i = 1; i < size; ++i) {
    cin >> temp;
    if (temp >= size - i) arr[temp - (size - i)].push_back(i);
  }
  cout << Dfs(arr, dp, 0) + size << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
