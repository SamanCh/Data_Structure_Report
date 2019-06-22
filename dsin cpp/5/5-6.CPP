#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct tree {
       tree *left ;
       int  key ;
       int bf;
       tree *right ;
} ;
void avl_insert(tree **root, int x, int *ub);
void right_rotation(tree **parent, int *ub);
void left_rotation(tree **parent, int *ub);
void inorder (tree *s);
int main()
{
  tree *h, *root = NULL;
  int x, ub;
  clrscr();
  while(1)
  {
      printf("Enter a number:");
      scanf("%d", &x);
      if(!x)
	 break;
      avl_insert(&root, x, &ub);
  }
  printf("Traverse of AVL tree is:\n");
  inorder(root);
  getch();
  return 0;
}
//*****************
void avl_insert(tree **parent, int x, int *ub)
{
   if(!(*parent))
   {     //insert element into null tree*/
      *ub = 1;
      *parent = (tree *)malloc(sizeof(tree));
      (*parent) -> left = (*parent) -> right = NULL;
      (*parent) -> bf = 0;
      (*parent) -> key = x;
   }
   else if(x < (*parent) -> key)
   {
       avl_insert(&(*parent) -> left, x, ub);
       if(*ub)  //left branch has grown higher
	  switch((*parent) -> bf)
	  {
	     case -1:
		(*parent) -> bf = 0;
		*ub = 0;
		break;
	     case 0:
		(*parent) -> bf = 1;
		break;
	     case 1:
		right_rotation(parent, ub);
	  }
   }//end of else if
   else if(x > (*parent) -> key)
   {
       avl_insert(&(*parent) -> right, x, ub);
       if(*ub)  //right branch has grown higer
	  switch((*parent) -> bf)
	  {
	     case -1:
		(*parent) -> bf = 0;
		*ub = 0;
		break;
	     case 0:
		(*parent) -> bf = -1;
		break;
	     case 1:
		left_rotation(parent, ub);
	  } //end of switch
   } //end of else if
   else
   {
      *ub = 0;
      printf("The key is already in the tree.");
      getch();
   }
}
//*****************
//void left_rotation(tree **parent, int *ub)
void right_rotation(tree **parent, int *ub)
{
   tree *grand_child, *child;
   child = (*parent) -> left;
   if(child -> bf == 1)
   {
      //LL rotation
      (*parent) -> left = child -> right;
      child -> right = *parent;
      (*parent) -> bf = 0;
      (*parent) = child;
   }
   else
   {   //LR rotation
      grand_child = child -> right;
      child -> right = grand_child -> left;
      grand_child -> left = child;
      (*parent) -> left = grand_child -> right;
      switch(grand_child -> bf)
      {
	 case 1:
	     (*parent) -> bf = -1;
	     child -> bf = 0;
	     break;
	 case 0:
	     (*parent) -> bf = child -> bf = 0;
	     break;
	 case -1:
	     (*parent) -> bf = 0;
	     child -> bf = 1;
      }
      *parent = grand_child;
   }
   (*parent) -> bf = 0;
   *ub = 0;
}
//*****************
void left_rotation(tree **parent, int *ub)
{
}
//*****************
void inorder (tree *s)
{
    if(s)
    {
       inorder(s -> left) ;
       printf("%d  ", s -> key);
       inorder(s -> right) ;
    }
}
