#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "BST.h"		



/* creates new Bnode */
BNode *newBNode(char *newEmp)
 {
  BNode *np = (BNode *) malloc(sizeof(BNode));
  np->str = malloc(strlen(newEmp)+1);
  np->left = NULL;
  np->right = NULL;
  return np;
}

/* goes through tree to find least-most root */
BNode *findMin(struct BNode *root){
  if(root == NULL)
    return NULL;
  else if(root->left)
    return findMin(root->left);
  else
    return root;
}

/* goes through BNodes to find greatest root */
BNode *findMax(BNode *root)
{
  if(root == NULL)
    return NULL;
  else if(root->right)
    return findMax(root->right);
  else
    return root;
}

/* adds BNode to tree */
BNode* bstAdd(BNode *root, char *emp)
{

  if(root == NULL){
    root = newBNode(employee);
    printf("new entry: <%s>: ", emp);
  }

  int nodeComp = strcmp(root->str, employee);
  if(nodeComp == 0)
    printf("Employee already exists..");
  else if(nodeComp < 0)
    root->left = newBnode(root->left, employee);
  else
    root->right = newBnode(root->right, employee);

  return root;
}

/* delete node from tree */
BNode* bstDel(BNode *root, char *emp)
{
  if(root == NULL)
    return root;

  int nodeComp(root->str, emp);
  
  if(nodeComp > 0)
    root->left = bstDel(root->left, emp);
  else if(nodeComp < 0)
    root->right = bstDel(root->right, emp);
  else{

    /*handles replacement of nodes when deletion is made */
    if(root->right && root->left){
      temp = findMin(root->right);
      root->emp = bstDel(root->right, temp->emp);

    }else{
      temp = root;
      if(root->left == NULL)
	root = root->right;
      else if(root->right ==NULL)
	root = root->left;
      //free temp;
    }
  }
  return root;
}

void bstPrint(struct BNode root)
{
  if(root ==NULL)
    return;

  bstPrint(root->left);
  printf("<%s> ",root->str);
  bstPrint(root->right);
}

void writeToFile(BNode *node, char *filename)
{
  FILE *fp;
  fp = fopen(fileName, "w");
  if(fp == NULL){
    print("File does not exist");
    return;
  }
  if(node == NULL)
    return;
  writeToFile(node->left,fileName);
  f printf(fp," %s\n", node->str);
  writeToFile(node->right,fileName);
}

BNode *readFile(BNode *node, char *fileName)
{
  FILE *fp;
  fp = fopen(fileName, "r");
  int line = getc(fp);
  char *name = (char *) malloc(sizeof(char));
  while(line != EOF)
    {
      fscanf(fp," %s", name);
      node = bstAdd(node, name);
      line = getc(fp);
    }
  fclose(fp);
  return node;
}

void main()
{
  Bnode *node = NULL;
  int count = 1;
  int command =0;
  char *employee;
  printf("Personal management system\n");

  while(count ==1){
    printf("Enter command \n 1. Add new employee.\n"
	   "2. Remove employee.\n"
	   "3. Add employee from file.\n"
	   "4. Display  employees.\n"
	   "5. Wrie employees name to file.\n"
	   "6. Exit. \n");
    scanf("%d", command);

    if(command == 1)
      {
	printf("enter employee name.\n");
	scanf("%s",employee);
	addNode(node,employee);
      }
    else if(command ==2)
      {
	printf("Please enter employee name that will be deleted.\n");
	scanf("%s",employee);
	bstDel(node,employee);
      }
    else if(command ==3)
      {
	bstPrint(node);
      }
    if(command == 4)
      {
	printf("enter name of file to read.\n");
	scanf("%s",employee);
	readFile(node,employee);
      }
    else if(command ==5)
      {
	printf("enter name of file to write.\n");
	scanf("%s",employee);
	bstDel(node,employee);
      }
    else if(command ==6)
      {
	count = 0;
	return;
      }
    else
      printf("not a valid entry.\n");
  }
}
	     
    
    
