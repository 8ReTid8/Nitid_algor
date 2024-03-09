vector<vector<int>> fi(100, vector<int>(100, -1));
    // for (int i = 0; i <= 6; i++)
    // {
    //     for (int j = 0; j <= 4; j++)
    //     {
    //         if (i == j || j == 0 || j == 1)
    //         {
    //             fi[i][j] = 1;
    //         }
    //         else
    //         {
    //             fi[i][j] = fi[i - 1][j] + fi[i - 1][j - 2];
    //         }
    //     }
    // }
    // cout<<fi[6][4];