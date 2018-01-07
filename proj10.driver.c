/*----------------------------------------------------------------------------
  Meryl Mabin
  CSE 320, Fall 2009
  Project # 10: Floating Point Operations
  Driver
----------------------------------------------------------------------------*/

#include <stdio.h>
#include "/user/cse320/Projects/project10.support.h"
#define M_PI 3.141159265358979323846

/*----------------------------------------------------------------------------
  Function main
----------------------------------------------------------------------------*/

/*double absolute( double );
double modulo( double, double );
double factorial( unsigned N );
double power( double X, unsigned N );
double cosine( double X );*/

int main()
{
  /* For absolute */
  double dblVec[] = { 4, -4, 0, -0, 5, 7 };

  /* For modulo*/
  double mod1Vec[] = { 4, -4, 2.4, 7.1, 10, 16, -5, 2, 12, 20, 20,\
 			-20, -20 };
  double mod2Vec[] = { 4, 4, 6, 3, 10, 2, -5, 0, M_PI, 3, -3, 3, -3 };

  /* For factorial */
  unsigned intVec[] = { 4, 0, 1000, 6, 2 };

  /* For power */
  double pow1Vec[] = { 4, -4, 2.4, 7.1, 10, 16, 5, 2, 2, 8 };
  unsigned pow2Vec[] = { 4, 4, 6, 3, 10, 2, 5, 0, 3, 1000 };

  /* For cosine */
  double cosVec[] = { 2, 4, 0, 4*M_PI, -78.5, 789, \
	  12 };

  unsigned dblSize = sizeof( dblVec ) / sizeof( dblVec[0] );
  unsigned intSize = sizeof( intVec ) / sizeof( intVec[0] );
  unsigned mod1Size = sizeof( mod1Vec ) / sizeof( mod1Vec[0] );
  unsigned pow1Size = sizeof( pow1Vec ) / sizeof( pow1Vec[0] );
  unsigned cosSize = sizeof( cosVec ) / sizeof( cosVec[0] );

  unsigned i;

  printf("\n/*** Absolute ***/\n");

  for( i=0; i<dblSize; i++ )
  {
    printf( "Absolute value of %f: %f\n", dblVec[i], absolute( dblVec[i]) );
  }

  printf("\n/*** Modulo ***/\n");

  for( i=0; i<mod1Size; i++ )
  {
    printf( "%f \%%  %f: %f\n", mod1Vec[i], mod2Vec[i], \
		    modulo( mod1Vec[i], mod2Vec[i] ) );
  }


  printf("\n/*** Factorial ***/\n");

  for( i=0; i<intSize; i++ )
  {
    printf( "Factorial of %d: %f\n", intVec[i], factorial( intVec[i]) );
  }

  printf("\n/*** Power ***/\n");

  for( i=0; i<pow1Size; i++ )
  {
    printf( "%f ^ %d: %f\n", pow1Vec[i], pow2Vec[i],\
	 		power( pow1Vec[i], pow2Vec[i] ) );
  }

  printf("\n/*** Cosine ***/\n");

  for( i=0; i<cosSize; i++ )
  {
    printf( "cos(%f): %f\n", cosVec[i], cosine( cosVec[i] ) );
  }
}
