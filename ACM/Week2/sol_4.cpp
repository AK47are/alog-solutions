// 洛谷-P8072
#include <iostream>
using namespace std;

int main() {
  unsigned K, left_bit = 31, right_bit = 0;
  cin >> K;
  while (!((1 << left_bit) & K)) --left_bit;
  while (!((1 << right_bit) & K)) ++right_bit;
  if ((1 << left_bit) != K) ++left_bit;
  cout << (1 << left_bit) << " " << left_bit - right_bit << "\n";
}
