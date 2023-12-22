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
    if(arr[0]<arr[1]){
        
        int differ = arr[0];
        for(int i=1;i<n;i++){
            if(differ<arr[i]){
                differ = arr[i];
            }
            else{
                temp = false;
                break;
            }
        }
    }
    cout<<temp;
}