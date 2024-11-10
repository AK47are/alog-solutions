// 洛谷-P1102
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  long long N, C;
  cin >> N >> C;
  unordered_map<long long, int> nums;
  vector<long long> arr;
  arr.resize(N);
  for (auto& value : arr) {
    cin >> value;
    ++nums[value];
  }

  long long count = 0;
  for (auto value : arr) count += nums[value - C];
  cout << count << "\n";
}
