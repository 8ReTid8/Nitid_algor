#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m=0;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=0;i<n;i++){
        m = max(m,arr[i][1]);
    }
    vector<int> counting(m+1);
    int Max = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=arr[i][0];j<=arr[i][1];j++){
            counting[j]++;
            Max = max(Max,counting[j]);
        }
    }
    
    int come = INT_MAX;
    int out = INT_MIN;
    for(int i=0;i<m+1;i++){
        if(counting[i]==Max){
            come = min(come,i);
            out = max(out,i);
        }
    }
    cout<<come<<" "<<out<<" "<<Max;
    return 0;
}