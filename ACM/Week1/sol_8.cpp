// 洛谷题 B3616
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
};

class Queue {
 private:
  Node head_;
  Node* rear_ = &head_;
  int size_ = 0;

 public:
  void push(int data) {
    ++size_;
    rear_->next = new Node{data, nullptr};
    rear_ = rear_->next;
  }

  void pop() {
    if (size_ != 0) {
      --size_;
      Node* temp = head_.next->next;
      delete head_.next;
      head_.next = temp;
      if (size_ == 0) rear_ = &head_;
    } else {
      cout << "ERR_CANNOT_POP\n";
    }
  }

  int size() { return size_; }
  int query() const { return head_.next->data; }
};

int main() {
  int n, flag, temp;
  cin >> n;
  Queue q;
  for (int i = 0; i < n; ++i) {
    cin >> flag;
    switch (flag) {
      case 1:
        cin >> temp;
        q.push(temp);
        break;

      case 2:
        q.pop();
        break;

      case 3:
        if (q.size() != 0)
          cout << q.query() << "\n";
        else
          cout << "ERR_CANNOT_QUERY\n";
        break;

      case 4:
        cout << q.size() << "\n";
        break;
    }
  }
}
