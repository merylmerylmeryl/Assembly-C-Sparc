/*----------------------------------------------------------------------------
  Meryl Mabin
  CSE 320, Fall 2009
  Project #5: Floating Point Representation
  Driver
----------------------------------------------------------------------------*/

#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"

/*----------------------------------------------------------------------------
  Function main
----------------------------------------------------------------------------*/

int main()
{
  int I, N;
  double A[] = {10.0, -10.0, 3.14159, -3.14159, 0.0, -0.0, 4.940656458412465e-324,
	  5.00e2342};

  N = sizeof( A ) / sizeof( A[0] );

  for ( I=0; I<N; I++ )
  {
    display(A[I]);
  }

  printf( "*** Function negate***\n\n" );
  for ( I=0; I<N; I++ )
  {
    printf( "Before:\n-----\n" );
    display(A[I]);
    printf( "After:\n-----\n" );
    display(negate(A[I]));
  }

  printf( "*** Function absolute***\n\n" );
  for ( I=0; I<N; I++ )
  {
    printf( "Before:\n-----\n" );
    display(A[I]);
    printf( "After:\n-----\n" );
    display(absolute(A[I]));
  }
}
