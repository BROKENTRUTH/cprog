#include<stdio.h> 
typedef struct { 
char city[20]; 
int pin; 
char phone[14]; 
}Address; 
typedef struct { 
char name[20]; 
Address add; 
}Employee; 
int main() { 
Employee emp; 
printf("Enter employee information?\n"); 
scanf("%s %s %d %s",emp.name,emp.add.city, 
&emp.add.pin, emp.add.phone); 
printf("Printing the employee information....\n"); 
printf("Name: %s\nCity: %s\nPincode: %d\nPhone: %s\n", emp.name, emp.add.city, emp.add.pin, emp.add.phone);
return 0;
}