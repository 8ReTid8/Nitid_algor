#include <iostream>
using namespace std;

int n = 4, X[4];

void nqueen(int k,int Bool[])
{
    
    if (k == n)
    {
        for (int i = 0; i < k; i++)
        {
            cout << X[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            X[k] = j;
            bool broke = true;
            for (int i = 0; i < k; i++)
            {
                if (abs(k - i) == abs(X[k] - X[i]) || (X[k] == X[i]))
                {
                    broke = false;
                    break;
                }
            }
            if (broke)
            {
                Bool[k] = 1;
                nqueen(k + 1,Bool);
            }
        }
    }
}

int main()
{
    nqueen(0,new int[n]{0});
    return 0;
}