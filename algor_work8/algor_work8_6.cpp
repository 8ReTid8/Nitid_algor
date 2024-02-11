#include <bits/stdc++.h>

using namespace std;

int n;
int minDiff = INT_MAX;

void subset(int k, int sumA, int sumB, int gift1[], int gift2[]) {
    if (k == n) {
        minDiff = min(abs(sumA-sumB), minDiff);
        return;
    }
    
    sumA += gift1[k];
    sumB += gift2[k];
    
    if (abs(sumA-sumB) < minDiff) {
        subset(k+1, sumA, sumB, gift1, gift2);
    }
    
    sumA -= gift1[k];
    sumB -= gift2[k];
    
    sumA += gift2[k];
    sumB += gift1[k];
    subset(k+1, sumA, sumB, gift1, gift2);
}
    
int main() {
    int gift1[] = {3, 7, 8, 2};
    int gift2[] = {5, 11, 8, 9};
    
    n = sizeof(gift1)/sizeof(gift1[0]);
    subset(0, 0, 0, gift1, gift2);
    
    cout << minDiff;
    return 0;
}