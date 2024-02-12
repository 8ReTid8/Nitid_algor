#include <bits/stdc++.h>

using namespace std;

int n;
int minDiff = INT_MAX;

void subset(int k, int momoi, int midori, int gift1[], int gift2[]) {
    if (k == n) {
        minDiff = min(abs(momoi-midori), minDiff);
        return;
    }
    
    momoi += gift1[k];
    midori += gift2[k];
    
    if (abs(momoi-midori) < minDiff) {
        subset(k+1, momoi, midori, gift1, gift2);
    }
    
    momoi -= gift1[k];
    midori -= gift2[k];
    
    momoi += gift2[k];
    midori += gift1[k];
    subset(k+1, momoi, midori, gift1, gift2);
}
    
int main() {
    int gift1[] = {3, 7, 8, 2};
    int gift2[] = {5, 11, 8, 9};
    
    n = sizeof(gift1)/sizeof(gift1[0]);
    subset(0, 0, 0, gift1, gift2);
    
    cout << minDiff;
    return 0;
}