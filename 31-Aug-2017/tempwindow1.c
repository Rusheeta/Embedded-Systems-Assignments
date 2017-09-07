#include<stdio.h>
#include<stdlib.h>

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
//printf("j=%d\n",j);
for(j=0;j<n;j++)
{
if(B[j]<=min)
min=B[j];
}
return min;
}

float Average(float C[100],int n) // to calculate average of the temperatures of each window
{
int k=0;
float t=0;
float Avg;
while(k<n)
{
t=t+C[k];
k++;
}
Avg=t/n;
return Avg;
}

float display(float D[100],int a) //to display max, min and average of temperatures for each window
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

/*int window(float A[60],float B[100],int a)
{
int b=0,c;
printf("%d min window %d:\n",a,a/5);
	c=0;
	while(b<a)
	{
	  B[c]=A[b];
	  printf("%f ",B[c]);
	  c++;
	  b++;
	  }
	display(B,c);
	  	 	
	  	
}*/

int windowType(float T[100],int d,int b)
	{
float A[100];
int a=0;

for(a=0,b=0+b;a<d,b<d;a++,b++)
{
	A[a]=T[b];
	
	printf("%f ",A[a]);	
	
}

display(A,a);
return b;
}





void main()
{
int data=0,data1=0,data2=0,data3=0,data4=0;
float temp_data;
float Temp[100]={ };
float Temp_five[5]={ };
float Temp_ten[10]={ };
float Temp_fifteen[15]={ };

while(data<60)
{
scanf("%f",&temp_data);
Temp[data]=temp_data;
printf("Temp[%d]=%f\n",data,Temp[data]);
data++;
data1=data;

if(data1%5==0)
{

	printf("5min window:\n");

data2=windowType(Temp,data1,data2);
}

if(data1%30==0)
{
	
printf("30min window:\n");
	
data3=windowType(Temp,data1,data3);	
}
if(data1%60==0)
{
	printf("60min window:\n");

data4=windowType(Temp,data1,data4);	
}
}

}
