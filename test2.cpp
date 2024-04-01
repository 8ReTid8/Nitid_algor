#include <bits/stdc++.h>
using namespace std;
typedef struct{
    float v;
    float w;
    float mean;
}thing;

bool compare(thing a1,thing a2){
    if(a1.mean>a2.mean){
        return true;
    }
    return false;
}

float gay(int n,int k,thing arr[]){
    float tempW=0;
    float ans=0;
    for(int i=0;i<n;i++){
        tempW+=arr[i].w;
        if(tempW<k){
            ans+=arr[i].v;
        }
        else if(tempW==k){
            ans+=arr[i].v;
            return ans;
        }
        else{
            float g = (k-(tempW-arr[i].w))/arr[i].w;
            ans+=arr[i].v*g;
            return ans;
        }
    }
}
int main(){
    int n,target;
    cin>>n>>target;
    thing arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].w;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].v;
        arr[i].mean = arr[i].v/arr[i].w;
    }
    sort(arr,arr+n,compare);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].mean<<" ";
    // }
    cout<<gay(n,target,arr);
    return 0;
}