/* A simple C code */
/* Tell me what it does */
/* Anyone? This simple code has a bug: what is it? can you modify the code to reveal the bug? */

#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "y";
  long len = 0;
  int i;
  char c = 'a';
  for(i=0; i<(int)strlen(str)-1; ++i)
  {
    ++len;
  }
  c = len + 'a';
  printf("len: %ld\nc: %c\nDone\n", len, c);
}

