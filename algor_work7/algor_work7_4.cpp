#include <bits/stdc++.h>
using namespace std;

int subset(int Bool[], int nums[], int n, int k)
{
    if (k == n)
    {
        bool Zero = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (Bool[i] == 1)
            {
                cout << nums[i];
                Zero = false;
            }
        }

        if (Zero)
        {
            cout << "0";
        }

        cout << "\n";
        return 1;
    }
    else
    {
        int sum = 0;
        Bool[k] = 0;
        sum += subset(Bool, nums, n, k + 1);
        Bool[k] = 1;
        sum += subset(Bool, nums, n, k + 1);

        return sum;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n],Bool[n];
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = (n+1) - i;
    }
    cout<<subset(Bool, arr, n, 0);
    return 0;
}