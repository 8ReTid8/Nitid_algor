#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    float start;
    float end;
    float diff;
}train;

bool compare(train a1,train a2){
    if(a1.start<a2.start){
        return true;
    }
    return false;
}

int count(int n,train arr[]){
    vector<float> temp(n,0);
    int cou;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i].start>=temp[j]){
                temp[j] = arr[i].end;
                cou = j+1;
                break;
            }
        }
        ans=max(ans,cou);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    train arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
        arr[i].diff = arr[i].end-arr[i].start;
    }
    sort(arr,arr+n,compare);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].diff<<" ";
    // }
    cout<<count(n,arr);
    return 0;
}