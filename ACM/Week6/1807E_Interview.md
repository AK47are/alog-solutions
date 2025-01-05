---
title: Problem - 1807E - Codeforces
source: https://codeforces.com/problemset/problem/1807/E
tags:
  - 算法题/题型/前缀和
  - 算法题/题型/折半查找
---

## 题目描述
This is an interactive problem. If you are unsure how interactive problems work, then it is recommended to read [the guide for participants](https://codeforces.com/blog/entry/45307).

Before the last stage of the exam, the director conducted an interview. He gave Gon $n$ piles of stones, the $i$\-th pile having $a_{i}$ stones.

Each stone is identical and weighs $1$ grams, except for one special stone that is part of an unknown pile and weighs $2$ grams.

![](https://espresso.codeforces.com/d17afaaa97ad93724a78811029ac13481370ed62.png) A picture of the first test case. Pile $2$ has the special stone. The piles have weights of $1 , 3 , 3 , 4 , 5$, respectively.

Gon can only ask the director questions of one kind: he can choose $k$ piles, and the director will tell him the total weight of the piles chosen. More formally, Gon can choose an integer $k$ ($1 \leq k \leq n$) and $k$ unique piles $p_{1} , p_{2} , \ldots , p_{k}$ ($1 \leq p_{i} \leq n$), and the director will return the total weight $m_{p_{1}} + m_{p_{2}} + \hdots + m_{p_{k}}$, where $m_{i}$ denotes the weight of pile $i$.

Gon is tasked with finding the pile that contains the special stone. However, the director is busy. Help Gon find this pile in at most $30$ queries.

Input

The input data contains several test cases. The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot \left(10\right)^{5}$) — the number of piles.

The second line of each test case contains $n$ integers $a_{i}$ ($1 \leq a_{i} \leq \left(10\right)^{4}$) — the number of stones in each pile.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot \left(10\right)^{5}$.

After reading the input for each test case, proceed with the interaction as follows.

Interaction

You can perform the operation at most $30$ times to guess the pile.

To make a guess, print a line with the following format:

- $? \&\text{nbsp}; k \&\text{nbsp}; p_{1} \&\text{nbsp}; p_{2} \&\text{nbsp}; p_{3} \&\text{nbsp}; . . . \&\text{nbsp}; p_{k - 1} \&\text{nbsp}; p_{k}$ ($1 \leq k \leq n$; $1 \leq p_{i} \leq n$; all $p_{i}$ are distinct) — the indices of the piles.

After each operation, you should read a line containing a single integer $x$ — the sum of weights of the chosen piles. (Formally, $x = m_{p_{1}} + m_{p_{2}} + \hdots + m_{p_{k}}$.)

When you know the index of the pile with the special stone, print one line in the following format: $! \&\text{nbsp}; m$ ($1 \leq m \leq n$).

After that, move on to the next test case, or terminate the program if there are no more test cases remaining.

If your program performs more than $30$ operations for one test case or makes an invalid query, you may receive a Wrong Answer verdict.

After you print a query or the answer, please remember to output the end of the line and flush the output. Otherwise, you may get Idleness limit exceeded or some other verdict. To do this, use the following:

- fflush(stdout) or cout.flush() in C++;
- System.out.flush() in Java;
- flush(output) in Pascal;
- stdout.flush() in Python;
- see the documentation for other languages.

It is additionally recommended to read the [interactive problems guide for participants](https://codeforces.com/blog/entry/45307).

Hacks

To make a hack, use the following format.

The first line should contain a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case should contain two integers $n , m$ ($1 \leq n \leq 2 \cdot \left(10\right)^{5}$) – the number of piles and the pile with the special stone.

The second line of each test case should contain $n$ integers $a_{i}$ ($1 \leq a_{i} \leq \left(10\right)^{4}$) — the number of stones in each pile.

Note that the interactor is not adaptive, meaning that the answer is known before the participant asks the queries and doesn't depend on the queries asked by the participant.

Example

```
2
5
1 2 3 4 5

11

6

3

7
1 2 3 5 3 4 2

12

6
```

```
? 4 1 2 3 4

? 2 2 3

? 1 2

! 2

? 4 2 3 5 6

? 2 1 4

! 7
```

Note

In the first test case, the stone with weight two is located in pile $2$, as shown in the picture. We perform the following interaction:

- $?\mathtt{ 4 1 2 3 4}$ — ask the total weight of piles $1$, $2$, $3$, and $4$. The total weight we receive back is $1 + 3 + 3 + 4 = 11$.
- $?\mathtt{ 2 2 3}$ — ask the total weight of piles $2$ and $3$. The total weight we receive back is $3 + 3 = 6$.
- $?\mathtt{ 1 2}$ — ask the total weight of pile $2$. The total weight we receive back is $3$.
- $!\mathtt{ 2}$ — we have figured out that pile $2$ contains the special stone, so we output it and move on to the next test case.

In the second test case, the stone with weight two is located on index $7$. We perform the following interaction:

- $?\mathtt{ 4 2 3 5 6}$ — ask the total weight of piles $2$, $3$, $5$, and $6$. The total weight we receive back is $2 + 3 + 3 + 4 = 12$.
- $?\mathtt{ 2 1 4}$ — ask the total weight of piles $1$ and $4$. The total weight we receive back is $1 + 5 = 6$.
- $!\mathtt{ 7}$ — we have somehow figured out that pile $7$ contains the special stone, so we output it and end the interaction.

## 题解
我们知道每堆的石头数量，寻找哪个堆石头数量不等于对应重量。很显然使用折半。查询左半部分重量和，如果等于其石头数量，那么奇特石头在右半边。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool Check(ll low, ll high, vector<ll>& prefix) {
  cout << "? " << high - low + 1 << " ";
  for (ll i = low; i <= high; ++i) {
    cout << i << " ";
  }
  cout << "\n";
  fflush(stdout);
  ll x;
  cin >> x;
  return prefix[high + 1] - prefix[low] != x;
}

void Solve() {
  int n;
  cin >> n;
  vector<ll> prefix(n + 2);
  for (ll i = 2; i < n + 2; ++i) {
    cin >> prefix[i];
    prefix[i] += prefix[i - 1];
  }
  ll mid, high = n, low = 1;
  while (low < high) {
    mid = (high + low) / 2;
    if (Check(low, mid, prefix))
      high = mid;
    else
      low = mid + 1;
  }
  cout << "! " << low << "\n";
  fflush(stdout);
}

int main() {
  int t;
  cin >> t;
  while (t--) Solve();
}
```
