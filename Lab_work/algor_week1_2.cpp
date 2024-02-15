#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int Max = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = max(arr[i],sum+arr[i]);
        Max = max(Max,sum);
    }
    cout<<Max;
    return 0;
}