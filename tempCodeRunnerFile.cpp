for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(x[i] - x[j]) == abs(j - i) || x[j] == x[i])
                {
                    return;
                }
            }
        }