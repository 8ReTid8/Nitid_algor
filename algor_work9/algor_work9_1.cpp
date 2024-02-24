#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    float v;
    float w;
    float value;
    float weightuse = 0;
    int index;
}item;

bool compareItem(item b1, item b2) {
   if(b1.value > b2.value) {
      return true;
   } return false;
}

void highvalue(int total,int n,item arr[]){
    float money = 0;
    int weight = 0; 
	for (int i=0; i<n; i++){
        weight+=arr[i].w;
        if(weight<total){
            money+=arr[i].v;
            arr[i].weightuse = 1;
        }
        if(weight==total){
            money+=arr[i].v;
            break;
        }
        if(weight>total){
            int temp = total-(weight-arr[i].w);
            arr[i].weightuse=temp/arr[i].w;
            money+=arr[i].v*arr[i].weightuse;
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j].index==i){
                cout<<arr[j].weightuse<<" ";
            }
        }
    }
    cout<<endl;
	cout << money;
}

int main(){
    int n,target;
    cin>>n>>target;
    item arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].w;
    }for(int i=0;i<n;i++){
        cin>>arr[i].v;
        arr[i].index = i;
        arr[i].value = arr[i].v/arr[i].w;
    }
    sort(arr, arr+n, compareItem);
    highvalue(target,n,arr);
    return 0;
}