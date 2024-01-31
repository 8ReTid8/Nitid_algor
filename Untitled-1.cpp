#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr,int n,int k){
    int l = 0;
    int r = n-1;
    int m;
    while(l<=r){
        m = (l+r)/2;
        if(k==arr[m]){
            return m;
        }
        if(k>arr[m]){
            l = m+1;
        }
        if(k<arr[m]){
            r = m-1;
        }
    }
    return -1;
}
vector<int> sort(vector<int> arr,int n){
    int m = INT_MIN;
    for(int i=0;i<n;i++){
        m = max(m,arr[i]);
    }
    vector<int> count(m+1,0);
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<m+1;i++){
        count[i]+=count[i-1];
    }
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        count[arr[i]]--;
        temp[count[arr[i]]] = arr[i];
    }
    return temp;
}

int main(){
    vector<int> arr = {5,4,3,2,1};
    int n = 5;
    arr = sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<search(arr,n,3);
    return 0;
}