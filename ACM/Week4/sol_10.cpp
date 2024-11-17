#include <bits/stdc++.h>  // 值得回看 codeforce-Add Zeros

// 在一些大数据时map 的构建效率比 unordered_map
// 高很多，因为可能进行多次扩充操作。
using namespace std;
using ll = long long;

// 法二
void Dfs(set<ll>& all_len, map<ll, vector<ll>>& adj, ll now_len) {
  if (all_len.count(now_len)) return;
  all_len.insert(now_len);
  for (auto after_len : adj[now_len]) Dfs(all_len, adj, after_len);
}

void Solve() {
  int n;
  cin >> n;
  map<ll, vector<ll>> adj;
  for (int i = 0; i < n; ++i) {
    ll len = 0, var_len = 0;
    cin >> len;
    len += i;
    var_len += len + i;
    if (i != 0) adj[len].push_back(var_len);
  }
  set<ll> all_len;
  Dfs(all_len, adj, n);
  cout << *all_len.rbegin() << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}

// // 法一
// // 和法二差不多，区别仅在于使用 dp 来保证不会重叠遍历，不如法二简洁。dp
// 完全是多余的。 map<ll, ll> dp; map<ll, vector<ll>> arr;
//
// // 状态为当添加 i 个零时可添加的最大 0 的个数。
// // dp[i] = max(dp[zero_num + value]) value 为当前可添加的 0 的个数。
// // 使用记忆化搜索，因为可以添加 0 的个数范围非常大。
// ll Dfs(map<ll, vector<ll>>& arr, map<ll, ll>& dp, ll zero_num) {
//   if (dp[zero_num] != 0) return dp[zero_num];
//   ll res = zero_num;
//   for (auto value : arr[zero_num])
//     res = max(res, Dfs(arr, dp, zero_num + value));
//   dp[zero_num] = res;
//   return res;
// }
//
// void Solve() {
//   dp.clear(), arr.clear();
//
//   int size;
//   cin >> size;
//   ll temp;
//   cin >> temp;
//   for (int i = 1; i < size; ++i) {
//     cin >> temp;
//     if (temp >= size - i) arr[temp - (size - i)].push_back(i);
//   }
//   cout << Dfs(arr, dp, 0) + size << "\n";
// }
