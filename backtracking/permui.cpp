#include <bits/stdc++.h>
using namespace std;

void permute(int arr[],int k,int n){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=k;i<n;i++){
            swap(arr[k],arr[i]);
            permute(arr,k+1,n);
            swap(arr[k],arr[i]);
        }
    }
}
int main(){
    int n = 3;
    int arr[] = {1,2,3};
    permute(arr,0,n);
    return 0;
}