/*
Problem Description
Task. The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
Input Format. The first line of the input contains the number 𝑛 of items and the capacity 𝑊 of a knapsack.
The next 𝑛 lines define the values and weights of the items. The 𝑖-th line contains integers 𝑣𝑖 and 𝑤𝑖—the
value and the weight of 𝑖-th item, respectively.
Constraints. 1 ≤ 𝑛 ≤ 103
, 0 ≤ 𝑊 ≤ 2 · 106
; 0 ≤ 𝑣𝑖 ≤ 2 · 106
, 0 < 𝑤𝑖 ≤ 2 · 106
for all 1 ≤ 𝑖 ≤ 𝑛. All the
numbers are integers.
Output Format. Output the maximal value of fractions of items that fit into the knapsack. The absolute
value of the difference between the answer of your program and the optimal value should be at most
10−3
. To ensure this, output your answer with at least four digits after the decimal point (otherwise
your answer, while being computed correctly, can turn out to be wrong because of rounding issues).
*/

#include <iostream>
#include <vector>

using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<double> values)
{
  double value = 0.0;
  int n = weights.size();
  vector<int> A(n, 0);

  for (int i = 0; i < n; i++)
  {
    if (capacity == 0)
      return value;

    int max_index = 0;
    for (int i = 0; i < n; i++)
    {
      if (weights[i] > 0 && values[i] / weights[i] > values[max_index] / weights[max_index])
      {
        max_index = i;
      }
    }

    double a = min(capacity, weights[max_index]);
    value += a * ((double)values[max_index] / weights[max_index]);
    A[i] += a;
    capacity -= a;
    values[max_index] -= a * ((double)values[max_index] / weights[max_index]);
    weights[max_index] -= a;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
