#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"

int intComp(const void*, const void*);
int stringComp(const void*, const void*);
/*
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numInteger: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fscanf
 *
 * You do NOT know how many integers are in the file until you have
 * read it. Once you know how many integers there are, you can modify
 * the "numberOfIntegers" variable. (Note that this is a pointer, not
 * an integer) You must allocate memory to store the integers.
 * 
 * Once memory is allocated to store the integers, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read integeres is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readInteger(char * filename, int * numInteger)
{
  //Variables
  FILE *f= NULL;
  int *arra= NULL;
  int count=0;
  int mem=0;
  int i=0;
	
  //Executions
  f= fopen(filename,"r");
  if(f != NULL)
    {
      while(fscanf(f,"%d",&mem)!= EOF)
	{
 	  count = count +1;
	}
      *numInteger = count;

      arra = malloc(sizeof(int)*(*numInteger));

      fseek(f,0,SEEK_SET);
      while( i < *numInteger )
	{
	  fscanf(f,"%d",&arra[i]);
	  i = i+1;
	}
      fclose(f);
    }
  return arra;
}

/* ----------------------------------------------- */

/*
 * Read a file of strings. This is similar to readInteger. However,
 * each string is an array of characters. The function needs to
 * allocate memory for an array of strings, i.e., array of arrays of
 * characters. In other words, this is a two-dimensional array (thus,
 * char **).
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of strings (one
 * per line)
 * 
 * numString: pointer to store the number of strings in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of strings from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fgets. 
 * 
 * Remember that an array of strings is a two-dimensional array of
 * characters
 *
 * You do NOT know how many strings are in the file until you have
 * read it. Once you know how many strings there are, you can modify
 * the "numberOfStrings" variable. (Note that this is a pointer, not
 * an string) You must allocate memory to store the strings.
 * 
 * Once memory is allocated to store the strings, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read stringes is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of strings in the file.  For example, if
 * you write this
 *
 * char array[10000];
 * 
 *
 */

char * * readString(char * filename, int * numString)
{
  FILE *f= NULL;
  char buf[MAXIMUM_LENGTH];
  char **sent= NULL;
  int i=0;
  int count=0;

  //Executions
  f= fopen(filename,"r");
	
  if(f != NULL)
    {
      while(fgets(buf, MAXIMUM_LENGTH, f) != NULL)
	{
	  count = count+1;
	}
	
      *numString = count;
      sent = malloc(sizeof(char*) * (*numString));
      fseek(f,0, SEEK_SET);	
      for(i=0; fgets(buf, MAXIMUM_LENGTH,f)!= NULL; i = i +1)
	{
	  sent[i] = malloc(sizeof(char) * (strlen(buf) + 1));
	  strcpy(sent[i], buf);
	}
      fclose(f);
    }
  return sent;

}

/* ----------------------------------------------- */
/*
 * print an array of integers, one integer per line
 */
void printInteger(int * arrInteger, int numInteger)
{
  int i =0;
	
  //Executions
  while( i < numInteger)
    {
      printf("%d",arrInteger[i]);
      printf("\n");
      i = i+1;
    }
}

/* ----------------------------------------------- */
/*
 * print an array of strings, one string per line
 *
 * Hint: printf("%s" ... can print a string
 */
void printString(char * * arrString, int numString)
{
  int i = 0;
  //Executions
  for(i = 0; i< numString; i = i+1)
    {
      printf("%s", arrString[i]);
    }
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of integers
 */
void freeInteger(int * arrInteger, int numInteger)
{
  free(arrInteger);
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of strings
 *
 * Hint: an array of strings is a two-dimensional array of characters
 */
void freeString(char * * arrString, int numString)
{
  int i =0;
  //Executions
  for(i=0; i <numString; i = i+1)
    {
      free(arrString[i]);
    }
  free(arrString);

}

/* ----------------------------------------------- */
/*
 * Write integers to a file, one integer per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrInteger: an array of integers
 * numInteger: the number of integers 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %d
 *
 */

int saveInteger(char * filename, int * arrInteger, int numInteger)
{

  int i=0;

  FILE *f = NULL;

  //Executions

  f= fopen(filename, "w");

  if(f != NULL)
    {

      while( i< numInteger)
	{

	  fprintf(f,"%d\n", arrInteger[i]);

	  i = i+1;
	}

      fclose(f);

      return 1;
    }
  return 0;
}

/* ----------------------------------------------- */
/*
 * Write strings to a file, one string per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrString: an array of strings
 * numString: the number of strings 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %s
 *
 */

int saveString(char * filename, char * * arrString, int numString)
{
  //Variables
  int i =0;

  int length = 0;

  FILE *f=NULL;

  //Executions

  f= fopen(filename, "w");

  if( f!= NULL)
    {
      while( i < numString)
	{
	  fprintf(f,"%s", arrString[i]);

	  length = strlen(arrString[i]);


	  if(length == 0 || arrString[i][length-1] != '\n')
	    {

	      fprintf(f,"%s","\n");
	    }

	  i = i+1;
	}
      fclose(f);
      return 1;

    }
  return 0;
}

/* ----------------------------------------------- */
/*
* sort an arry of integers by calling the built-in qsort function in
* the C library.  You need to provide the comparison function. Please
* read the Linux manual about qsort
*
*/

void sortInteger(int * arrInteger, int numInteger)
{
  qsort(&arrInteger[0],numInteger, sizeof(int), intComp);

}


/* ----------------------------------------------- */
     /*
* sort an arry of strings by calling the built-in qsort function in
* the C library.  You need to provide the comparison function. Please
* read the Linux manual about qsort
*
* Hint: use strcmp in the comparison function
*
*/

void sortString(char * * arrString, int numString)
{
  qsort(&arrString[0], numString, sizeof(char*), stringComp);
}


int intComp(const void* pointer1, const void* pointer2)
{
 
  //Variables

  int * point1 = (int*)pointer1;

  int value1 = * point1;

  int * point2 = (int*)pointer2;

  int value2 = * point2;

  //Executions
  if(value1 == value2)
    {
      return 0;
    }
  if( value1<value2)
    {
      return -1;
    }
  return 1;
}

int stringComp( const void * pointer1, const void *pointer2)
{
  char ** point1 = (char**)pointer1;

  char * value1= *point1;

  char ** point2 = (char**)pointer2;

  char * value2= *point2;

  return strcmp(value1,value2);
}
