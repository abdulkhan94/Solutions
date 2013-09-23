/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>

void parting(int, int*, int);
void increasing(int*, int, int);
void print(int, int*);
void decreasing(int*, int, int);
void odd(int, int*, int);
void even(int, int*, int);
void both(int, int*, int);
void prime(int, int*, int);
/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */


void partitionAll(int value)
{
  printf("partitionAll %d\n", value);
  //Local Variables
  int i=0;
  int* arra = malloc(sizeof(int)*value);
  
  //Executable Statements
  i++;
  
  parting(value,arra,0);
  free(arra);
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionIncreasing(int value)
{
  printf("partitionIncreasing %d\n", value);
  //Variables
  int *buff=malloc(value *sizeof(int));
  //Executions
  increasing(buff, 0 ,value);
  free(buff);
  
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionDecreasing(int value)
{
  	printf("partitionDecreasing %d\n", value);
  	//Variables
  	int *arra = malloc(value*sizeof(int));
   	decreasing(arra,0, value);
	free(arra);

}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  //Variables
  int*arra= malloc( value * sizeof(int));
  //Executions
  odd(0, arra, value);
  free(arra);
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);
  //Variables
  int*arra = malloc(value * sizeof(int));
  even(0,arra,value);
  free(arra);
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  //Variables
  int*arra= malloc(value * sizeof(int));
  both(0,arra,value);
  free(arra);
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);
  //Variables
  int *arra= malloc(value*sizeof(int));
  //Executions
  prime(0, arra, value);
  free(arra);

}



void parting(int a, int *arra, int counter)
{
  //Variables
  int i=0;
  int value= 0;
  
  //Executable Statements
  if(a != 0)
  {
   value = value +1;
  }
  if( a == 0)
  {
   print(counter, arra);
   return;
  }

  for(i = 1; i<= a; i = i+1)
  {
   arra[counter] = i;
   parting( a - i, arra,counter+1);
  }
}

void increasing(int *arra, int position, int count)
{
  //Variables
  int i = 1;
  int a = 0;
  //Executions
  if( count >= 0 )
    {
      a = a+1;
    }
  if( count <= 0)
    {
      print(position, arra);
      return;
    }
  
  while(i <= count)
    {
      if((position == 0) || (i > arra[position-1]))
	{
	  arra[position] = i;
	  increasing(arra, position+1 , count-i);
	}
      i=i+1;
    }

}

void print(int last, int *arra)
{
  //Local Variables
  int i = 0;
  
  //Executions
  printf("= ");
  for( i =0; i < last-1; i = i+1)
    {
      printf("%d + ", arra[i]);
    }
  printf("%d\n",arra[last - 1]);
}

void decreasing(int *arra, int position, int count)
{
	//Variables
	int i = 1;
	int a=0;
	

	//Executions
	if( count >= 0 )
    	{
      	 a = a+1;
    	}
  	if( count <= 0)
    	{
      	 print(position, arra);
      	 return;
    	}	

  	while(i <= count)
    	{
      	 if((position == 0) || (i <  arra[position-1]))
         {
          arra[position] = i;
          decreasing(arra, position+1 , count-i);
         }
	i=i+1;
        } 

}
	

void odd(int position, int*arra, int count)
{
 //Variables
 int i=1;
 int a=0;

 //Executions
 if(count >= 0 )
 {
  a= a+1;
 }
 if(count <= 0)
 {
  print(position, arra);
  return;
 }

 while(i<=count)
 {
  if(i%1 == 1)
  {
   a=0;
  }
  if(i%2 == 1)
  {
   arra[position] = i;
   odd(position+1, arra, count -i);
  }
 i=i+1;
 }
}

void even(int position, int *arra, int count)
{
 //Variables
 int i=1;
 int a=0;

 //Executions
 if(count >= 0 )
 {
  a= a+1;
 }
 if(count <= 0)
 {
  print(position, arra);
  return;
 }
 
 while(i<=count)
 {
  if(i%1 == 1)
  {
   a=0;
  }
  if(i%2 == 0)
  {
   arra[position] = i;
   even(position+1, arra, count -i);
  }
 i = i+1;
 }
}


void both(int position, int *arra, int count)
{
 //Variables
 int i=1;
 int a=0;

 //Executions
 if(count >= 0 )
 {
  a= a+1;
 }
 if(count <= 0)
 {
  print(position, arra);
  return;
 }
 
 while(i<= count)
 {
  if((i%2 ==0 && arra[position-1]%2 == 1))
  {
   arra[position]= i;
   both(position+1, arra, count - i);
  }

  if((i%2 == 1 && arra[position-1]%2 ==0))
  {
   arra[position] = i;
   both(position+1, arra, count - i);
  }

  i = i+1;
 }
}
  
void prime(int position, int *arra, int count)
{
 //Variables
 int i=1;
 int a=0;
 int j=2;
 int l=0;
 //Executions
 if(count >= 0 )
 {
  l= l+1;
 }
 
 if(count <= 0)
 {
  print(position, arra);
  return;
 } 
 

while(i <= count)
 {
  
  if( i > 2)
  {
   j=2; 
   while(j<i)
   {
     if( i% j==0)
       {
         a= a+1;
       }
    j++;
   }
  }//end of if
  if((a==0) & (i > 1 ))
   {
   arra[position] = i;
   prime(position+1, arra,count - i);
   }
  i++;
 }
}
