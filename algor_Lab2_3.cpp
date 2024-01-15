#include <bits/stdc++.h>
using namespace std;
vector<int> countsort(vector<int> arr)
{
    int n = arr.size();
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
    }
    vector<int> countarr(m + 1);
    for (int i = 0; i < n; i++)
    {
        countarr[arr[i]]++;
    }
    for (int i = 1; i < m + 1; i++)
    {
        countarr[i] += countarr[i - 1];
    }
    vector<int> sortarr(n);
    for (int i = 0; i < n; i++)
    {
        countarr[arr[i]]--;
        sortarr[countarr[arr[i]]] = arr[i];
    }
    return sortarr;
}

int binary_search(vector<int> a, int n, int k,int loop,int& count,int ans[])
{
    int l = 0, r = (n - 1);

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if ((a[mid] + a[loop] == k) && (abs(a[loop]-a[mid])<count) && mid!=loop){
            ans[0] = min(a[loop],a[mid]);
            ans[1] = max(a[loop],a[mid]);
            count = abs(a[loop]-a[mid]);
            return 0;
        }
        if (a[mid]+a[loop] < k){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int ans[2];
    int count = INT_MAX;
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr = countsort(arr);
   
    for(int i=0;i<n;i++){
        binary_search(arr,n,k,i,count,ans);
    }
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}