#include <bits/stdc++.h>
using namespace std;

vector<int> countsort(vector<int> arr){
    int n = arr.size();
    int m = 0;
    for(int i=0;i<n;i++){
        m = max(m,arr[i]);
    }
    vector<int> countarr(m+1);
    for(int i=0;i<n;i++){
        countarr[arr[i]]++;
    }
    for(int i=1;i<m+1;i++){
        countarr[i]+=countarr[i-1];
    }
    vector<int> sortarr(n);
    for(int i=0;i<n;i++){
        countarr[arr[i]]--;
        sortarr[countarr[arr[i]]] = arr[i];
    }
    return sortarr;
}

string changetostr(vector<int> arr){
    stringstream ss("");
    for (int i = 0; i < arr.size(); i++) 
    {
        ss << arr[i];
    }
    return ss.str();
}

string popsamenum(string s){
    stringstream temp("");
    for (int i = 0;i<s.length();i++){
        if(s[i]!=s[i+1]){
            temp << s[i];
        }
    }
    return temp.str();
}

void countmaxsame(string s){
    vector<int> freq;
    int maxDup = 0;

    for (int i = 0; i < s.length();i++) {
        int dup = 1;
        int pivot = i;
        while ((s[pivot] - '0') == (s[i+1] - '0')) {
            dup++;
            i++;
        }

        if (dup > maxDup) {
            maxDup = dup;
            freq.clear();
            freq.push_back(s[pivot] - '0');
        } else if (dup == maxDup) {
            freq.push_back(s[pivot] - '0');
        }

    }
    for(int i=0;i<freq.size();i++){
        cout << freq[i] <<" ";
    }
    cout << endl;
}

int main(){
    int n; 
    cin>>n;
    vector<int> arr(n);
    string cum;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr = countsort(arr);
    cum = changetostr(arr);
    cout<<cum<<endl;
    countmaxsame(cum);
    cum = popsamenum(cum);
    cout<<cum;
}