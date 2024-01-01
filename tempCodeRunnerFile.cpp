#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int Intersect[n];
    int Union[n+n];
    int countUn = 0;
    for(int i=0;i<n;i++){
        bool temp = true;
        cin>>a[i];
        for(int j=0;j<countUn;j++){
            if(a[i]==Union[j]){
                temp = false;
            }
        }
        if(temp){
            Union[countUn] = a[i];
            countUn++;
        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    int oldcountUn = countUn;
    for(int i=0;i<n;i++){
        bool temp = true;
        for(int j=0;j<n;j++){
            if(b[i]==Union[j]){
                temp = false;
            }
        }
        if(temp){
            bool checkU = true;
            for(int k=oldcountUn;k<countUn;k++){
                if(b[i]==Union[k]){
                    checkU = false;
                }
            }
            if(checkU){
                Union[countUn] = b[i];
                countUn++;
            }
            
        }
    }


    for(int i=0;i<countUn;i++){
        cout<<Union[i]<<" ";
    }
    return 0;
}