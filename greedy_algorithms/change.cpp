#include <iostream>

int get_change(int m) {
  int change = 0, remainder = m;

  if(remainder >= 10)
  {
    change += remainder / 10;
    remainder %= 10;
  }

  if(remainder >= 5)
  {
    change += remainder / 5;
    remainder %= 5;
  }

  if(remainder >= 1)
  {
    change += remainder / 1;
    remainder %= 1;
  }

  return change;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
