#include<bits/stdc++.h>
using namespace std;
int Min = INT_MAX;
void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int Min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[Min]){
                Min = j;
            }
        }
        swap(arr[Min],arr[i]);
    }
}

void greed(int arr[],int n,int k,int Bool[]){
    if(k==n){
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<k;i++){
            if(Bool[i]){
                sum1+=arr[i];
            }
            else{
                sum2+=arr[i];
            }
        }
        int temp = abs(sum1-sum2);
        if(Min>temp){
            Min = temp;
        }
    }
    else{
        Bool[k] = 1;
        greed(arr,n,k+1,Bool);
        Bool[k] = 0;
        greed(arr,n,k+1,Bool);
    }
}

int main(){
    int n = 7;
    // int arr[] = {2,25,47,16,14};
    int arr[] = {4,12,13,29,31,32,50};
    sort(arr,n);
    int Bool[n] = {0};
    greed(arr,n,0,Bool);
    cout<<Min<<" ";
    int sum1 = arr[0];
    int sum2 = 0;
    for(int i=1;i<n;i++){
        if(sum1>sum2){
            sum2+=arr[i];
        }
        else{
            sum1+=arr[i];
        }
    }
    cout<<abs(sum1-sum2);
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;


// int check(int x[], int k,int a[])
// {
//     int sum = 0; 
//     for (int i = 0; i < k-1; i++)
//     {
//         if(a[i] && a[i+1]){
//             return 0;
//         }
//         if(a[i]==1){
//             sum+=x[i];
//         }
//     }
//     return sum;
// }
// void genebinary(int x[],int k,int n,int a[],int& m){
    
//     if(k==n){
//         int temp = check(x,k,a);
//         m = max(temp,m);
//     }
//     else{
//         a[k] = 1;
//         genebinary(x,k+1,n,a,m);
//         a[k] = 0;
//         genebinary(x,k+1,n,a,m);
//     }
// }
// int main()
// {
//     int n = 10;
//     int arr[n] = {30,10,8,20,11,12,25,13,20,19};
//     int temp[n];
//     int Max = 0;
//     genebinary(arr, 0, n,temp,Max);
//     cout<<Max;
// }