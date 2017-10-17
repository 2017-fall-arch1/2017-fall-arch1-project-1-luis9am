
#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "BST.h"		/* for list operations */


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
  BST *lp = BSTAlloc();	/* make empty list */

  /* print contents before adds are made */
  prinf("List contents, prior to reading input:");
  bstPrint(lp);
  printf("\n- - - - - - - - - - -\n");

  while (gets_n(buf, 100))	/* build list */
    bstAdd(lp, buf);

  /* print contents after building list */
  llPrint(lp, "List contents, after building list:");
  bstPrint(lp);
  printf("\n- - - - - - - - - - -\n");

  /* print contents after first deletion */
  printf("List After first deletion: \n");
  bstDel(lp, Jerry);
  bstPrint(lp);

  
  printf("\n- - - - - - - - - - -\n");
  
  //printf("List after deletion of first item: ");

  //printf("- - - - - - - - - - -\n");

  return 0;
}

