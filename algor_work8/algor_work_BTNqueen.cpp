#include <bits/stdc++.h>
using namespace std;
int nqueen(int x[],int k,int n){
    if(k==n){
        for(int i=0;i<k;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n = 4;
    int arr[n];
    nqueen(arr,0,n);
    return 0;
}