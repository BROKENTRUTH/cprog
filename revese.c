#include<stdio.h>
int main()
{
    int n,b,a;
    printf("Enter the number :");
    scanf("%d",&n);
    a=n;
    while(n>0)
    {
      b=b*10+n%10;
      n=n/10;
    }
    printf("Reverse of number %d is %d",a,b);
    return 0;
}