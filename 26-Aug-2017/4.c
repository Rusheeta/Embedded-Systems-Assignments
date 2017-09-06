#include<stdio.h>
#include<conio.h>
void main()
{
int N,i;
float Num,ADD=0,AVG;
clrscr();
printf("Enter how many numbers you need:");
scanf("%d",&N);
printf("Enter %d numbers:\n",N);
for(i=1;i<=N;i++)
{
scanf("%f",&Num);
ADD=Num+ADD;
}
AVG=ADD/N;
printf("Average of N numbers is %f",AVG);
getch();
}
