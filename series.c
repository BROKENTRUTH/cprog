#include<stdio.h>
int main()
{
    int n,a=0,b=1,c;
    printf("enter the number of terms ");
    scanf("%d",&n);
    printf("fibonacci series :\n");
    printf("%d\n%d\n",a,b);
    for(int i=1;i<=n-2;i++)
    { 
        c=a+b;
        a=b;
        b=c;
        printf("%d \n",c);
    }
    return 0;
}