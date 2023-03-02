#include<stdio.h>
#include<stdlib.h>

int linearsearch(int *a,int b,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==b){
            c=1;
            break;
        }
    }
    return c;
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
    i=linearsearch(a,m,n);
    if(i==0)
        printf("The number is not in the list\n");
    else
        printf("The number is in %d position of the the list\n",i+1);
}
