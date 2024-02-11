#include <bits/stdc++.h>

using namespace std;

int genebinary(int x[], int k, int n, int a[], int &m, int sum)
{
    if (k == n)
    {
        return 0;
    }
    // if (sum < m)
    // {
    //     return 0;
    // }
    if (sum > m)
    {
        for (int i = 0; i < k-1; i++)
        {
            if (a[i] && a[i + 1])
            {
                return 0;
            }
        }
        m = sum;
    }
    cout << sum << endl;
    a[k] = 1;
    sum += x[k];
    genebinary(x, k + 1, n, a, m, sum);

    a[k] = 0;
    sum -= x[k];
    genebinary(x, k + 1, n, a, m, sum);
    return sum;
}
int main()
{
    int n = 10;
    int arr[n] = {30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
    int temp[n];
    int Max = 0;
    int Sum = 0;
    genebinary(arr, 0, n, temp, Max, Sum);
    cout << Max;
}