void permute(int X[], int start, int end, int check[], int max, int copyArr[])
{
    cunny++;
    if (start == end)
    {
        return;
    }
    check[start] = 1;
    int sum = 0, prop = 0;
    for (int i = 0; i < end; i++)
    {
        if (check[i] == 1)
        {
            sum += X[i];
            prop += 1;
        }
    }
    if (sum > max)
    {
        return;
    }
    else if ((max - maxNumber > max - sum) && prop >= 3)
    {
        maxNumber = sum;
        created = true;
        int t = 0;
        fill(copyArr, copyArr + end, 0);
        for (int i = 0; i < end; i++)
        {
            if (check[i] == 1)
            {
                copyArr[t] = X[i];
                t++;
            }
        }
        permute(X, start + 1, end, check, max, copyArr);
        check[start] = 0;
        permute(X, start + 1, end, check, max, copyArr);
    }
    else
    {
        permute(X, start + 1, end, check, max, copyArr);
        check[start] = 0;
        permute(X, start + 1, end, check, max, copyArr);
    }
}

int main()
{
    int n = 8, max = 600;
    int X[] = {136, 411, 211, 200, 275, 189, 232, 375};
    quickSort(X, 0, n - 1);
    int *check = new int[n]{0};
    int copy[n];
    fill(copy, copy + n, 0);
    permute(X, 0, n, check, max, copy);
    if (!created)
    {
        cout << 0 << endl
             << 0 << endl
             << 0 << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (copy[i] != 0)
            {
                cout << copy[i] << endl;
            }
            else
            {
                break;
            }
        }
    }
    cout<<cunny<<endl;
    return 0;
}