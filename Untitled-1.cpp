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
    string str[] = {"11","22","33"};
    vector<int> arr(3);
    for(int i=0;i<3;i++){
        int sum = 0;
        for(int j=0;j<str[i].length();j++){
            sum += str[i][j]-'0';
        }
        arr[i] = sum;
    }
    
    arr = countsort(arr);
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
}