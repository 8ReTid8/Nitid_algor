#include <bits/stdc++.h>
using namespace std;
void wow(int x[], int k)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
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

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    permui(arr,0,n);
    return 0;
}