#include <iostream>

// Task. The goal in this problem is to find the minimum number of coins needed to change the input value
// (an integer) into coins with denominations 1, 5, and 10.
int get_change(int m) {
  int coins = 0, remainder = m;

  if(remainder >= 10)
  {
    coins += remainder / 10;
    remainder %= 10;
  }

  if(remainder >= 5)
  {
    coins += remainder / 5;
    remainder %= 5;
  }

  return coins + remainder;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
