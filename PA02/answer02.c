#include "pa02.h"
#define DIFF 32;
/**
 * Count the number of characters in a null-terminated string 's' 
 * (not counting the null character).
 *
 * Example: my_strlen("foo") should yield 3.
 */
int my_strlen(const char * s)
{
	//Variables
	int i=0;
	int l=0;
	//Executions
	for(i=0; s[i]!='\0';i++)
	{
	 l++;
	}    

	return l;
}

/**
 * Count the number of occurrences of a particular character 'c' in a
 * null-terminated string 's'.
 *
 * Example: my_countchar("foo", 'o') should yield 2.
 */
int my_countchar(const char * s, char c)
{
	//Variables
	int i=0;
	int count=0;
	
	//Executions
	for(i=0; s[i]!='\0'; i++)
	{
	 if( (s[i]) == c)
	 {
	  count= count+1;
	 }
	}
	return count;
}

/**
 * Convert an entire null-terminated string 's' to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that yields
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "foobar";
 * my_strupper(foobar) yields "FOOBAR".
 */
void my_strupper(char * s)
{
	//Variables
	int i = 0;
	
	//Executions
	for(i=0; s[i]!='\0'; i++)
	{
	 if((s[i]>=97) & (s[i]<=122))
	 {
	 s[i]= s[i] - DIFF;
	 }
	}

}

/**
 * Convert an entire null-terminated string 's' to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that yields
 * the lowercase version of a character 'c'.
 *
 * Example: char foobar[10] = "FOOBAR";
 * my_strupper(foobar) yields "foobar".
 */
void my_strlower(char * s)
{
	//Variables
	int i=0;
	//Executables
	for(i=0; s[i]!='\0'; i++)
	{
	 if((s[i]>=65) & (s[i]<=90))
	 {
	  s[i]= s[i] + DIFF;
	 }
	}
}

/**
 * Copy the contents of a null-terminated string 's2' into the memory
 * pointed to by 's1'.  Any existing data in 's1' will be overwritten by
 * the contents of 's2'.  Note: you can assume that there is sufficient
 * memory available in 's1'.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "foo") yields "foo".
 */
void my_strcpy(char * s1, const char * s2)
{
	//Variables
	int i=0;
	int i2=0;
	//Executables
	
	while( s2[i]!='\0')
	{
	 s1[i] = s2[i2];
	 i++;
	 i2++;
	}
        
	s1[i] = '\0';	

}

/**
 * Copy the first 'n' characters of a null-terminated string 's2' into the
 * memory pointed to by 's1'. Any existing data in 's1' will be
 * overwritten by the contents of 's2'.  Note: you can assume that there
 * is sufficient memory available in 's1'.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "foo", 1) yields "f".
 */
void my_strncpy(char * s1, const char * s2, int num)
{
	//Variables
	int i = 0;
	int i2 = 0;
	//Executables
	for(i=0; i< num; i++,i2++)
	{
	 s1[i] = s2[i];
	}
 	
	s1[i] = '\0';
}


/** 
 * Concatenate (append) the contents of a null-terminated string 's2'
 * onto the end of the null-terminated string 's1'.  Note: you can
 * assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar") yields "foobar".
 */
void my_strcat(char * s1, const char * s2) 
{
	//Variables
	
	int i2=0;
	int l1=0;
	int l2=0;
	//Executables
	l1 = my_strlen(s1);
	l2 = my_strlen(s2);
	for(i2=0; s2[i2]!='\0';i2++)
	{
	 s1[i2+l1] = s2[i2];
	}
}

/** 
 * Concatenate (append) the first n characters of a null-terminated
 * string 's2' onto the end of the null-terminated string 's1'.  Note: you
 * can assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar", 1) yields "foob".
 */
void my_strncat(char * s1, const char * s2, int num)
{
	//Variables
	int i1=0;
	int l1=0;
	int l2=0;

	//Executables
	l1 = my_strlen(s1);
	l2 = my_strlen(s2);
	for(i1=0;i1<num ; i1++)
	{
	 s1[i1+l1] = s2[i1];
	}

}

/**
 * Return a pointer to the first occurrence of a null-terminated
 * substring 's2' in a null-terminated string 's1'.  If 's2' does not appear
 * in 's1', the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will yield 0 (NULL).
 * Example(2): my_strstr("foobar", "bar") will yield a pointer to the
 * "bar" portion of the "foobar" argument.
 */

const char *my_strstr(const char * s1, const char * s2)
{
	//Variables
	int count=0;
	int l1=0;
	int l2=0;
	int i1=0;
	int i2=0;
	const char *pointer = NULL;
	int check=0;
	int temporary =0;
	
	
	//Executions
	l1= my_strlen(s2);
	l2= my_strlen(s1);
		
	for(i1=0 ; i1< l1; i1= i1+1)
	{
	 if(s1[i1] == s2[i2])
	 {
	  pointer = &s1[i1];
	  temporary = i1;
	  count=0;
	  i2=0;
	  for(check = i1; check< ( l2 + temporary); check = check+1)
	  {
	   if(s1[check] == s2[i2])
	   {
	    i2= i2+1;
	    count = count +1;
           }
	   if( count == l2)
	   {
	    i1 = l1;
	   }
	  }
	 }
	}
	if(count == l2)
        {
         return pointer;
        }
	return NULL;
}



/**
 * Insert a null-terminated string s2 in the null-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "foo";
 * my_strinsert(foo, "bar", 0) yields "barfoo".
 * 
 * Example(2): char foo[10] = "foo";
 * my_strinsert(foo, "bar", 100) yields "foobar".
 */
void my_strinsert(char *s1, const char *s2, int pos)
{
	//Variables
	int i1=0;
	int i2=0;
	int l1=0;
	int l2=0;
	int position=0; 
	//Executions
	position=pos;
	l1= my_strlen(s1);
	l2= my_strlen(s2);
	
	if((pos > l1) || (pos == l1))
	{
	 strcat(s1,s2);
	}
	
	else if( pos < l1)
	{
	 
	 for(i1= l1 + l2; i1>=(pos+l2);i1--)
         {
          s1[i1-1] = s1[i1-l2-1];
         }

	 for(i1= pos; i1<(l2+pos); i1=i1+1)
         {
          s1[i1] = s2[i2];
          i2 = i2+1;
         }

	 s1[l2+l1] = '\0';
	}
	
	
}

/**
 * Delete a portion of the null-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "foobar";
 * my_strdelete(foo, 3, 3) yields "foo".
 *
 * Example(2): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 3) yields "bar".
 * 
 * Example(3): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 34) yields "".
 * 
 * Example(4): char foo[10] = "foobar";
 * my_strdelete(foo, 2, 30) yields "fo";
 */
void my_strdelete(char *s, int pos, int length)
{
	//Variables
	int i1=0;
	int l1=0;

	//Executions
	l1= strlen(s);


	if( length > l1)
	{


	 if (pos!= 0)
	 {


	  s[pos] = '\0';
  	 }  


	 else if ( pos == 0)
	 {


	  s[pos] = '\0';
	 }
	}
	


	else if ( length < l1)
	{
	 
	 i1 = length + pos;
	 while(i1 < l1)
	 {	
	  
	  s[ pos ] = s[i1];
	  pos = pos +1;

	  i1++;
	 }

	 s[l1-length] = '\0';
	}


}



