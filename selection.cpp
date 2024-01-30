#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 5;
    int arr[n] = {5,4,3,2,1};
    
    int temp = 0;
    for(int i=0;i<n-1;i++){
        int Min = i;
        for(int j=i+1;j<n;j++){
            if(arr[Min]>arr[j]){
                Min = j;
            }
            temp = arr[i];
            arr[i] = arr[Min];
            arr[Min] = temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}