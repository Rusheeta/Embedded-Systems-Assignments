#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c;
clrscr();
printf("Enter the length of side a of a triangle: ");
scanf("%d",&a);
printf("Enter the length of side b of a triangle: ");
scanf("%d",&b);
printf("Enter the length of side c of a triangle: ");
scanf("%d",&c);
if(a+b>c && b+c>a && a+c>b )
{
printf("a,b,c are valid lengths to form a triangle.");
}
else
{
printf("a,b,c are not valid lengths to form a triangle.");
}
getch();
}
