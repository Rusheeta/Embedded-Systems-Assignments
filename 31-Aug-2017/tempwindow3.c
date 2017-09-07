#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double * simulateTempSensor()
{
int flag=0;
FILE *ptr;
double current_temp=0;
static double val[100]={};
char fileName[]="values.txt";
double retVal;
printf("values in the file: %s\n",fileName);
ptr=fopen(fileName,"r");
if(ptr!=NULL)
{
while(!feof (ptr))
{	
retVal=fscanf(ptr,"%lf",&val[flag]);
flag++;
}	
}
return val;
fclose(fileName);
	
}

double Max(double A[100],int n) //to calculate min of temperatures of each window
{
int i=0;
double max;
max=A[0];
while(i<n)
{
if(A[i]>=max)
max=A[i];
i++;
}
return max;
}

double Min(double B[100],int n) //to calculate min of temperatures of each window
{
int j=0;
double min=0;
min=B[0];
for(j=0;j<n;j++)
{
if(B[j]<=min)
min=B[j];
}
return min;
}

double Average(double C[100],int n) // to calculate average of the temperatures of each window
{
int k=0;
double t=0;
double Avg;
while(k<n)
{
t=t+C[k];
k++;
}
Avg=t/n;
return Avg;
}

double display(double D[100],int a) //to display max, min and average of temperatures for each window
{
double max=0,min=0,avg=0;
max=Max(D,a);
min=Min(D,a);
avg=Average(D,a);
printf("\nMaximum temperature for this window is %f\n",max);
printf("\nMinimum temperature for this window is %f\n",min);
printf("\nAverage is %f\n",avg);
return max,min,avg;
}


int windowType(double T[100],int d,int b)
	{
double A[100];
int a=0;

for(a=0,b=0+b;a<d,b<d;a++,b++)
{
	A[a]=T[b];
	
	printf("%f ",A[a]);	
	
}

display(A,a);
return b;
}





double main()
{
int data=0,data1=0,data2=0,data3=0,data4=0,tempdata;
double Temp[100]={ };
double Temp_five[5]={ };
double Temp_ten[10]={ };
double Temp_fifteen[15]={ };
double *random;
random=simulateTempSensor();

while(data<60)
{


Temp[data]=*(random+data);
printf("Temp[%d]=%lf\n",data,*(random+data));
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
