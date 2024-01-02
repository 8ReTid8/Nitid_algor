#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[],int l,int r){
    int p = arr[l];
    int i = l;
    int j = r+1;
    do{
        do{
            i+=1;
        }while(arr[i]<p);
        do{
            j-=1;
        }while(arr[j]>p);
        swap(arr[i],arr[j]);
    }while(i<j);
    swap(arr[i],arr[j]);
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
    int a[] = {16,25,2,54,36,9,12,66};
    int l = 0;
    int r = sizeof(a)/sizeof(a[0])-1;
    Quicksort(a,l,r);
    for(int i=0;i<r+1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}