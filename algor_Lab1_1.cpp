#include <bits/stdc++.h>
using namespace std;

void buildMaxHeap(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{

		if (arr[i] > arr[(i - 1) / 2])
		{
			int j = i;
			while (arr[j] > arr[(j - 1) / 2])
			{
				swap(arr[j], arr[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
		}
	}
	for (int k = 0; k < n; k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;
}

void heapSort(int arr[], int n)
{
	buildMaxHeap(arr, n);

	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		int j = 0, index;
		do
		{
			index = (2 * j + 1);
			if (arr[index] < arr[index + 1] && index < (i - 1))
				index++;

			if (arr[j] < arr[index] && index < i){
				swap(arr[j], arr[index]);
				for (int k = 0; k < n; k++)
				{
					cout << arr[k] << " ";
				}
				cout << endl;
			}
			j = index;
			cout << j << endl;
		} while (index < i);
	}
}

int main()
{

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	heapSort(arr, n);
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] != arr[i] - 1)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
