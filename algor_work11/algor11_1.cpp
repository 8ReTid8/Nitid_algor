#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> temp(100,vector<int>(100,-1));
int dynamic(int n,int k,int arr[],int count){
    if(n==0&&k>0){
        return -999;
    }
    else if(k==0){
        return 0;
    }
    else if(k<0){
        return -999;
    }
    else if(temp[n][k]!=-1){
        return temp[n][k];
    }
    else{
        temp[n][k] = max(dynamic(n-1,k,arr,count),1+dynamic(n-1,k-arr[n-1],arr,count+1));
        return temp[n][k];
        // return max(dynamic(n-1,k,arr,count),dynamic(n-1,k-arr[n-1],arr,count+1));
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