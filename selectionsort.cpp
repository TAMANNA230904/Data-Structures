#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int arr[]={100,87,25,12,34};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        int minindex=i;
        for(int j=i;j<n;j++){
            if(arr[minindex]>arr[j]){ 
                swap(arr[minindex],arr[j]);
            }

        }
    }
    for(int p=0;p<n;p++){
        cout<<arr[p]<<" ";
    }
    return 0;
}