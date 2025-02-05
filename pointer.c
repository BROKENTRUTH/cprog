#include<stdio.h>
int main()
{
    int var=10;
    int*ptr=&var;
    printf("value of var is %d \n",*ptr);
    printf("Address of var is %p\n",ptr);
    *ptr = 20;
    printf("after doing *ptr is %d \n",var);
}