#include<bits/stdc++.h>
using namespace std;

// int Min = INT_MAX;
// void sort(int arr[],int n){
//     for(int i=0;i<n;i++){
//         int Min = i;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]>arr[Min]){
//                 Min = j;
//             }
//         }
//         swap(arr[Min],arr[i]);
//     }
// }

// void greed(int arr[],int n,int k,int Bool[]){
//     if(k==n){
//         int sum1 = 0;
//         int sum2 = 0;
//         for(int i=0;i<k;i++){
//             if(Bool[i]){
//                 sum1+=arr[i];
//             }
//             else{
//                 sum2+=arr[i];
//             }
//         }
//         int temp = abs(sum1-sum2);
//         if(Min>temp){
//             Min = temp;
//         }
//     }
//     else{
//         Bool[k] = 1;
//         greed(arr,n,k+1,Bool);
//         Bool[k] = 0;
//         greed(arr,n,k+1,Bool);
//     }
// }

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

int c=0;
void DFS(int i,int arr[][10],int visit[],int n){
    
    // cout<<i<<" ";
    if(i==7){
        c++;
        return;
    }
    visit[i] = 1;
    for(int j=0;j<n;j++){
        if(visit[j]==0&&arr[i][j]==1){
            DFS(j,arr,visit,n);
        }
    }
    visit[i]=0;
}
int main(){
    int n;
    cout<<"input n of V: ";
    cin>>n;
    int arr[n][10];
    cout<<"input adjency matrix graph :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int visit[n];
    for(int i=0;i<n;i++){
        visit[i] = 0;
    }
    DFS(0,arr,visit,n);
    cout<<c;
    return 0;
}