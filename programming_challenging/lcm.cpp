#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}

int gcd_fast(int a, int b)
{
  if (b == 0)
    return a;

  return gcd_fast(b, a % b);
}

long long lcm_recursive(int a, int b)
{
  return ((long long)a * b) / gcd_fast(a, b);
}

long long lcm_fast(int a, int b)
{
  long long d;

  if (a > b)
    d = a;
  else
    d = b;

  while (true)
  {
    if (d % a == 0 && d % b == 0)
      return d;
    d++;
  }
}

void test_solution()
{
  assert(lcm_naive(6, 8) == 24);
  assert(lcm_fast(6, 8) == 24);

  while (true)
  {
    int a = rand() + 1 % 100000;
    int b = rand() + 1 % 100000;

    cout << "a: " << a << " b: " << b << endl;

    int res1 = lcm_naive(a, b);
    int res2 = lcm_recursive(a, b);

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
  cout << lcm_naive(a, b) << endl;
  test_solution();
  cout << lcm_recursive(a, b) << endl;
  return 0;
}
