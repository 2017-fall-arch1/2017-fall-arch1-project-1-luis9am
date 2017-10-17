#ifdef BST_included
#define BST_included


/* node item */
typedef struct BNode {
  struct BNode *right, *left;
  char *str;
} BNode;

/* tree items */
typedef struct {
  BNode *root;
} BST;


//extern int llDoCheck;

/* create new Tree*/
BST *BSTAlloc();

/* */
void newBnode(BST *lp);

/* */
void findMin(BST *lp);

/* */
void findMax(BST *lp);

/* */
void bstAdd(BST *bp, char *e);

/* */
void bstDel(BST *lp, char *s);

/* */
void bstPrint(BST *lp);

/* */
void writeInFile(char *s);

/* */
void readFile();

#endif
