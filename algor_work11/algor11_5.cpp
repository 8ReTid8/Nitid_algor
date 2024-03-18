#include <bits/stdc++.h>
using namespace std;
vector<int> temp(100,-1);
int dynamic(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 1;
    }
    else if(temp[n]!=-1){
        return temp[n];
    }
    else{
        temp[n] = (dynamic(n-1)*3)+dynamic(n-2);
        return temp[n];
    }
}
int main(){
    int n;
    cin>>n;
    cout<<dynamic(n);
    return 0;
}