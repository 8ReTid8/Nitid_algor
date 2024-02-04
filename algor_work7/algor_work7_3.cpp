#include <bits/stdc++.h>
using namespace std;

int lexicography(int *arr, int *nums, int n, int k, int c)
{
    if (c == k)
    {
        for (int i = 0; i < k; i++)
        {
            cout << nums[arr[i]] << " ";
        }
        cout << "\n";
        return 1;
    }
    else
    {
        int sum = 0;
        for (int i = (c == 0) ? 0 : arr[c - 1] + 1; i < n; i++)
        {
            arr[c] = i;
            sum += lexicography(arr, nums, n, k, c + 1);
        }
        return sum;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int nums[n];
    for (int i = 1; i <= n; i++)
    {
        nums[i - 1] = i;
    }

    cout << lexicography(new int[n], nums, n, k, 0);
    return 0;
}