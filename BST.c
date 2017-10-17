#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "BST.h"		


 int main(){
  BNode *root = root = NULL;
  char *str;
}
/* creates new Bnode */
BNode* newBNode(BNode *root, char *newEmp){
  BNode *np = (BNode*) malloc(sizeof(BNode));
  np->str = malloc(strlen(newEmp));
  BNode->left = NULL;
  BNode->right = NULL;
  return BNode;
}

/* goes through tree to find least-most root */
BNode* findMin(BNode *root){
  if(root == NULL)
    return NULL;
  else if(root->left)
    return findMin(root->left);
  else
    return root;
}

/* goes through BNodes to find greatest root */
BNode* findMax(BNode *root){
  if(root == NULL)
    return NULL;
  else if(root->right)
    return findMax(root->right);
  else
    return root;
}

/* adds BNode to tree */
BNode* bstAdd(BNode *root, char *emp){

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
BNode* bstDel(BNode *root, char *emp){
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

void bstPrint(BNode root){
  if(root ==NULL)
    return;

  bstPrint(root->left);
  printf("<%s> ",root->str);
  bstPrint(root->right);
}
