#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> o(100, vector<int>(100, -1));
int f(int n, int k)
{
    if (n >= k)
    {
        if (n == k)
        {
            return 1;
        }
        else if (k == 0)
        {
            return 1;
        }
        else if (k == 1)
        {
            return 1;
        }
        else if (o[n][k] != -1)
        {
            return o[n][k];
        }
        else
        {
            o[n][k] = f(n - 1, k) + f(n - 1, k - 2);
            return o[n][k];
        }
    }
    return 0;
}


vector<int> m(100, -1);
int g(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (m[n] != -1)
    {
        return m[n];
    }
    else
    {
        m[n] = g(n - 1) + g(n - 2) - g(n - 3);
        return m[n];
    }
}

int main()
{
    cout << g(7) << f(6, 4);
    vector<int> g(100, -1);
    g[0] = 0;
    g[1] = 1;
    g[2] = 1;
    for (int i = 3; i <= 7; i++)
    {
        g[i] = g[i - 1] + g[i - 2] - g[i - 3];
    }
    cout << g[7];

    vector<vector<int>> fi(100, vector<int>(100));
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            if (i >= j)
            {
                if (i == j || j == 0 || j == 1)
                {
                    fi[i][j] = 1;
                }
                else
                {
                    fi[i][j] = fi[i - 1][j] + fi[i - 1][j - 2];
                }
            }
        }
    }
    cout << fi[6][4];
    return 0;
}
