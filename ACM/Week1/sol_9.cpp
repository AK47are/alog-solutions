// 洛谷题 P3378
#include <iostream>
const int MAX = 1e6;
using namespace std;

// 小顶堆。
class Heap {
 private:
  int arr_[MAX];
  int size_ = 0;

 public:
  int left(int i) { return i * 2 + 1; }
  int right(int i) { return i * 2 + 2; }
  int parent(int i) { return (i - 1) / 2; }

  void swap(int& w1, int& w2) {
    int temp = w1;
    w1 = w2;
    w2 = temp;
  }

  void heapify_up(int n) {
    for (auto i = n; i > 0; i = parent(i)) {
      if (arr_[parent(i)] > arr_[i])
        swap(arr_[parent(i)], arr_[i]);
      else
        break;
    }
  }

  void heapify_down(int i) {
    while (true) {
      int l = left(i), r = right(i), min = i;
      if (l < size_ && arr_[l] < arr_[min]) min = l;
      if (r < size_ && arr_[r] < arr_[min]) min = r;
      if (min == i) break;
      swap(arr_[i], arr_[min]);
      i = min;
    }
  }

  void push(int temp) {
    arr_[size_] = temp;
    ++size_;
    heapify_up(size_ - 1);
  }

  void pop() {
    if (size_ == 0) return;
    swap(arr_[0], arr_[size_ - 1]);
    --size_;
    heapify_down(0);
  }

  int top() { return arr_[0]; }
};

int main() {
  int n, flag, temp;
  Heap h;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> flag;
    switch (flag) {
      case 1:
        cin >> temp;
        h.push(temp);
        break;

      case 2:
        cout << h.top() << "\n";
        break;

      case 3:
        h.pop();
    }
  }
}
