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
    vector<int> arr = {1,5,3,4,2};
    // int arr[] = {1,5,3,4,2};
    arr = countsort(arr);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}