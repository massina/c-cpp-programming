/*
Problem Description
Input Format. The first line contains an integer 𝑑. The second line contains an integer 𝑚. The third line
specifies an integer 𝑛. Finally, the last line contains integers stop1,stop2, . . . ,stop𝑛.
Output Format. Assuming that the distance between the cities is 𝑑 miles, a car can travel at most 𝑚 miles
on a full tank, and there are gas stations at distances stop1,stop2, . . . ,stop𝑛 along the way, output the
minimum number of refills needed. Assume that the car starts with a full tank. If it is not possible to
reach the destination, output −1.
Constraints. 1 ≤ 𝑑 ≤ 105
. 1 ≤ 𝑚 ≤ 400. 1 ≤ 𝑛 ≤ 300. 0 < stop1 < stop2 < · · · < stop𝑛 < 𝑑.
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    int numRefills = 0, currentRefill = 0, n = stops.size();

    while (currentRefill < n - 1)
    {
        int lastRefill = currentRefill;

        while (currentRefill < n && stops[currentRefill + 1] - stops[lastRefill] <= tank)
        {
            currentRefill += 1;
        }

        if (currentRefill == lastRefill)
        {
            return -1;
        }

        if (currentRefill < n - 1)
        {
            numRefills++;
        }
    }

    return numRefills;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 2);
    stops[0] = 0;
    stops[n + 1] = d;

    for (size_t i = 1; i < n + 1; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
