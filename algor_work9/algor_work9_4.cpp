#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int gift1;
    int gift2;
    int rangediff;
} setgift;

bool compareItem(setgift b1,setgift b2){
    if(b1.rangediff>b2.rangediff){
        return true;
    }
    return false;
} 

void comparegift(setgift arr[],int n){
    int midori = arr[0].gift1;
    int momoi = arr[0].gift2;
    int diffval;
    for(int i=1;i<n;i++){
        int temp1 = abs((midori+arr[i].gift1)-(momoi+arr[i].gift2));
        int temp2 = abs((midori+arr[i].gift2)-(momoi+arr[i].gift1));
        if(temp1<temp2){
            midori += arr[i].gift1;
            momoi += arr[i].gift2;
            diffval = temp1;
        }
        else{
            midori += arr[i].gift2;
            momoi += arr[i].gift1;
            diffval = temp1;
        }
    }
    cout<<diffval;
}

int main(){
    int n;
    cin>>n;
    setgift arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].gift1>>arr[i].gift2;
        arr[i].rangediff = abs(arr[i].gift1-arr[i].gift2);
    }
    sort(arr, arr + n, compareItem);
    comparegift(arr,n);
    
    return 0;
}