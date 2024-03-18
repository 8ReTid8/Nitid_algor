#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> temp(100,vector<int>(100,-1));
int dynamic(int n,int k){
    if(k==0){
        return 1;
    }
    else if(n==k){
        return 1;
    }
    else if(temp[n][k]!=-1){
        return temp[n][k];
    }
    else{
        temp[n][k] = dynamic(n-1,k-1)+dynamic(n-1,k);
        return temp[n][k];
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<dynamic(n,k);
    return 0;
}