#include <bits/stdc++.h>
using namespace std;
void sort(int arr[],int n){
    int temp = 0;
    for(int i=0;i<n;i++){
        int Min = i;
        for(int j=i+1;j<n;j++){
            if(arr[Min]>arr[j]){
                Min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[Min];
        arr[Min] = temp;
    }
}

int check(int x[], int k,int temp[])
{
    int sum = 0;
    int count = 0;
    for(int i=0;i<k;i++){
        if(temp[i]==1){
            count++;
        }
    }
    if(count<3){
        return 0;
    }
    else{
        count = 0;
        for (int i = 0; i < k; i++)
        {  
            if(temp[i]==1){
                sum+=x[i];
                count++;
            }
        }
    }
    return sum;
}

void binary(int x[],int k,int n,int temp[],int& Max,int money,int arrMax[]){
    
    if(k==n){
        int find = check(x,k,temp);
        if(find>Max && find<=money){
            Max = find;
            for(int i=0;i<n;i++){
                arrMax[i] = temp[i];
            }
        }
    }
    else{
        temp[k] = 1;
        binary(x,k+1,n,temp,Max,money,arrMax);
        temp[k] = 0;
        binary(x,k+1,n,temp,Max,money,arrMax);
    }
}

int main(){
    int n,money;
    cin>>n>>money;
    int arr[n],temp[n],arrMax[n];
    int Max = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
    binary(arr,0,n,temp,Max,money,arrMax);
    
    cout<<"ans :"<<endl;
    if(Max==0){
        for(int i=0;i<3;i++){
            cout<<0<<endl; 
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(arrMax[i]==1){
                cout<<arr[i]<<endl;
            }
        }
    }

    return 0;
}
