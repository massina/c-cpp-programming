#include <iostream>
#include <vector>

using namespace std;

int fairRations(vector<int> &B)
{
    int sum = 0;
    int n = B.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        sum += B[i];
    }

    if(sum % 2 == 1){
        return -1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(B[i] % 2 == 1)
            {
                B[i] += 1;
                B[i + 1] += 1;
                count += 2;
            }
        }
    }
    
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int result = fairRations(numbers);
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << "\n";

    if (result > -1)
        cout << result << "\n";
    else
        cout << "No\n";
}