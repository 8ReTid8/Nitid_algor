#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	// bubble sort
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
	
    stringstream ss;

    // convert int to string
    for (int i = 0; i < n; i++) {
        ss << arr[i];
    }

    string s1 = ss.str();
    cout << s1;
	cout << endl;


	// checking popularity
	int mainIndex = 0;
	int innerIndex = 0;
	int maxDup = 0;

	vector<char> dupVector;

	while (mainIndex < s1.length() && innerIndex < s1.length()) {
		int dupCount = 1;
		innerIndex = mainIndex+1;
		while(innerIndex < s1.length() && s1[mainIndex] == s1[innerIndex]) {
			innerIndex++;
			dupCount++;
		}
		if (dupCount > maxDup) {
			maxDup = dupCount;
			dupVector.clear();
			dupVector.push_back(s1[mainIndex]);
		} else if (dupCount == maxDup) {
			dupVector.push_back(s1[mainIndex]);
		}

		mainIndex = innerIndex;
	}

	// sort and remove dup num
	for (int i = 0; i < dupVector.size(); i++) {
		for (int j = 0; j < dupVector.size()-i-1; j++) {
			if (dupVector[j] - '0' > dupVector[j+1] - '0') {
				swap(dupVector[j], dupVector[j+1]);
			}
		}
	}

	// print 2nd
	int ptr1 = 0;
	int ptr2 = 0;
	while (ptr1 < dupVector.size() && ptr2 < dupVector.size()) {
		cout << dupVector[ptr1] << " ";
		ptr2 = ptr1+1;
		while (ptr2 < dupVector.size() && dupVector[ptr1] == dupVector[ptr2]) {
			ptr2++;
		}
		ptr1 = ptr2;
	}
	cout << endl;

	// print 3rd
	ptr1 = 0;
	ptr2 = 0;
	while (ptr1 < s1.size() && ptr2 < s1.size()) {
		cout << s1[ptr1];
		ptr2 = ptr1+1;
		while (ptr2 < s1.size() && s1[ptr1] == s1[ptr2]) {
			ptr2++;
		}
		ptr1 = ptr2;
	}

    return 0;
}
