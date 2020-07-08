/*
Problem Description
Task. The goal in this problem is to find the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.
Input Format. The input consists of a single integer 𝑚.
Constraints. 1 ≤ 𝑚 ≤ 103
.
Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.
*/

#include <iostream>

int get_change(int m)
{
  int coins = 0;

  if (m >= 10)
  {
    coins += m / 10;
    m %= 10;
  }

  if (m >= 5)
  {
    coins += m / 5;
    m %= 5;
  }

  return coins + m;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
