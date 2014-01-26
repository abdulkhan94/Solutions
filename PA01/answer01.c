#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
	//Variables
	int index=0;
	int sum=0;
	
	//Executions
	for(index=0;index<len; index++)
	{
	 sum=sum+array[index];
	}
	
	if(sum!=0)
	{	
	 return sum;
	}
	else

	return 0;
}

int arrayCountNegative(int * array, int len)
{
	//Variables
	int i=0;
	int c=0;
	
	//Executions
	for(i=0; i<len; i=i+1)
	{
	 if(array[i]<0);
	 {
	  c=c+1;
	 }
	}
	return c;
}

int arrayIsIncreasing(int * array, int len)
{
	//Variables
	int index=0;	
	int count=0;
	int f=0;
    	int a=1;
	//Executions
	if(a==1)
	{
	 a++;
	}
	
	if(len==0)
	{
	 return 1;
	}

	for(index=0;index<len-1;index=index+1)
	{
	 for(count=index+1;count<len;count=count+1)
	 {
	  if(array[index]<=array[count])
	  {
	   f=f*1;
	  }
	  else
	  {
	   f=f*0;
	  }
	 }
	}
	
	return f;

}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
	//Variables
	int i;
	int t=0;
	int s;

	//Executions
	for(i=0;i<len;i++)
	{
	 if(needle==haystack[i])
	 {
	  t=1;

	  s=i;
	 }
	}

	if(t!=0)
	{
	 return s;
	}
	
	 return -1;
	
	 
}

int arrayFindSmallest(int * array, int len)
{
    return 0;
}
