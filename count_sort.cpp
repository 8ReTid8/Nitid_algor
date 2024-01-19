#include <bits/stdc++.h>
using namespace std;
vector<int> countsort(vector<int> arr){
    int n = arr.size();
    int m = 0;
    int Max=0,Min=0;
    for(int i=0;i<n;i++){
        Max = max(Max,arr[i]);
        Min = min(Min,arr[i]);
    }
    vector<int> countarr(Max-Min+1);
    for(int i=0;i<n;i++){
        countarr[arr[i]-Min]++;
    }
    for(int i=1;i<Max-Min+1;i++){
        countarr[i]+=countarr[i-1];
    }
    vector<int> sortarr(n);
    for(int i=0;i<n;i++){
        countarr[arr[i]-Min]--;
        sortarr[countarr[arr[i]-Min]] = arr[i];
    }
    return sortarr;
}
int main(){
    vector<int> arr = {1,5,3,4,2};
    arr = countsort(arr);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}