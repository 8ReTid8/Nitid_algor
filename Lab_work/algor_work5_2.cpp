#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int m,int r){
    int i, j, k=l;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    i=0,j=0; //important
    while (i < n1 && j < n2){ 
        if(L[i] <= R[j]){ 
            arr[k] = L[i];
            i++;
        }
        else{ 
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) // copy left sub-array
    { 
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) // copy right sub-array
    { 
        arr[k] = R[j];
        j++;
        k++;
    }
 
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m = (l+(r-1))/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}


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
    // int a[] = {16,25,2,54,36,9,12,66};
    // int a[] = {4,3,8,2,1};
    int a[] = {4,3,2,1};
    int l = 0;
    int r = sizeof(a)/sizeof(a[0])-1;
    // Quicksort(a,l,r);
    mergesort(a,l,r);
    
    for(int i=0;i<r+1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}