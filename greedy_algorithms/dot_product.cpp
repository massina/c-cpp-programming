/*Problem Description
Task. Given two sequences 𝑎1, 𝑎2, . . . , 𝑎𝑛 (𝑎𝑖
is the profit per click of the 𝑖-th ad) and 𝑏1, 𝑏2, . . . , 𝑏𝑛 (𝑏𝑖
is
the average number of clicks per day of the 𝑖-th slot), we need to partition them into 𝑛 pairs (𝑎𝑖
, 𝑏𝑗 )
such that the sum of their products is maximized.
Input Format. The first line contains an integer 𝑛, the second one contains a sequence of integers
𝑎1, 𝑎2, . . . , 𝑎𝑛, the third one contains a sequence of integers 𝑏1, 𝑏2, . . . , 𝑏𝑛.
Constraints. 1 ≤ 𝑛 ≤ 103
; −105 ≤ 𝑎𝑖
, 𝑏𝑖 ≤ 105
for all 1 ≤ 𝑖 ≤ 𝑛.
Output Format. Output the maximum value of ∑︀𝑛
𝑖=1
𝑎𝑖𝑐𝑖
, where 𝑐1, 𝑐2, . . . , 𝑐𝑛 is a permutation of
𝑏1, 𝑏2, . . . , 𝑏𝑛.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long max_dot_product(vector<int> a, vector<int> b)
{
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long result = 0;

  for (size_t i = 0; i < a.size(); i++)
  {
    result += ((long long)a[i]) * b[i];
  }

  return result;
}

int main()
{
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  cout << max_dot_product(a, b) << endl;
}
