#include <bits/stdc++.h>
using namespace std;

int n;
int maxCoin = INT_MIN;

void subset(int arr[], int k, int coins[]) {
    if (k == n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                sum += coins[i];
            }
            
            if (sum > maxCoin) {
                maxCoin = sum;
            }
        }
        return;
    }
    
    arr[k] = 1;
    if (k == 0 || arr[k-1] != 1) {
        subset(arr, k+1, coins);
    }
    arr[k] = 0;
    subset(arr, k+1, coins);

}

int main() {
    int coins[] = {30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
    n = sizeof(coins)/sizeof(coins[0]);
    subset(new int[n], 0, coins);
    
    cout << maxCoin;
    return 0;
}