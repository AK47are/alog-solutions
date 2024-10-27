// 洛谷题 P1996
#include <iostream>
#include <numeric>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  iota(arr, arr + n, 1);
  int front = 0, rear = n - 1;
  while (front != rear) {  //  只剩一个元素时退出。
    for (int i = 0; i < m - 1; ++i) {
      ++rear, rear %= n;
      arr[rear] = arr[front];
      ++front, front %= n;
    }
    cout << arr[front] << " ";
    ++front, front %= n;
  }
  cout << arr[front] << "\n";
}
