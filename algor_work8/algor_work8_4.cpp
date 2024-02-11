#include <bits/stdc++.h>

using namespace std;


int check(int x[], int k,int a[])
{
    int sum = 0; 
    for (int i = 0; i < k-1; i++)
    {
        if(a[i] && a[i+1]){
            return 0;
        }
        if(a[i]==1){
            sum+=x[i];
        }
    }
    return sum;
}
void genebinary(int x[],int k,int n,int a[],int& m){
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    if(k==n){
        int temp = check(x,k,a);
        m = max(temp,m);
    }
    else{
        a[k] = 1;
        genebinary(x,k+1,n,a,m);
        a[k] = 0;
        genebinary(x,k+1,n,a,m);
    }
}
int main()
{
    int n = 10;
    int arr[n] = {30,10,8,20,11,12,25,13,20,19};
    int temp[n];
    int Max = 0;
    genebinary(arr, 0, n,temp,Max);
    cout<<Max;
}