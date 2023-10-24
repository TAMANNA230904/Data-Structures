#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("Enter the size of array:");
scanf("%d",&n);
int *arr=(int *)malloc(n*sizeof(int));
for(int i=0;i<n;i++){
    printf("Enter the no.:");
    scanf("%d",&arr[i]);
}
for(int i=0;i<n;i++){
    printf("The no. is:%d\n",arr[i]);
}
return 0;
}

