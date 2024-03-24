#include <bits/stdc++.h>
using namespace std;
vector<double> temp(100,-1);
double findmean(int n,double arr[]){
    // if(index==0){
    //     return arr[index]/n;
    // }
    // else{
    //     return (arr[index]/n)+findmean(n,arr,index-1);
    // }
    if(n==0){
        temp[n] = arr[n];
        return temp[n];
    }
    else {
        temp[n] = (n*findmean(n-1,arr)+arr[n])/(n+1);
        return temp[n];
    }
}
int main(){
    int n;
    cin>>n;
    double arr[n];
    for(int i=0;i<n;i++){   
        cin>>arr[i];                   
    }
    cout<<findmean(n-1,arr);
    return 0;
}