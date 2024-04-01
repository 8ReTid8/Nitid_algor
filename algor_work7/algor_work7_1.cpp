#include <bits/stdc++.h>
using namespace std;
void wow(string x, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
void permui(string x, int k, int n)
{
    if (k == n)  
    {
        wow(x, k);
    }
    else
    {
        for (int i = k ; i < n; i++)
        {
            swap(x[k],x[i]);
            permui(x, k + 1, n);
            swap(x[i],x[k]);
        }
    }
}
int main(){
    string str = "ABEX";
    int n = str.length();
    permui(str,0,n);
    return 0;
}
