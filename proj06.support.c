/*----------------------------------------------------------------------------
  Meryl Mabin
  CSE 320, Fall 2009
  Project #6: The ARC Instruction Set Architecture
  Support
----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "/user/cse320/Projects/project06.support.h"

/*----------------------------------------------------------------------------
  Name:   decode

  Input: - the bit pattern for an ARC machine language instruction
         - a character string

  Purpose: produces the machine language instruction in a human-readable
           character string
----------------------------------------------------------------------------*/
void decode( unsigned N, char* peopleFriendly )
{

  switch ( N>>30 )
  {

    // SETHI/Branch format
    case 0:
      if ( ((N<<7) >>29) == 2 ) // branch format
      {
	// check cond
        switch ((N<<3) >>28)
	{
	  case 1:
	    sprintf( peopleFriendly, "be     PC+%#08x",
			    (((N<<10)>>10) * 4) );
            break;

	  case 5:
	    sprintf( peopleFriendly, "bcs    PC+%#08x",
			    (((N<<10)>>10) * 4) );
	    break;

	  case 6:
	    sprintf( peopleFriendly, "bneg   PC+%08x",
			    (((N<<10)>>10) * 4) );
	    break;

	  case 7:
	    sprintf( peopleFriendly, "bvs    PC+%08x",
			    (((N<<10)>>10) * 4) );
	    break;

	  case 8:
	    sprintf( peopleFriendly, "ba     PC+%08x",
			    (((N<<10)>>10) * 4) );
	    break;

	  default:
	    sprintf( peopleFriendly, "INVALID" );
	    break;
	}
      }
      else if ( ((N<<7) >> 29) == 4 ) // sethi format
      {
        sprintf( peopleFriendly, "sethi  %#08x, %%r%i", ((N<<10)>>10),
			((N<<2) >>27) );
      }
      else sprintf( peopleFriendly, "INVALID" );
      break;


    // CALL format
    case 1:
      if ( (N<<2) >>31 ) // first bit is 1, number is negative
      {
        sprintf( peopleFriendly, "call   PC-%#08x",
			( ((N ^ 0xffffffff) + 1) * 4 ) );
      }
      else // first bit is 0, number is positive
      {
        sprintf( peopleFriendly, "call   PC+%#08x",
			( (N ^ 0xffffffff) * 4 ) );
      }
      break;


    // Arithmetic format
    case 2:
      switch ( (N<<7) >>26 )
      {
	case 16:   // addcc
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
	  {
	    sprintf( peopleFriendly, "addcc  %%r%i, %%r%i, %%r%i",
			    ((N<<13)>>27), ((N<<27)>>27), ((N<<2)>>27) );
	  }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "addcc  %%r%i, %i, %%r%i",
			    ((N<<13)>>27), ((N<<19)>>19), ((N<<2)>>27) );
	  }
	  break;

	case 17:   // andcc
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
          {
	    sprintf( peopleFriendly, "andcc  %%r%i, %%r%i, %%r%i",
			    ((N<<13)>>27), ((N<<27)>>27), ((N<<2)>>27) );
          }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "andcc  %%r%i, %i, %%r%i",
			    ((N<<13)>>27), ((N<<19)>>19), ((N<<2)>>27) );
	  }
	  break;

	case 18:   // orcc
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
          {
	    sprintf( peopleFriendly, "orcc   %%r%i, %%r%i, %%r%i",
			    ((N<<13)>>27), ((N<<27)>>27), ((N<<2)>>27) );
	  }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "orcc   %%r%i, %i, %%r%i",
		            ((N<<13)>>27), ((N<<19)>>19), ((N<<2)>>27) );
	  }
	  break;

	case 22:   // orncc
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
	  {
	    sprintf( peopleFriendly, "orncc  %%r%i, %%r%i, %%r%i",
		            ((N<<13)>>27), ((N<<27)>>27), ((N<<2)>>27) );
	  }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "orncc  %%r%i, %i, %%r%i",
			    ((N<<13)>>27), ((N<<19)>>19), ((N<<2)>>27) );
	  }
	  break;

	case 38:   // srl
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
	  {
	    sprintf( peopleFriendly, "srl    %%r%i, %%r%i, %%r%i",
			    ((N<<13)>>27), ((N<<27)>>27), ((N<<2)>>27) );
	  }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "srl    %%r%i, %i, %%r%i",
			    ((N<<13)>>27), ((N<<19)>>19), ((N<<2)>>27) );
	  }
	  break;

	case 56:   // jmpl
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
	  {
            sprintf( peopleFriendly, "jmpl   %%r%i, %%r%i, %%r%i",
			    ((N<<13)>>27), ((N<<27)>>27), ((N<<2)>>27) );
	  }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "jmpl   %%r%i, %i, %%r%i",
			    ((N<<13)>>27), ((N<<19)>>19), ((N<<2)>>27) );
	  }
	  break;

	default:
	  sprintf( peopleFriendly, "INVALID" );
	  break;
      }
      break;


    // Memory format
    case 3:
      switch ( (N<<7) >> 26 )
      {
	case 0:   // ld
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
	  {
	    sprintf( peopleFriendly, "ld    [%%r%i+%%r%i], %%r%i",
			    ((N<<13)>>27), ((N<<27)>>27), ((N<<2)>>27) );
	  }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "ld    [%%r%i+%i], %%r%i",
			    ((N<<13)>>27), ((N<<19)>>19), ((N<<2)>>27) );
	  }
	  break;

	case 4:   // st
	  if ( ((N<<18) >> 31) == 0 )   // i = 0
	  {
	    sprintf( peopleFriendly, "st    %%r%i, [%%r%i+%%r%i]",
			    ((N<<2)>>27), ((N<<13)>>27), ((N<<27)>>27) );
	  }
	  else   // i = 1
	  {
	    sprintf( peopleFriendly, "st    %%r%i, [%%r%i+%i]",
			    ((N<<2)>>27), ((N<<13)>>27), ((N<<19)>>19) );
	  }
	  break;

	default:
	  sprintf( peopleFriendly, "INVALID" );
	  break;
      }
      break;

    default:
      sprintf( peopleFriendly, "INVALID" );
      break;

  } // end switch

}
