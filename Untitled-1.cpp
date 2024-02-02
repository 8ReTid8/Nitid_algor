#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum = 0;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        sum = max(arr[i],sum+arr[i]);
        ans = max(sum,ans);
    }
    cout<<ans;
    return 0;
}