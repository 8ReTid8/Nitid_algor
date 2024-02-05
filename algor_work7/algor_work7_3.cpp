#include <bits/stdc++.h>
using namespace std;

int number = 0;

void permute(int x[], int k, int n, int round, int Bool[])
{
    if (k == n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (Bool[i] == 1)
            {
                count++;
            }
        }
        if (count == round)
        {
            for (int i = 0; i < n; i++)
            {
                if (Bool[i] == 1)
                {
                    cout << x[i] << " ";
                }
            }
            cout << endl;
            number++;
        }
        return;
    }

    Bool[k] = 1;
    permute(x, k + 1, n, round, Bool);
    Bool[k] = 0;
    permute(x, k + 1, n, round, Bool);
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int x[n];
    int Bool[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = i + 1;
    }

    permute(x, 0, n, k, Bool);
    cout << number << endl;
    return 0;
}