#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    float start;
    float end;
} train;

bool compareItem(train b1, train b2)
{
    if (b1.start < b2.start)
    {
        return true;
    }
    return false;
}

void paltform(int n, train arr[])
{
    float machine[n] = {0};
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        bool assigned = false;
        for (int j = 0; j < count; j++)
        {
            if (arr[i].start >= machine[j])
            {
                machine[j] = arr[i].end;
                assigned = true;
                break;
            }
        }
        if (!assigned)
        {
            count++;
            machine[count - 1] = arr[i].end;
        }
    }

    cout << "number of machines : " << count << endl;
}

int main()
{
    int n;
    cin >> n;
    train arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].start >> arr[i].end;
    }
    sort(arr, arr + n, compareItem);
    for (int i = 0; i < n; ++i)
    {
        cout<< arr[i].start<<" "<<arr[i].end<<endl;
    }
    paltform(n,arr);
    return 0;
}
