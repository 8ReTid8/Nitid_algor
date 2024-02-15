#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m = INT_MIN;
    for(int i=0;i<n;i++){
        m = max(m,arr[i]);
    }
    vector<int> counting(m+1,0);
    for(int i=0;i<n;i++){
        counting[arr[i]] = 1;
    }
    int sum = 0;
    for(int i=0;i<m+1;i++){
        sum+=counting[i];
    }
    cout<<sum;
    return 0;
}