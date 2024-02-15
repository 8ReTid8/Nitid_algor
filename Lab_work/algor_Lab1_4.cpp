#include <iostream>
using namespace std;

bool check(int arr[],int n){
    if(n==0){
        return true;
    }
    else if(arr[n-1]<=arr[n]){
        return check(arr,n-1);
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

    bool checksort = check(arr,n-1);
    
    if (checksort)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}