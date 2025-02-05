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
    if(a==b)
        printf("palindrome number");
        else
           printf("not a palindrome number");
    return 0;
}