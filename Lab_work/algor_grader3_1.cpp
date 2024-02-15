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
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            count++;
        }
    }
    if(count==0){
        count = -1;
    }
    cout<<count;
}