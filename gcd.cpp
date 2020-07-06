#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b)
{
  if (b == 0)
    return a;

  return gcd_fast(b, a % b);
}

void test_solution()
{
  assert(gcd_naive(80, 32) == 16);
  assert(gcd_fast(80, 32) == 16);

  while (true)
  {
    int a = rand() + 1 % 100000;
    int b = rand() + 1 % 100000;
    
    cout << "a: " << a << " b: " << b << endl;

    int res1 = gcd_naive(a, b);
    int res2 = gcd_fast(a, b);

    if (res1 != res2)
    {
      cout << "Wrong: " << res1 << " " << res2 << endl;
      return;
    }
    else
    {
      cout << "OK" << endl;
    }
  }
}

int main()
{
  int a, b;
  cin >> a >> b;
  // cout << gcd_naive(a, b) << " " << gcd_fast(a, b) << endl;
  // test_solution();
  cout << gcd_fast(a, b) << endl;
  return 0;
}
