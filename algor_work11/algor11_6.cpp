#include <bits/stdc++.h>
using namespace std;
vector<int> temp(100,0);
int cross(int n,int k){
    if(n==0){
        return 1;
    }
    else if(n<0){
        return 0;
    }
    else if(temp[n]!=0){
        return temp[n];
    }
    else{
        for(int i=1;i<=k;i++){
            temp[n] += cross(n-i,k);
        }
        return temp[n];
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<cross(n,k);
    return 0;
}