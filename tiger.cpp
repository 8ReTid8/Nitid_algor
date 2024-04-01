#include<bits/stdc++.h>
using namespace std;
struct Item{
    double start;
    double end;
};
int main(){
    int n;
    cin >> n;
    Item ar[n];
    for(int i =0;i<n;i++){
        cin >> ar[i].start;
        cin >> ar[i].end;
    }
    //
    int count1 = 0;
    double machine[n] = {0};
    for(int i =0;i<n;i++){
        bool assigned = false;
        for(int j=0;j<count1;j++){
            if(ar[i].start >= machine[j]){
                assigned = true;
                machine[j] = ar[i].end;
                break;
            }
        }
        if(!assigned){
            count1++;
            machine[count1-1] = ar[i].end;
        }
    }
    cout << count1;
}