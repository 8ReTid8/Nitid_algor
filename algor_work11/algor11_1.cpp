#include <bits/stdc++.h>
using namespace std;
int dynamic(int n,int k,int arr[],int count){
    if(n==0){
        return count;
    }
    else if(k==0){
        return count;
    }
    else if(k<0){
        return 0;
    }
    else{
        return max(dynamic(n-1,k,arr,count),dynamic(n-1,k-arr[n-1],arr,count+1));
    }
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin>>k;
    cout<<dynamic(n,k,arr,0);
}