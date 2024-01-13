#include <bits/stdc++.h>
using namespace std;


int interpolationSearch(int arr[], int l, int r, int k)
{
	int x;

	if (l <= r && k >= arr[l] && k <= arr[r]) {

		x = l + (((r - l)*(k - arr[l])) / (arr[r] - arr[l]));
        cout<<x<<" ";

		if (arr[x] == k)
			return x;
	
		if (arr[x] < k)
			return interpolationSearch(arr, x + 1, r, k);

		if (arr[x] > k)
			return interpolationSearch(arr, l, x - 1, k);
	}
	return -1;
}


int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    interpolationSearch(arr, 0, n - 1, k);

	return 0;
}


