#include<iostream>
using namespace std;
int binarySearch(int key,int arr[],int l,int r){
  int m=l+(r-l)/2;
  //base case
  if(arr[m]==key)
  return m;

  else if(key>arr[m]){
  binarySearch(key,arr,m+1,r);
  }

  else{
    binarySearch(key,arr,l,m);
  }
}
int main(){
  int arr[10]={1,2,3,4,5,6,7,8,9,10};
  int key=3;
  int ans=binarySearch(3,arr,0,9);
  cout<<"The index is:"<<ans;
}