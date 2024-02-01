#include <bits/stdc++.h>
using namespace std;

void print(int x[], int k,int& count)
{
    if(k==0){
        cout<<0<<endl;
        count++;
    }
    else{
        for (int i = 1; i <= k; i++)
        {
            cout << x[i] << " ";
        }
        count++;
        cout << endl;
    }
}
void sub(int x[], int k, int n,int& count)
{
    print(x, k,count);
    int j;
    if(k == 0){
        j = 1;
    }
    else{
        j = x[k]+1;
    }

    for (int i = j; i <= n; i++)
    {
        x[k + 1] = i;
        // for(int k=0;k<n+1;k++){
        //     cout<<x[k]<<" ";
        // }
        // cout<<endl;
        sub(x, k + 1, n,count);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n+1] = {0};
    int count = 0;
    sub(arr,0,n,count);
    cout<<count;
    return 0;
}