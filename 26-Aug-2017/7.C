#include<stdio.h>
#include<conio.h>
void main()
{
int n,m,s,t,p;
char A;
clrscr();
printf("Let the guessed number be n.\n");
printf("Add 8 to n.\n");
m=n+8;
printf("Add 7 to the above sum.\n");
s=m+7;
printf("Subtract the guessed number from the above sum.\n");
t=s-n;
printf("Add 25 to the above total.\n");
p=t+25;
printf("Type 'Y'to reveal the answer.\n");
scanf(" %c",&A);
while(A=='Y')
{
printf("The answer you get is %d.",p);
A=' ';
}
getch();
}