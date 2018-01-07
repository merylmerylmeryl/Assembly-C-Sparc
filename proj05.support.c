/*----------------------------------------------------------------------------
  Meryl Mabin
  CSE 320, Fall 2009
  Project #5: Floating Point Representation
  Support
----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "/user/cse320/Projects/project05.support.h"

/*----------------------------------------------------------------------------
  Name:     is_negative
  Purpose:  determines whether or not the input is negative -
            true if first bit is 1
----------------------------------------------------------------------------*/
int is_negative( double D )
{
  union dp_item B;
  B.drep = D;

  if (B.irep>>63) return 1;
  else return 0;
}


/*----------------------------------------------------------------------------
  Name:     is_zero
  Purpose:  determines whether or not the input is zero -
            true if exponent is all 0's, fraction is all 0's
----------------------------------------------------------------------------*/
int is_zero( double D )
{
  union dp_item B;
  B.drep = D;

  if (!(B.irep<<1)) return 1;
  else return 0;
}


/*----------------------------------------------------------------------------
  Name:     is_denormal
  Purpose:  determines whether or not the input is denormal -
            true if exponent is all 0's, fraction is NOT all 0's
----------------------------------------------------------------------------*/
int is_denormal( double D )
{
  union dp_item B;
  B.drep = D;

  if ( (B.irep<<1) >>53) return 0;

  if ( (B.irep<<12) >>12) return 1;
  else return 0;
}


/*----------------------------------------------------------------------------
  Name:     is_nan
  Purpose:  determines whether or not the input is NaN -
            true if exponent is all 1's, fraction is NOT all 0's
----------------------------------------------------------------------------*/
int is_nan( double D )
{
  union dp_item B;
  B.drep = D;

  if ( (~(B.irep)<<1) >>53) return 0;

  if ( (B.irep<<12) >>12) return 1;
  else return 0;
}


/*----------------------------------------------------------------------------
  Name:     is_infinite
  Purpose:  determines whether or not the input is infinite -
            true if exponent is all 1's, fraction is all 0's
----------------------------------------------------------------------------*/
int is_infinite( double D )
{
  union dp_item B;
  B.drep = D;

  if ( (~(B.irep)<<1) >>53) return 0;

  if ( (B.irep<<12) >>12) return 0;
  else return 1;
}


/*----------------------------------------------------------------------------
  Name:     is_finite
  Purpose:  determines whether or not the input is finite -
            true if exponent consists of 0's and 1's
----------------------------------------------------------------------------*/
int is_finite( double D )
{
  union dp_item B;
  B.drep = D;

  if (( (B.irep<<1) >>53) && ( (~(B.irep)<<1) >> 53)) return 1;
  else return 0;
}


/*----------------------------------------------------------------------------
  Name:     negate
  Purpose:  return negation of input -
            make the first bit its opposite
----------------------------------------------------------------------------*/
double negate( double D )
{
  union dp_item B;
  B.drep = D;

  B.irep = B.irep ^ 0x8000000000000000ULL;
  return B.drep;
}


/*----------------------------------------------------------------------------
  Name:     absolute
  Purpose:  return absolute value of input -
            make the first bit 0
----------------------------------------------------------------------------*/
double absolute( double D )
{
  union dp_item B;
  B.drep = D;

  B.irep = B.irep & 0x7FFFFFFFFFFFFFFFULL;
  return B.drep;
}


/*----------------------------------------------------------------------------
  Name:     display
  Purpose:  display fields of input
----------------------------------------------------------------------------*/
void display( double D )
{
  int I, C;
  union dp_item B;
  B.drep = D;

  // Print the number in binary
  printf( "Decimal:     %16.8lf\n", B.drep);
  printf( "Hexadecimal: %016llx\n", B.irep);

  // Print the biased exponent in hexadecimal and decimal
  printf( "Biased exponent:  " );

  for (I=62; I>=52; I--)
  {
    C = ((B.irep >> I) & 0x0001) | 0x30;

    printf( "%c", C );
  }
  printf( "\n" );

  // Print the true exponent in hexadecimal and decimal


  // Print the significand in hexadecimal


  // Print the fractional part of the significand in hexadecimal


  // Print the classification of the floating point value
  if ( is_negative(D) ) printf( "Negative\n" );
  if ( is_zero(D) ) printf( "Zero\n" );
  if ( is_denormal(D) ) printf( "Denormal\n" );
  if ( is_nan(D) ) printf( "NaN\n" );
  if ( is_infinite(D) ) printf( "Infinite\n" );
  if ( is_finite(D) ) printf( "Finite\n" );
  printf("\n");
}
