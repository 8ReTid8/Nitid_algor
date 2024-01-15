#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=0;i<n-1;i++){
        m = max(arr[i][1],arr[i+1][1]);
    }
    vector<int> counting(m+1);
    for(int i=0;i<n;i++){
        for(int j=arr[i][0];j<=arr[i][1];j++){
            counting[j]++;
        }
    }
    for(int i=0;i<m+1;i++){
        
    }
    return 0;
}