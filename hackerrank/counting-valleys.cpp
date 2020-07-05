#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s)
{
    int u = 0;
    int d = 0;
    int a = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D')
            d -= 1;
        else
            u += 1;

        if (a == 0)
            a = s[i] == 'D' ? -1 : 1;

        if (u + d == 0)
        {
            if (a == -1)
                count++;
            u = d = a = 0;
        }
    }

    return count;
}

int countValleysFast(int n, string s)
{
    int v = 0;
    int lvl = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
            lvl++;
        if (s[i] == 'D')
            lvl--;

        if (lvl == 0 && s[i] == 'U')
            v++;
    }

    return v;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int result = countingValleys(n, s);

    if (result > -1)
        cout << result << "\n";
    else
        cout << "No\n";
}