// #include <bits/stdc++.h>
// using namespace std;
// int subsetsum(int arr[], int k, int n, int target, int Bool[], int sum)
// {
//     if (k == n)
//     {
//         return 0;
//     }
//     if (sum > target)
//     {
//         return 0;
//     }
//     if (sum == target)
//     {
//         for (int i = 0; i < k; i++)
//         {
//             if (Bool[i] == 1)
//             {
//                 cout << arr[i] << " ";
//             }
//         }
//         cout << endl;
//     }

//     Bool[k] = 0;
//     subsetsum(arr, k + 1, n, target, Bool, sum);

//     Bool[k] = 0;
//     subsetsum(arr, k + 1, n, target, Bool, sum);
//     return 0;
// }
// int main()
// {
//     int n = 5;
//     // int arr[] = {25,9,10,2,3};
//     int arr[] = {1, 2, 3, 4, 5};
//     int target = 12;
//     int Bool[n] = {1};
//     subsetsum(arr, 0, n, target, Bool, 0);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void subsetsum(int Bool[], int nums[], int n, int k,int target, int sum)
{
    if (k == n)
    {
        if (sum == target)
        {
            for (int i = 0; i < n; i++)
            {
                if (Bool[i] != 0)
                    cout << Bool[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    if (sum + nums[k] <= target)
    {
        Bool[k] = nums[k];
        subsetsum(Bool, nums, n, k + 1, target, sum + nums[k]);
        Bool[k] = 0;
        subsetsum(Bool, nums, n, k + 1, target, sum);
    }
}

int main()
{
    int n, t;
    cin >> n >> t;
    int arr[n];
    int Bool[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    subsetsum(Bool, arr, n, 0, t, 0);
    return 0;
}