#include<iostream>
using namespace std;

int main(){
    int arr[]={1,23,12,9,30,2,50};
    int size=sizeof(arr)/sizeof(int);
  
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<size;i++){
       for(int j=0;j<size-i;j++){
        if(arr[j]>arr[j+1]){
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
  }
  cout<<endl;
  for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}