#include<stdio.h> 
#include <string.h> 
typedef struct { 
int rollno; 
char name[10]; 
} Student; 
void main(){ 
int i; 
Student st[4]; 
printf("Enter Records of 5 students\n"); 
for(i=0;i<4;i++){ 
printf("Enter Rollno:"); 
scanf("%d",&st[i].rollno); 
printf("Enter Name:"); 
scanf("%s",&st[i].name); 
} 
printf("\nStudent Information List:"); 
for(i=0;i<4;i++) 
printf("\nRollno:%d, Name:%s",st[i].rollno,st[i].name); 
}