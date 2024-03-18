#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> temp(100,vector<int>(100,-1));
int dynamic(int n,int k,int count){
    if(n==1&&k==1){
        return count;
    }
    else if(n==0||k==0){
        return 0;
    }
    else if(temp[n][k]!=-1){
        return temp[n][k];
    }
    else{
        temp[n][k] = max(dynamic(n-1,k,count+1),dynamic(n,k-1,count+1));
        return temp[n][k];
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    // n = 1||0;
    // cout<<n;
    cout<<dynamic(n,k,0);
    return 0;
}