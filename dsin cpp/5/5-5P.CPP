#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class treeNode {
       friend class tree;
    private:
       treeNode *left ;
       int  key ;
       treeNode *right ;
} ;
class tree {
   public:
     tree();
     void input ();
     void insert(int);
     int  search (int);
     treeNode *getRoot() {return root;}
     void inorder (treeNode *s);
     void deleteNode(int item);
     void search2(int item, int *found,
	     treeNode **locptr, treeNode **parent);
   private:
     treeNode *root;
};
//********************
tree::tree()
{
  root = NULL;
}
//********************
int  menu_select();
//********************
void tree::input ()
{
    int num;
    while(1)
    {
      cout << "Enter a number:";
      cin >> num;
      if(!num)
	  break;
      insert(num);
    } //end while
}
//***********************
void tree::insert(int num)
{
   treeNode *node, *help ;
   help = root;
   node = new treeNode;
   node -> left = node -> right = NULL;
   node -> key = num;
   if(root == NULL)
      root = node;
    else
    {
      while (help != NULL)
      {
	if(node -> key > help ->key)
	{
	  if (help -> right != NULL)
		help = help -> right ;
	  else {
	      help -> right=node ;
	      break ;
	  }//end of else
	} //end of if
	else  {
	    if (help -> left != NULL )
		   help = help -> left ;
	    else  {
		 help -> left=node ;
		 break ;
	    } //end of else
	}  //end of else
      }//end of while
   }//end else
}
//*******************
int tree::search(int num)
{
   treeNode *h = root;
   while(h != NULL)
   {
      if( num < h -> key)
	  h = h -> left;
      else if(num > h ->key)
	 h = h -> right;
      else return 1;
    }
    return 0;
}
//********************
void tree::inorder(treeNode *s)
{
    if(s)
    {
       inorder(s -> left) ;
       cout << s -> key << " ";
       inorder(s -> right) ;
    }
}
//************************************
void tree::deleteNode(int item)
{
  int found;
  treeNode *x, *parent, *xSucc, *subtree;
  search2(item, &found, &x, &parent);
  if(!found)
  {
      cout << "item not found in BST.";
      return;
  }
  if(x -> left != NULL && x -> right != NULL)
  {    //node has two children
       //Find x's successor and its parent
       xSucc = x -> right;
       parent = x;
       while(xSucc -> left != 0)  //descend left
       {
	  parent = xSucc;
	  xSucc = xSucc -> left;
       }
       //Move contents of xSucc to x and change x
       //to point to successor, wich will be deleted.
       x -> key = xSucc -> key;
       x = xSucc;
  }//end of if
  //Now proceed with case where node has 0 or 1 child
  subtree = x -> left;   //point to a subtree of x
  if(subtree == NULL)
     subtree = x -> right;
  if(parent == NULL)     //root being deleted
      root = subtree;
  else if(parent -> left == x) //left child of parent
      parent -> left = subtree;
  else           //right child of parent
      parent -> right = subtree;
  delete x;
} //end of deleteNode()
//********************
void tree::search2(int item, int *found,
	     treeNode **locptr, treeNode **parent)
{
   *locptr = root;
   *parent = NULL;
   *found = 0;
   for(;;)
   {
       if((*found) || *locptr == NULL)
	  return;
       if(item < (*locptr) -> key)    //descend left
       {
	  *parent = *locptr;
	  *locptr = (*locptr) -> left;
       }
       else if(item > (*locptr) -> key) //descend right
       {
	  *parent = *locptr;
	  *locptr = (*locptr) -> right;
       }
       else
	  (*found) = 1;
   }
}
//*****************
int main ()
{
    tree treeObject;
    int num;
    while (1)  {
	clrscr();
	switch(menu_select())  {
	  case 1:

		 treeObject.input() ;
		 break ;
	  case 2:
		 cout << "Enter number to search:";
		 cin >> num;
		 if(treeObject.search(num))
		    cout << "Number found.";
		 else
		    cout << "Number not found.";
		 getch() ;
		 break ;
	  case 3:
		 clrscr() ;
		 cout << "\n Traverse treeNode in inorder:\n";
		 treeObject.inorder(treeObject.getRoot()) ;
		 getch();
		 break ;
	  case 4:
		 cout << "Enter number to delete:";
		 cin >> num;
		 treeObject.deleteNode(num);
		 break ;
	  case 5:
		 exit(0) ;
	} //end of switch
    } //end of while
}//end of main
//**********************
int menu_select()
{
   int choice ;
   char s[5] ;
   cout << "1- Enter a number in treeNode.\n";
   cout << "2- Search a number in treeNode.\n";
   cout << "3- Print information on screen.\n" ;
   cout << "4- delete an item.\n";
   cout << "5- Quit from program.\n" ;
   do {
       cout << "Enter your select(1-5):";
       cin.getline(s, 5) ;
       choice = atoi(s) ;
   }  while (choice < 0 || choice > 5);
   return choice ;
}





