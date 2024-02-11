#include <bits/stdc++.h>
using namespace std;
int subsetsum(int arr[],int k,int n,int target,int Bool[],int sum){

    if(k==n){
        return 0;
    }
    if(sum>target){
        return 0;
    }
    if(sum==target){
        for(int i=0;i<k;i++){
            if(Bool[i]==1){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
    Bool[k] = 0;
    sum+=arr[k];
    subsetsum(arr,k+1,n,target,Bool,sum);

    Bool[k] = 1;
    sum-=arr[k];
    subsetsum(arr,k+1,n,target,Bool,sum);
    return 0;
}
int main(){
    int n = 5;
    int arr[] = {25,9,10,2,3};
    int target = 12;
    int Bool[n];
    subsetsum(arr,0,n,target,Bool,0);
    return 0;
}

