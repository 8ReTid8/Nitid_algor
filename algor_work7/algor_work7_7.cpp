#include <bits/stdc++.h>
using namespace std;
int check(int x[][2], int k,int Bool[][2])
{
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            cout<<Bool[i][j]<<" ";
        }
        cout<<",";
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            if(Bool[i][j]==1){
                sum1+=x[i][j];
            }
            else{
                sum2+=x[i][j];
            }
        }
    }
    cout<<abs(sum1-sum2)<<endl;
    return abs(sum1-sum2);
}

void binary(int x[][2],int k,int n,int Bool[][2],int& Min){
    
    if(k==n){
        int temp = check(x,k,Bool);
        Min = min(temp,Min);
    }
    else{
        Bool[k][0] = 1;
        Bool[k][1] = 0;
        binary(x,k+1,n,Bool,Min);
        Bool[k][0] = 0;
        Bool[k][1] = 1;
        binary(x,k+1,n,Bool,Min);
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n][2],Bool[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    int Min = INT_MAX;
    binary(arr,0,n,Bool,Min);
    cout<<Min;
    return 0;
}