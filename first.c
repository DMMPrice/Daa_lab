
#include<stdio.h>
#include<stdlib.h>

void linearsearch(int *a,int b,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==b){
            c=i+1;
            printf("Present at %d",c);
            exit(0);
        }}
    if(c==0)
        printf("Element not found");
    
}
void main(){
    int *a,n,m,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d",&m);
    linearsearch(a,m,n);

        printf("Element not found");
