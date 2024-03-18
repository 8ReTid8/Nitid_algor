#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> temp(100,vector<int>(100,-1));

int dynamic(int n,int k,int count,vector<vector<int>> arr){
    count += arr[n][k];
    if(n==0&&k==0){
        return count;
    }
    else if(n<0||k<0){
        return 0;
    }
    else if(temp[n][k]!=-1){
        return temp[n][k];
    }
    else{
        temp[n][k] = max(dynamic(n-1,k,count,arr),dynamic(n,k-1,count,arr));
        return temp[n][k];
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<dynamic(n-1,m-1,0,arr);
    return 0;
}