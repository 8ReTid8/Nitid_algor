#include <bits/stdc++.h>
using namespace std;
void queen(int k, int n, int x[], int &count, int Bool[])
{
    if (k == n)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(x[i] - x[j]) == abs(j - i) || x[j] == x[i])
                {
                    return;
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int row = 0; row < n; row++)
        {
            if (Bool[row] == 0)
            {
                Bool[row] = 1;
                x[k] = row;
                queen(k + 1, n, x, count, Bool);
                Bool[row] = 0;
            }
        }
    }
}

int main()
{
    int count = 0;
    int n = 4;
    int arr[4];
    int Bool[4] = {0};
    queen(0, n, arr, count, Bool);
}