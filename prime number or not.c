#include<stdio.h>
int main()
{
    int n,a=0;
    printf("Enter the number ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
       if(n%i==0){
         a++;
       }
    }
    if(a==2)
    {
        printf("prime number");
    }
    if(a!=2)
    {
        if(a==1)
        {
            printf("neither a prime number nor a composite number");
        }
        else{
            printf("composite number");
        }
    }
}