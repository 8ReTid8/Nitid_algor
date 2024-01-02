#include <bits/stdc++.h>
using namespace std;

void UNcheck(int &n,int start,int U[],int value){
    bool check = true;
    for(int i=start;i<n;i++){
        if(value == U[i]){
            check = false;
        }
    }
    if(check){
        U[n] = value;
        n++;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int Intersect[n];
    int Union[n+n];
    int countUn = 0;
    int countInter = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        UNcheck(countUn,0,Union,a[i]);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    int oldcountUn = countUn;
    for(int i=0;i<n;i++){
        bool tempUn = true;
        bool tempInter = false;
        for(int j=0;j<n;j++){
            if(b[i]==Union[j]){
                tempUn = false;
            }
            if(a[i]==b[j]){
                tempInter = true;
            }
        }
        if(tempUn){
            UNcheck(countUn,oldcountUn,Union,b[i]);
        }
        if(tempInter){
            UNcheck(countInter,0,Intersect,a[i]);
        }
    }

    for(int i=0;i<countInter;i++){
        cout<<Intersect[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<countUn;i++){
        cout<<Union[i]<<" ";
    }
    return 0;
}