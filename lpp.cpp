#include <bits/stdc++.h>
using namespace std;

void back(int n, int k, int tar, int arr[], int count)
{
    if (k == n)
    {
        if (count == tar)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    else if (count <= tar)
    {
        arr[k] = 0;
        back(n, k + 1, tar, arr, count);
        arr[k] = 1;
        back(n, k + 1, tar, arr, count + 1);
    }
}

int main()
{
    int n = 4;
    int tar = 2;
    int arr[n] = {0};
    back(n, 0, tar, arr, 0);
}