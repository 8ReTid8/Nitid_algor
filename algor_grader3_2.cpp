#include <bits/stdc++.h>
using namespace std;
int Power(int x, int n, int &c)
{
    
    if (n == 0)
    {
        return 1;
    }
    c++;
    if (n % 2 == 0)
    {
        int half = Power(x, n / 2, c);
        // c++;
        return half * half;
    }
    else
    {
        int half = Power(x, n / 2, c);
        // c++;
        return x * half * half;
    }
    return 0;
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
    int c = 0;
    cout << Power(n, k, c) << " " << c-1;
    return 0;
}
