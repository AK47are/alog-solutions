# [412. Fizz Buzz](https://leetcode.cn/problems/fizz-buzz/)

## 题解
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            bool is_divide3 = false, is_divide5 = false;
            if (i % 3 == 0) is_divide3 = true;
            if (i % 5 == 0) is_divide5 = true;
            if (is_divide3 && is_divide5)
                res.push_back("FizzBuzz");
            else if (is_divide3)
                res.push_back("Fizz");
            else if (is_divide5)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};
```
