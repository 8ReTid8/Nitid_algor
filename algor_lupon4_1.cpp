#include <bits/stdc++.h>
using namespace std;

void findK(int A[], int M, int k, int n)
{
    int i = 0;
    while ((A[i] < M) && (i < n)){
        i++;
    }

    int left = i - 1; // set left, right
    int right = i;

    while (right - left <= k)
    {
        cout<<left<<" "<<right<<endl;
        if (abs(A[left] - M) > abs(A[right] - M)){
            right++;
        }
        else{
            left--;
        }
    }
    for (int i = left + 1; i < right; i++){
        cout<<A[i]<<" ";
    }
}

int main()
{
    int A[] = {10, 12, 15, 17, 18, 20, 25};
    int M = 11, k = 8;
    int n = sizeof(A)/sizeof(A[0]);
    A[-1] = INT_MAX;
    A[n] = INT_MAX;
    findK(A, M, k, n);
    return 0;
}