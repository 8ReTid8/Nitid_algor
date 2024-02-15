#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    unordered_map<int ,int> counting;
    int b[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int Time = 0;
    int Max = 0;

    for(int i=0;i<n;i++){
        counting[a[i]]++;
        counting[b[i]]++;
        if(Max<counting[a[i]]){
            Max = counting[a[i]];
            Time = a[i];
        }
        if(Max<counting[b[i]]){
            Max = counting[b[i]];
            Time = b[i];
        }
    }

    // for(int i=0;i<n;i++){
    //     int MaxA = 0;
    //     int MaxB = 0;
    //     for(int j=0;j<n;j++){
    //         if(a[i]==a[j]||a[i]==b[j]){
    //             MaxA++;
    //         }
    //         if(b[i]==b[j]||b[i]==a[j]){
    //             MaxB++;
    //         }
    //     }
    //     if(Max < MaxA){
    //         Max = MaxA;
    //         Max_val = a[i];
    //     }
    //     if(Max < MaxB){
    //         Max = MaxB;
    //         Max_val = b[i];
    //     }
    // }
    cout<<Time<<" "<<Max<<endl;
}