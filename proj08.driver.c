/*****************************************************************************
  Meryl Mabin
  Project 08 - SPARC Subprograms
  Driver Module
*****************************************************************************/

#include <stdio.h>
#include "/user/cse320/Projects/project08.support.h"

int main()
{
  int bob;

  printf(" *** Testing negate ***\n");

  bob = negate( -29 );
  printf( "-29:   %d\n", bob );
  bob = negate( 10 );
  printf( "10:    %d\n", bob );
  bob = negate( 0 );
  printf( "0:     %d\n", bob );



  printf( "\n*** Testing absolute ***\n" );

  bob = absolute( -29 );
  printf( "-29:   %d\n", bob );
  bob = absolute( 10 );
  printf( "10:    %d\n", bob );
  bob = absolute( 0 );
  printf( "0:     %d\n", bob );



  printf( "\n*** Testing power ***\n" );

  bob = power( 2, 3 );
  printf( "2^ 3:   %d\n", bob );
  bob = power( 3, -10 );
  printf( "3^ -10: %d\n", bob );
  bob = power( 0, 0 );
  printf( "0^ 0:   %d\n", bob );
  bob = power( 3, 0 );
  printf( "3^ 0:   %d\n", bob );
  bob = power( 0, 4 );
  printf( "0^ 4:   %d\n", bob );
  bob = power( -7, -6 );
  printf( "-7^ -7: %d\n", bob );
  bob = power( 9, 99 );
  printf( "9^ 99:  %d\n", bob );
  bob = power( -3, 0 );
  printf( "-3^ 0:  %d\n", bob );




  printf( "\n*** Testing factorial ***\n" );

  bob = factorial( 5 );
  printf( "5!:   %d\n", bob );
  bob = factorial( 0 );
  printf( "0!:   %d\n", bob );
  bob = factorial( -7 );
  printf( "-7!:  %d\n", bob );
  bob = factorial( 800 );
  printf( "800!: %d\n", bob );

  printf( "\n*** Testing sum ***\n" );

  bob = sum( 3, 4 );
  printf( "3+...+4:   %d\n", bob );
  bob = sum( 1, 9 );
  printf( "1+...+9:   %d\n", bob );
  bob = sum( 5, 2 );
  printf( "5+...+2:   %d\n", bob );
  bob = sum( 1, 100000000);
  printf( "1+...+100000000:   %d\n", bob );
  bob = sum( -3, -5 );
  printf( "-3+...+-5:   %d\n", bob );
  bob = sum( -5, -3 );
  printf( "-5+...+-3:   %d\n", bob );
  bob = sum( -2, 4 );
  printf( "-2+...+4:    %d\n", bob );

  printf( "\n*** Testing ceiling ***\n" );

  bob = ceiling( 3.2 );
  printf( "3.2:   %d\n", bob );
  bob = ceiling( 0.0 );
  printf( "0.0:   %d\n", bob );
  bob = ceiling( -3.2 );
  printf( "-3.2:  %d\n", bob );

  printf( "\n*** Testing floor ***\n" );

  bob = flooring( 3.2 );
  printf( "3.2:   %d\n", bob );
  bob = flooring( 0.0 );
  printf( "0.0:   %d\n", bob );
  bob = flooring( -3.2 );
  printf( "-3.2:  %d\n", bob );
}
