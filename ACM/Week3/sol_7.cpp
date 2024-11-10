// 洛谷-P8647
#include <iostream>
#include <vector>
using namespace std;
vector<int> hv, wv;

int main() {
  int N, K, h, w;
  cin >> N >> K;
  while (N--) {
    cin >> h >> w;
    hv.push_back(h);
    wv.push_back(w);
  }

  int low = 1, high = 1e5;
  while (low != high) {
    int mid = (low + high + 1) / 2, sum = 0;
    for (int i = 0; i < hv.size(); ++i) {
      sum += (hv[i] / mid) * (wv[i] / mid);
    }
    if (sum < K)
      high = mid - 1;
    else
      low = mid;
  }
  cout << low << "\n";
}
