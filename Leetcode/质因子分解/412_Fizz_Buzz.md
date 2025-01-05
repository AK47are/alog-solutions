---
title: 412. Fizz Buz - 力扣（LeetCode）
source: https://leetcode.cn/problems/fizz-buzz/
tags:
  - 算法题/题型/数论/质因子分解
---

## 题目描述
给你一个整数 `n` ，找出从 `1` 到 `n` 各个整数的 Fizz Buzz 表示，并用字符串数组 `answer`（下标从 1 开始）返回结果，其中：

`answer[i] == "FizzBuzz"` 如果 `i` 同时是 `3` 和 `5` 的倍数。
`answer[i] == "Fizz"` 如果 `i` 是 `3` 的倍数。
`answer[i] == "Buzz"` 如果 `i` 是 `5` 的倍数。
`answer[i] == i` （以字符串形式）如果上述条件全不满足。
 

示例 1：

输入：n = 3
输出：["1","2","Fizz"]
示例 2：

输入：n = 5
输出：["1","2","Fizz","4","Buzz"]
示例 3：

输入：n = 15
输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 

提示：

1 <= n <= 10

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
