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
if((c*c)==(a*a)+(b*b)||(b*b)==(a*a)+(c*c)||(a*a)==(c*c)+(b*b))
{
printf("A right angled triangle.");
}
else
{
printf("Not a right angled triangle.");
}
getch();
}
