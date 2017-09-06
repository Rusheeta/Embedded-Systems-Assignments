#include<stdio.h>
#include<conio.h>
float Max(float A[100],int n) //to calculate min of temperatures of each window
{
int i=0;
float max;
max=A[0];
while(i<n)
{
if(A[i]>=max)
max=A[i];
i++;
}
return max;
}
float Min(float B[100],int n) //to calculate min of temperatures of each window
{
int j=0;
float min=0;
min=B[0];
while(j<n)
{
if(B[j]<=min)
min=B[j];
j++;
}
return min;
}
float Average(float C[100],int n) // to calculate average of the temperatures of each window
{
float k=0,t=0;
float Avg;
while(k<n)
{
t=t+C[k];
k++;
}
Avg=t/n;
return Avg;
}
float display(int a,float D[100]) //to display max, min and average of temperatures for each window
{
float max=0,min=0,avg=0;
max=Max(D,a);
min=Min(D,a);
avg=Average(D,a);
printf("\nMaximum temperature for this window is %f\n",max);
printf("\nMinimum temperature for this window is %f\n",min);
printf("\nAverage is %f\n",avg);
return max,min,avg;
}

void main()
{
float Temp[100]={NULL};   //array to store temperature
float five[5]={NULL};     //array to store 5 mins temperatures
float ten[10]={NULL};     //array to store 10 mins temperatures
float fifteen[15]={NULL}; //array to store 15 mins temperatures
float temp=0;             //to enter temperatures
int idx=0,idx1=0,idx2=0;  //index of the arrays
int number;               //no of temperatures
int m,count=0;            //to print no of 5mins, 10mins,15mins windows
clrscr();
printf("Enter number of temperatures to be stored: \n");
scanf("%d",&number);
printf("Enter temperatures collected at every minute:\n");
while(idx<number)
{
scanf("%f",&temp);
Temp[idx]=temp;
printf("Temp[%d]= %f\n",idx,temp);
idx++;
}

m=1;
for(count=1;count<=(number/5);count++)
{
printf("\n5mins window %d:\n",count);
idx2=0;
while(idx1<5*m)
{
five[idx2]=Temp[idx1];
printf("%f ",five[idx2]);
idx1++;
idx2++;
}
display(idx2,five);
m++;
}
m=1;
idx1=0;
for(count=1;count<=(number/10);count++)
{
printf("\n10mins window %d:\n",count);
while(idx1<10*m)
{
ten[idx1]=Temp[idx1];
printf("%f ",ten[idx1]);
idx1++;
}
display(idx1,ten);
m++;
}

m=1;
idx1=0;
for(count=1;count<=(number/15);count++)
{
printf("\n15mins window %d:\n",count);
while(idx1<15*m)
{
fifteen[idx1]=Temp[idx1];
printf("%f ",fifteen[idx1]);
idx1++;
}
display(idx1,fifteen);
m++;
}
getch();
}

