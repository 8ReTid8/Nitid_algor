#include <iostream>
using namespace std;

bool check(int arr[],int n,int i=1){
    if(n==i){
        return true;
    }
    else if(arr[i-1]<=arr[i]){
        return check(arr,n,i+1);
    }
    else{
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    bool temp = true;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bool checksort = check(arr,n);
    
    if (checksort)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}