#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n],B[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }

    int mA = INT_MIN;
    int mB = INT_MIN;
    for(int i=0;i<n;i++){
        mA = max(mA,A[i]);
        mB = max(mB,B[i]);
    }

    int countA[mA+1];
    int countB[mB+1];

    for(int i=0;i<n;i++){
        countA[A[i]]=1;
        countB[B[i]]=1;
    }

    
    for(int i=0;i<n;i++){
        if(countA[A[i]]==1&&countB[A[i]]==1){
            cout<<A[i]<<" ";
        }
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        if(countA[A[i]]==1){
            cout<<A[i]<<" ";
            countA[A[i]]=0;
            countB[A[i]]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(countB[B[i]]==1){
            cout<<B[i]<<" ";      
            countB[B[i]]=0;
        }
    }

    return 0;
}