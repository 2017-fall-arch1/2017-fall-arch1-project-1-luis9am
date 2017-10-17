#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "llist.h"		/* for list operations */


/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

int main()
{
  char buf[100];
  LList *lp = llAlloc();	/* make empty list */

  llPrint(lp, "List contents, prior to reading input:");
  printf("- - - - - - - - - - -\n");

  while (gets_n(buf, 100))	/* build list */
    llPut(lp, buf);

  llPrint(lp, "List contents, after building list:");

  //new - - - - - -

  printf("- - - - - - - - - - -\n");

  printf("List prints reverse: \n");
  llReverse(lp);              /* implementation for llReverse() */

  // - - - - = = = = = = = = - - - -
  
  printf("- - - - - - - - - - -\n");
  
  llGet(lp);                  /* implementation for llGet() */
  llPrint(lp, "List after deletion of first item: ");

  printf("- - - - - - - - - - -\n");

  //wen - - - - - -
  
  llMakeEmpty(lp);
  
  printf("After emptying the list...");
  llPrint(lp, 0);		/* default message */

  llFree(lp);

  return 0;
}
