#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Partition(int *arr,int l,int r){
    int pIndex=l;
    int pivot=arr[r];
    for(int i=l;i<r;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    
    swap(arr[pIndex],arr[r]);
    
    return pIndex;
}
void quicksort(int *arr,int l,int r){
    if(l<r){
        int p=Partition(arr,l,r);
    
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
    }
    
}

int main(){
int arr[]={2,10,3,7,8,4};
for(int i=0;i<=5;i++){
    cout<<arr[i]<<" ";
}
quicksort(arr,0,5);
cout<<endl;
for(int i=0;i<=5;i++){
    cout<<arr[i]<<" ";
}
   return 0;
}