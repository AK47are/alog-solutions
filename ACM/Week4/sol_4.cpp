// 洛谷-P1036
#include <cmath>
#include <iostream>
using namespace std;
int count = 0;

bool IsPrime(int n) {
  int s = sqrt(double(n));
  for (int i = 2; i <= s; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void Solve(int arr[], int n, int sum, int k) {
  if (n < k) return;
  if (k == 0) {
    if (IsPrime(sum)) ++count;
    return;
  }
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    Solve(arr + i + 1, n - i - 1, sum, k - 1);
    sum -= arr[i];
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (auto& value : arr) cin >> value;
  Solve(arr, n, 0, k);
  cout << count << "\n";
}
