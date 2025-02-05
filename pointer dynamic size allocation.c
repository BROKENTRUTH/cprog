#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("enter the size of array ");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int *b=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}