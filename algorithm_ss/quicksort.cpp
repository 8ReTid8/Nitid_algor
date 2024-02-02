#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[],int l,int r){
    int p = arr[l];
    int i = l;
    int j = r+1;
    while(true){
        do{
            i+=1;
        }while(arr[i]<=p);
        do{
            j-=1;
        }while(arr[j]>p);
        if(i>=j){
            break;
        }
        swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}

void Quicksort(int arr[],int l,int r){
    if(l<r){
        int s = Partition(arr,l,r);
        Quicksort(arr,l,s-1);
        Quicksort(arr,s+1,r);
    }
}

int main(){
    int n = 5;
    int arr[] = {5,4,3,2,1};
    Quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}