#include <bits/stdc++.h>

using namespace std;

void wow(int x[], int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
int check(int x[], int k,int a[])
{
    int sum = 0; 
    for (int i = 0; i < k-1; i++)
    {
        if(a[i] && a[i+1]){
            return 0;
        }
        if(a[i]==1){
            sum+=x[i];
        }
    }
    return sum;
}

void sub(int x[], int k, int n)
{
    wow(x, k);
    int j = (k == 0) ? 1 : x[k] + 1;
    for (int i = j; i <= n; i++)
    {
        x[k + 1] = i;
        sub(x, k + 1, n);
    }
}
void permui(int x[], int k, int n)
{
    if (k == n)
    {
        wow(x, k);
    }
    else
    {
        for (int i = k ; i < n; i++)
        {
            // x[k] = x[i];
            swap(x[k],x[i]);
            permui(x, k + 1, n);
            swap(x[i],x[k]);
            // x[i] = x[k];
        }
    }
}

void no5(int x[],int k,int n,int a[],int& m){
    
    if(k==n){
        int find = check(x,k,a);
        m = max(find,m);
    }
    else{
        a[k] = 1;
        no5(x,k+1,n,a,m);
        a[k] = 0;
        no5(x,k+1,n,a,m);
    }
}
int main()
{
    // int arr[] = {30,10,8,20,11,12,25,13,20,19};
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    int Max = 0;
    // no5(arr, 0, n,temp,Max);
    sub(arr, 0, n);
    // cout<<Max;
}

