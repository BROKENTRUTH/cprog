#include<stdio.h>
int main()
{
    int a,b,lcm=1,c,d,i;
    printf("Enter the first number ");
    scanf("%d",&a);
    printf("Enter the second number ");
    scanf("%d",&b);
    c=a;d=b;
    for(i=a;i>0;i--)
    {
        if(c%i==0 && d%i==0)
        {
            c=c/i;
            d=d/i;
            lcm=lcm*i;
        }
    }
    lcm=c*d*lcm;
    printf("lcm of %d and %d is %d",a,b,lcm);
    return 0;
}