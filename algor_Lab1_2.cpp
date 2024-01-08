#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    unordered_map<int ,int> counting;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int Max = 0;
    int Min = INT_MAX;
    for(int i=0;i<n;i++){
        counting[a[i]]++;
        
    }
    for(int i=0;i<n;i++){

        if(Max<counting[i]){
            Max = counting[i];
        }
        if(Min>counting[i]&&counting[i]!=0){
            Min = counting[i];
        }
    }

    // for(int i=0;i<n;i++){
    //     int count = 0;
    //     for(int j=0;j<n;j++){
    //         if(a[i]==a[j]){
    //             count++;
    //         }
    //     }
    //     if(Max<count){
    //         Max = count;
    //     }
    //     if(Min>count){
    //         Min = count;
    //     }
    // }
    cout<<Max<<" "<<Min<<endl;
    cout<<Max-Min;
}