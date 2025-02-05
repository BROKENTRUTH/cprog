#include<stdio.h>
int main()
{
    int n;
    printf("enter the total number to be entered is ");
    scanf("%d",&n);
    printf("enter tne numbers:\n");
    int num[n],max=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int j=0;j<n;j++)
    {
        if(max<num[j])
        {
            max=num[j];
        }
    }
    printf("Greatest number is %d",max);
}


