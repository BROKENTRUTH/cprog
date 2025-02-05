#include <stdio.h>

int calculatemarks(int phy,int math,int che );
int main()
{
	int phy=98;
	int math = 99;
	int che = 100;
	printf(" precentage is:%d",calculatemarks(phy,math,che));
	return 0;
}
int calculatemarks(int phy,int math,int che) 
{
return ((phy+math+che)/3);
}

