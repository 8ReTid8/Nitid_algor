#include <bits/stdc++.h>
using namespace std;

int binarysearch(int A[],int n,int m){
    int l=0;
    int r=n-1;
    
    while(l<r){
        int mid = (l+r)/2;
        cout<<mid<<endl;
        if(m<A[mid]){
            r = mid-1;
        }
        if(m>A[mid]){
            l = mid+1; 
        }
        if(m==A[mid]){
            return mid;
        }
    }
    return l;
}

void findK(int A[], int M, int k, int n)
{
    int i = 0;
    // while ((A[i] < M) && (i < n)){
    //     i++;
    // }
    i = binarysearch(A,n,M);
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
    int M = 30, k = 5;
    int n = sizeof(A)/sizeof(A[0]);
    A[-1] = INT_MAX;
    A[n] = INT_MAX;
    findK(A, M, k, n);
    return 0;
}