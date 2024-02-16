#include <bits/stdc++.h>
using namespace std;
void printsub(int arr[],int k){
    for(int i=1;i<=k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void subset(int arr[],int k,int n){
    printsub(arr,k);
    int j;
    if(k==0){
        j=1;
    }
    else{
        j=arr[k]+1;
    }
    for(int i=j;i<=n;i++){
        arr[k+1] = i;
        subset(arr,k+1,n);
    }
}

int main(){
    int n = 3;
    int arr[n+1];
    subset(arr,0,n);
    return 0;
}