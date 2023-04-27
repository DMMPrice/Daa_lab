
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearsearch(int *a,int b,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==b){
            c=i+1;
            return(c);
            break;
        }}
    
    
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
    clock_t start_t,end_t;
    double total_t;
    printf("Enter the element you want to search: ");
    scanf("%d",&m);
    start_t=clock();
    printf("Found at %d position",linearsearch(a,m,n));
    end_t=clock();
    total_t=(double)(end_t-start_t);
    printf("\nTotal time: %f",total_t);
}
