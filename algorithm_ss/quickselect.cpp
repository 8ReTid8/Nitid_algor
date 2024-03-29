#include <bits/stdc++.h>
using namespace std;
int partition(int l,int r,int arr[]){
    int c = (l+r)/2;
    if(arr[l]>arr[c]){
        swap(arr[l],arr[c]);
    }
    if(arr[c]>arr[r]){
        swap(arr[c],arr[r]);
    }
    if(arr[l]>arr[r]){
        swap(arr[l],arr[r]);
    }
    // if(arr[l]>arr[c]){
    //     swap(arr[l],arr[c]);
    // }
    // swap(arr[c],arr[r]);

    int pivot = arr[r];
    int i = (l-1);
    for(int j=l;j<=r-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int quickselect(int low,int high,int k,int arr[],int& c){
    
    c++;
    if(low == high){
        return arr[low];
    }
    int p = partition(low,high,arr);
    if(k == p){
        return arr[p]; 
    }
    else if(k < p){
        
        return quickselect(low,p-1,k,arr,c);
    }
    else{
        // k = k - p + 1; 
        return quickselect(p+1,high,k,arr,c);
    }

}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count = 0;
   
    cout<<quickselect(0,n-1,k-1,arr,count)<<" "<<k;
    return 0;
}