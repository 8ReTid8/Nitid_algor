#include <bits/stdc++.h>
using namespace std;


void merge(int arr[],int l,int m,int r){
    int i, j, k=l;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    i=0,j=0;
    while (i < n1 && j < n2){ 
        if(L[i] <= R[j]){ 
            arr[k] = L[i];
            i++;
        }
        else{ 
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) // copy left sub-array
    { 
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) // copy right sub-array
    { 
        arr[k] = R[j];
        j++;
        k++;
    }

}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m = (l+(r-1))/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
		
    }
}


int main()
{

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int l=0;
	int r=n-1;
	mergesort(a,l,r);
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] != a[i] - 1)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
