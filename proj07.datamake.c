#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int asc;
  FILE *outf;

  outf = fopen("proj07.data", "w");

  for( asc=0; asc<128; asc++ )
  {
    fprintf(outf, "%c", asc);
  }
  fclose(outf);

  return 0;
}
