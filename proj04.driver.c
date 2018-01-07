/*----------------------------------------------------------------------------
  Meryl Mabin
  CSE 320, Fall 2009
  Project #4: Twos Complement Representation
  Driver
----------------------------------------------------------------------------*/

#include <stdio.h>
#include "/user/cse320/Projects/project04.support.h"

/*----------------------------------------------------------------------------
  Function main
----------------------------------------------------------------------------*/

int main()
{
  int flag;

  printf( "*** Case: +324, Base 10 ***\n" );
  int A;
  flag = convert("+324", 10, &A);
  printf( "A:   %d (base 10)\n", A );
  printf( "A:   %x (base 16)\n", A );
  printf( "Flag: %d\n\n", flag );

  printf( "*** Case: -324, Base 10 ***\n" );
  int B;
  flag = convert("-324", 10, &B);
  printf( "B:   %d (base 10)\n", B );
  printf( "B:   %x (base 16)\n", B );
  printf( "Flag: %d\n\n", flag );

  printf( "*** Case: 10011100001010111111010100000111, Base 2 ***\n" );
  int C;
  flag = convert("10011100001010111111010100000111", 2, &C);
  printf( "C:   %d (base 10)\n", C );
  printf( "C:   %x (base 16)\n", C );
  printf( "Flag: %d\n\n", flag );

  printf( "*** Case: Bad input ***\n" );
  int D;
  flag = convert("-2342-235+", 10, &D);
  printf( "Flag: %d\n\n", flag );

  printf( "*** Case: 162, Base 7 ***\n" );
  int E;
  flag = convert("162", 7, &E);
  printf( "E:   %d (base 10)\n", E );
  printf( "E:   %x (base 16)\n", E );
  printf( "Flag: %d\n\n", flag );

  printf( "*** Case: Bad input - base 40 number ***\n" );
  int F;
  flag = convert("2343", 40, &F);
  printf( "Flag: %d\n\n", flag );
}
