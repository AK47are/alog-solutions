// 洛谷题 B2121
#include <iostream>
#include <string>

using namespace std;

int main() {
  string max, min, temp;
  for (char c = cin.get(); !cin.eof(); c = cin.get()) {
    if (isalpha(c))
      temp.push_back(c);
    else {
      if (max.size() < temp.size()) max = temp;
      if (!min.size() || (temp.size() != 0 && min.size() > temp.size()))
        min = temp;
      temp.clear();
    }
  }
  if (max.size() < temp.size()) max = temp;
  if (!min.size() || (temp.size() != 0 && min.size() > temp.size())) min = temp;
  cout << max << "\n" << min << "\n";
}
