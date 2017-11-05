#ifdef BST_included
#define BST_included


/* node item */
typedef struct BNode {
  struct BNode *right, *left;
  char *str;
} BNode;

/* create new Tree*/
//BST *BSTAlloc();

/* */
sruct BNode *newBnode(BNode *lp, char *newEmp);

/* */
struct BNode *findMin(BNode *lp);

/* */
struct BNode *findMax(BNode *lp);

/* */
struct BNode *bstAdd(BNode *bp, char *newEmp);

/* */
struct BNode *bstDel(BNode *lp, char *s);

/* */
void bstPrint(BNode *lp);

/* */
void writeInFile(char *s);

/* */
void readFile(BNode *node, char *fn);



#endif
