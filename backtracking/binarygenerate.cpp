#include <bits/stdc++.h>
using namespace std;

void binarygene(int arr[],int n,int k){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        arr[k] = 0;
        binarygene(arr,n,k+1);
        arr[k] = 1;
        binarygene(arr,n,k+1);
    }
}

int main(){
    int n = 4;
    int arr[n];
    binarygene(arr,n,0);
    return 0;
}