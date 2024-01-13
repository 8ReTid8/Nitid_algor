#include <bits/stdc++.h>
using namespace std;
vector<int> countsort(vector<int> arr){
    int n = arr.size();
    int m = 0;
    for(int i=0;i<n;i++){
        m = max(m,arr[i]);
    }
    vector<int> countarr(m+1);
    for(int i=0;i<n;i++){
        countarr[arr[i]]++;
    }
    for(int i=1;i<m+1;i++){
        countarr[i]+=countarr[i-1];
    }
    vector<int> sortarr(n);
    for(int i=0;i<n;i++){
        countarr[arr[i]]--;
        sortarr[countarr[arr[i]]] = arr[i];
    }
    return sortarr;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr = countsort(arr);
    return 0;
}