#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    float start;
    float end;
} Time;
bool compareTo(Time b1,Time b2){
    if(b1.start<b2.end){
        return true;
    }
    return false;
}
void machine(int n,Time arr[]){
    int count = 0;
    float machine[n] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++){
            if(s)
        }
    }
}
int main()
{
    int n;
    cin >> n;
    Time arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
    }
    sort(arr,arr+n,compareTo);
    for(int i=0;i<n;i++){
        cout<<arr[i].start<<" ";
    }
    return 0;
}