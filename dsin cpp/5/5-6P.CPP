#include <iostream.h>
#include <stdio.h>
#include <conio.h>
class treeNode {
   friend class avlTree;
   private:
       treeNode *left ;
       int  key ;
       int bf;
       treeNode *right ;
} ;
class avlTree {
   public:
      avlTree();
      void input();
      void avl_insert(treeNode **, int x, int *ub);
      void right_rotation(treeNode **, int *ub);
      void left_rotation(treeNode **, int *ub);
      void inorder (treeNode *s);
      treeNode *getRoot(){return root;}
   private:
      treeNode *root;
};
//***************
avlTree::avlTree()
{
  root = NULL;
}
avlTree avl;
//******************
void avlTree::input()
{
  treeNode *h;
  int x, ub;
  clrscr();
  while(1)
  {
      cout << "Enter a number:";
      cin >> x;
      if(!x)
	 break;
      avl.avl_insert(&root, x, &ub);
  }
}
//*****************
void avlTree::avl_insert(treeNode **parent, int x, int *ub)
{
   if(!(*parent))
   {     //insert element into null tree*/
      *ub = 1;
      *parent = new treeNode;
      (*parent) -> left = (*parent) -> right = NULL;
      (*parent) -> bf = 0;
      (*parent) -> key = x;
   }
   else if(x < (*parent) -> key)
   {
       avl.avl_insert(&(*parent) -> left, x, ub);
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
		avl.right_rotation(parent, ub);
	  }
   }//end of else if
   else if(x > (*parent) -> key)
   {
       avl.avl_insert(&(*parent) -> right, x, ub);
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
      cout << "The key is already in the tree.";
      getch();
   }
}
//*****************
void avlTree::right_rotation(treeNode **parent, int *ub)
{
   treeNode *grand_child, *child;
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
void avlTree::inorder (treeNode *s)
{
    if(s)
    {
       inorder(s -> left) ;
       cout << s -> key << "  ";
       inorder(s -> right) ;
    }
}
//*****************
void avlTree::left_rotation(treeNode **parent, int *ub)
{
}
//***************
int main()
{
  avl.input();
  cout << "Traverse of AVL treeNode is:\n";
  avl.inorder(avl.getRoot());
  getch();
  return 0;
}
