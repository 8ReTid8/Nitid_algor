#include<bits/stdc++.h>
using namespace std;
typedef struct 
{
    int start;
    int end;
    int linelong;
}line;

bool compareItem(line b1, line b2)
{
    if (b1.linelong > b2.linelong)
    {
        return true;
    }
    return false;
}

void lineconnect(int n,line arr[],line target){
    int count = 0; 
    line a[n];
    int check = target.start;
    cout<<"Ans :"<<endl;
    for(int i=0;i<n;i++){
        if(arr[i].start<target.start||arr[i].end>target.end){
            continue;
        }
        if(arr[i].start<=check&&arr[i].end>check){
            check = arr[i].end;
            cout<<arr[i].start<<" "<<arr[i].end<<endl;
            count++;
        }
    }
    cout<<count;
} 

int main(){
    int n;
    cin>>n;
    line arr[n];
    line target;
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
        arr[i].linelong = arr[i].end - arr[i].start;
    }
    cin>>target.start>>target.end;
    sort(arr, arr + n, compareItem);
    lineconnect(n,arr,target);
    return 0;
}
