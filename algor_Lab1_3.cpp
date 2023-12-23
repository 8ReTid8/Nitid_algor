#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int Max = 0;
    int Max_val = 0;
   

    for(int i=0;i<n;i++){
        int MaxA = 0;
        int MaxB = 0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]||a[i]==b[j]){
                MaxA++;
            }
            if(b[i]==b[j]||b[i]==a[j]){
                MaxB++;
            }
        }
        if(Max < MaxA){
            Max = MaxA;
            Max_val = a[i];
        }
        if(Max < MaxB){
            Max = MaxB;
            Max_val = b[i];
        }
    }
    cout<<Max_val<<" "<<Max<<endl;
}