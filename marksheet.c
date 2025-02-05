#include<stdio.h>
int main()
{
     int n,top=0,mtop=0,ptop=0,ctop=0,a,b,c,d;
     printf("enter the number of students of a class ");
     scanf("%d",&n);
     int math[n],chem[n],phy[n],sum[n];
     for(int i=0;i<n;i++)
     {
        printf("Enter the marks out of 100 of roll no.%d of mathematics, physic and chemistry respectively\n",i+1);
        scanf("%d",&math[i]);
        scanf("%d",&phy[i]);
        scanf("%d",&chem[i]);
        sum[i]=math[i]+phy[i]+chem[i];
     } 
     printf("roll no who has failed in exam are:\n ");
     for(int j=0;j<n;j++)
     {
        if(mtop<math[j])
        {
            mtop=math[j];
            a=j+1;
        }
        if(ptop<phy[j])
        {
            ptop=phy[j];
            b=j+1;
        }
        if(ctop<chem[j])
        {
            ctop=chem[j];
            c=j+1;
        }
        if(top<sum[j])
        {
            top=sum[j];
            d=j+1;
        }
        if(sum[j]<151)
        {
            printf("Rollno.%d with score %d out of 300\n",j+1,sum[j]);
        }
     }
     printf("Topper in mathematics is rollno.%d with score %d out of 100\n",a,math[a-1]);
     printf("Topper in physics is rollno.%d with score %d out of 100\n",b,phy[b-1]);
     printf("Topper in chemistry is rollno.%d with score %d out of 100\n",c,chem[c-1]);
     printf("Topper of the class is rollno.%d with score %d out of 300\n",d,sum[d-1]);
}