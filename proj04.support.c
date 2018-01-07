/*----------------------------------------------------------------------------
  Meryl Mabin
  CSE 320, Fall 2009
  Project #4: Twos Complement Representation
  Support
----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/user/cse320/Projects/project04.support.h"

int convert( const char sequence[], int base, int* A )
{
  int i = 0, sum = 0, sign = 1, char_to_int, num_addends = 0;

  if ( (base<2) || (base>36) ) return 0;

  while ( sequence[i] != '\0' )
  {
    int is_addend = 0;
    if ( sequence[i] == '+' )
    {
      if ( num_addends == 0 )
      {
        sign = 1;
      }
      else return 0;
    }
    else if ( sequence[i] == '-'  )
    {
      if ( num_addends == 0 )
      {
	sign = -1;
      }
      else return 0;
    }
    else if ( (sequence[i] >= '0') && (sequence[i] <= '9') )
    {
      char_to_int = sequence[i] - '0';
      is_addend = 1;
//      printf( "%d\n", char_to_int );
    }
    else if ( (sequence[i] >= 'A') && (sequence[i] <= 'Z') )
    {
      char_to_int = sequence[i] - '0' - 10;
//      printf( "%d\n", char_to_int );
      is_addend = 1;
    }
    else if ( (sequence[i] >= 'a') && (sequence[i] <= 'z') )
    {
      char_to_int = sequence[i] - '0' - 10 - 32;
//      printf( "%d\n", char_to_int );
      is_addend = 1;
    }
    else return 0;

    if ( is_addend )
    {
      sum *= base;
      sum += char_to_int;
      num_addends ++;
    }
    i++;
  }

  sum *= sign;

  *A = sum;
  return 1;
}
