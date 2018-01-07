/*----------------------------------------------------------------------------
  Meryl Mabin
  CSE 320, Fall 2009
  Project #6: The ARC Instruction Set Architecture
  Driver
----------------------------------------------------------------------------*/

#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

/*----------------------------------------------------------------------------
  Function main
----------------------------------------------------------------------------*/

int main()
{
  char destination[40];

  printf( "          *** sethi ***\n" );
  decode( 0x03304F15, destination );
  printf( "0x03304F15:  %s\n", destination);
  decode( 0x03304235, destination );
  printf( "0x03304235:  %s\n", destination);
  decode( 0x37372849, destination );
  printf( "0x37372849:  %s\n", destination);
  decode( 0x21075BBB, destination );
  printf( "0x21075BBB:  %s\n", destination);
  decode( 0x151ABEF2, destination );
  printf( "0x151ABEF2:  %s\n", destination);
  decode( 0x3700000D, destination );
  printf( "0x3700000D:  %s\n\n\n", destination);


  printf( "          *** be ***\n" );
  decode( 0x02800005, destination );
  printf( "0x02800005:  %s\n", destination);
  decode( 0x028DACEF, destination );
  printf( "0x028DACEF:  %s\n", destination);
  decode( 0x02A32523, destination );
  printf( "0x02A32523:  %s\n", destination);
  decode( 0x02B2035E, destination );
  printf( "0x02B2035E:  %s\n", destination);
  decode( 0x028203BC, destination );
  printf( "0x028203BC:  %s\n\n\n", destination);

  printf( "          *** bneg ***\n" );
  decode( 0x0C888888, destination );
  printf( "0x0C888888:  %s\n", destination);
  decode( 0x028DACEF, destination );
  printf( "0x028DACEF:  %s\n", destination);
  decode( 0x02A32523, destination );
  printf( "0x02A32523:  %s\n", destination);
  decode( 0x02B2035E, destination );
  printf( "0x02B2035E:  %s\n", destination);
  decode( 0x028203BC, destination );
  printf( "0x028203BC:  %s\n\n\n", destination);




  printf( "          *** andcc ***\n" );
  decode( 0x86884002, destination );
  printf( "0x86884002:  %s\n", destination);
  decode( 0xAC880006, destination );
  printf( "0xAC880006:  %s\n", destination);
  decode( 0xB888000A, destination );
  printf( "0xB888000A:  %s\n", destination);
  decode( 0x908FC003, destination );
  printf( "0x908FC003:  %s\n", destination);
  decode( 0x908FF67A, destination );
  printf( "0x908FF67A:  %s\n\n\n", destination);


  printf( "          *** call ***\n" );
  decode( 0x7FFFFFCE, destination );
  printf( "0x7FFFFFCE:  %s\n", destination);
  decode( 0x7235AC22, destination );
  printf( "0x7235AC22:  %s\n", destination);
  decode( 0x47205739, destination );
  printf( "0x47205739:  %s\n", destination);
  decode( 0x4C8A2357, destination );
  printf( "0x4C8A2357:  %s\n", destination);
  decode( 0x528583DA, destination );
  printf( "0x528583DA:  %s\n\n\n", destination);


  printf( "          *** orcc ***\n" );
  decode( 0x82906001, destination );
  printf( "0x82906001:  %s\n", destination);
  decode( 0xB0970008, destination );
  printf( "0xB0970008:  %s\n", destination);
  decode( 0xAC900002, destination );
  printf( "0xAC900002:  %s\n", destination);
  decode( 0x8092E004, destination );
  printf( "0x8092E004:  %s\n\n\n", destination);


  printf( "          *** INVALID ***\n" );
  decode( 0x00000000, destination );
  printf( "0x00000000:  %s\n", destination);
  decode( 0x03563957, destination );
  printf( "0x03563957:  %s\n", destination);
  decode( 0xFFFFFFFF, destination );
  printf( "0xFFFFFFFF:  %s\n", destination);
  decode( 0x12345678, destination );
  printf( "0x12345678:  %s\n", destination);
  decode( 0x01832935, destination );
  printf( "0x01832935:  %s\n\n\n", destination);


  printf( "          *** ld ***\n" );
  decode( 0xC200E810, destination );
  printf( "0xC200E810:  %s\n", destination);


  decode( 0xC2002810, destination );
  printf( "0xC2002810:  %s\n\n\n", destination);


  printf( "          *** st ***\n" );
  decode( 0xC2214007, destination );
  printf( "0xC2214007:  %s\n\n\n", destination);


}
