#include<bits/stdc++.h>
using namespace std;
typedef struct 
{
    int start;
    int end;
    int linelong;
}line;

void lineconnect(int n,line arr[],line target){
    int templong = ;
    for(int i=0;i<n;i++){
        int
        for(int j = templong;j<n;j++){
            if(arr[i].start<=target.start){

            }
        }
    }
} 

int main(){
    int n;
    cin>>n;
    line arr[n];
    line target;
    target.start = INT_MAX;
    target.end = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
        arr[i].linelong = arr[i].end - arr[i].start;
        target.start = min(arr[i].start,target.start);
        target.end = max(arr[i].end,target.end);
    }
    cout<<target.end;
    return 0;
}
