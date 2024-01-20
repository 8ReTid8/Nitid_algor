#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr[9][2] = {{1,4},{2,6},{3,1},{4,5},{5,7},{6,9},{7,2},{8,6},{9,3}};
	//check
	int maxx[9] = {0};
	int maxy[9] = {0};
	int k=0;
	for(int i =0;i<9;i++){
		for(int j =0;j<9;j++){
			if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1] ){
				break;
			}
			if(j == 9-1){
				maxx[k] = arr[i][0];
				maxy[k] = arr[i][1];
				k++;
			}
			
		}
	}
	
	for(int i=0;i<9;i++){
		cout << maxx[i] << " " <<maxy[i];
	}
}
