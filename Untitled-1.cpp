#include <bits/stdc++.h>
using namespace std;
int check(int w[],int v[],int k,int Bool[])
{
    int sum = 0;
    int sumval = 0;
    for(int i=0;i<k;i++){
        if(Bool[i]==1){
            sum+=w[i];
            sumval+=v[i];
        }
    }
    cout<<sum<<" "<<sumval<<endl;
    if(sum>18){
        return 0;
    }
    else{
        return sumval;
    }
}

void binary(int w[],int v[],int k,int n,int Bool[],int& Max){
    
    if(k==n){
        int temp = check(w,v,k,Bool);
        Max = max(temp,Max);

    }
    else{
        Bool[k] = 1;
        binary(w,v,k+1,n,Bool,Max);
        Bool[k] = 0;
        binary(w,v,k+1,n,Bool,Max);
    }
}


int main(){
    int n;
    cin>>n;
    int w[n],v[n],Bool[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int Max = INT_MIN;
    binary(w,v,0,n,Bool,Max);
    cout<<Max;
    return 0;
}