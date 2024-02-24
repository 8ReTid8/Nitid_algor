#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int gift1[n];
    int gift2[n];
    int i = 0;
    for(int i=0;i<n;i++){
        cin >> gift1[i];
        cin >> gift2[i];
    }

    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            if (gift1[i] > gift2[i])
            {
                a += gift1[i];
                b += gift2[i];
            }
            else
            {
                a += gift2[i];
                b += gift1[i];
            }
        }
        if (i >= n / 2)
        {
            if (gift1[i] > gift2[i])
            {
                b += gift1[i];
                a += gift2[i];
            }
            else
            {
                b += gift2[i];
                a += gift1[i];
            }
        }
    }
    cout << abs(a - b);
    return 0;
}