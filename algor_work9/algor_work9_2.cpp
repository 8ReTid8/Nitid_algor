#include <bits/stdc++.h>
using namespace std;
void sort(int n,int arr[]){
    for(int i=0;i<n;i++){
        int Min = i;
        for(int j=i+1;j<n;j++){
            if(arr[Min]>arr[j]){
                Min = j;
            }
        }
        swap(arr[i],arr[Min]);
    }
}

float filemean(int arr[],int n){
    float Sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            Sum+=arr[j]; 
        }
    }
    return Sum/n;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(n,arr);
    float ans = filemean(arr,n);
    // cout<<ans;
    printf("%.2f",ans);
    return 0;
}6