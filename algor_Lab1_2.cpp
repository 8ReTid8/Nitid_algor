#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int Max = 0;
    int Min = INT_MAX;

    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                count++;
            }
        }
        if(Max<count){
            Max = count;
        }
        if(Min>count){
            Min = count;
        }
    }
    cout<<Max-Min;
}