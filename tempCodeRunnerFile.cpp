 #include <bits/stdc++.h>
using namespace std;
int Partition(int ar[],int l,int r){
    int p = ar[l];
    int i  = l;
    int j = r + 1;
    do{
        do{
            i=i+1;
        }while(ar[i] < p);
        do{
            j=j-1;
        }while(ar[j]>p);
        swap(ar[i],ar[j]);
    }while(i < j);
    swap(ar[i],ar[j]);
    swap(ar[l],ar[j]);
    return j;
}
void quickSort(int ar[],int l,int r){
    int s=0;
    if(l < r){
        s=Partition(ar,l,r);
        quickSort(ar,l,s-1);
        quickSort(ar,s+1,r);
    }
}

int main(){
    int n;
    cin >> n;
    int *ar = new int[n];
    int i =0;
    while(i < n){
        cin >> ar[i];
        i++;
    }
    quickSort(ar,0,n-1);
    for(int i =0;i<n;i++){
        cout << ar[i] << " ";
    }
}