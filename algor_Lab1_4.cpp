#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    bool temp = true;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool minmax = true;
    bool maxmin = true;
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            minmax = false;
        }
        if(arr[i-1]<arr[i]){
            maxmin = false;
        }   
    }

    if(minmax){
        cout<<"yes";
    }
    else if(maxmin){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}