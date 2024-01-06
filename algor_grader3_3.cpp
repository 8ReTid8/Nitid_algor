#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(i==k){
            cout<<arr[i]<<" "<<i;
            break;
        }
    }
    return 0;
}