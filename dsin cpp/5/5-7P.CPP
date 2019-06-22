#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
class threadNode{
   friend class threadTree;
   private:
     threadNode *left;
     int info;
     int rthread;
     threadNode *right;
};
class threadTree {
  public:
     threadTree();
     threadNode *getRoot(){return root;}
     void maketree(int num);
     void inorder (threadNode *s);
  private:
     threadNode *root;
};
//****************
threadTree::threadTree()
{
   root = NULL;
}
//******************
void threadTree::maketree(int num)
{
   threadNode *q, *p, *r;
   q = new threadNode;
   q -> left = q -> right = NULL;
   q -> info = num;
   q -> rthread = 1;
   if(root == NULL)
      root = q;
    else
    {
      p = root;
      while (p != NULL)
      {
	if(q -> info > p -> info)
	{
	    if (p -> rthread)
	    {
		 p -> rthread = 0;
		 //save the inorder successor of node p
		 r = p -> right;
		 p -> right = q;
		 q -> left = NULL;
		 //The inorder successor of node q is the
		 //previous successor of node p
		 q -> right = r;
		 q -> rthread = 1;
		 break;
	    }//end of if
	    else
	       p = p -> right;
	}//end of if
	else  {
	    if (p -> left != NULL )
		   p = p -> left ;
	    else  {
		 p -> left = q ;
		 q -> left = NULL;
		 //The inorder successor of node q is node p
		 q -> right = p;
		 q -> rthread = 1;
		 break ;
	    } //end of else
	}  //end of else
      }//end of while
   }//end else
}
//*******************
void threadTree::inorder(threadNode *s)
{
   threadNode *p, *q;
   cout << "Traverse of tree is :\n";
   p = s;
   do {
      q = NULL;
      while(p != NULL) //Traverse left branch
      {
	 q = p;
	 p = p -> left;
      }//end of while;
      if(q != NULL)
      {
	 cout << q -> info << "  ";
	 p = q -> right;
	 while(q -> rthread && p!= NULL)
	 {
	    cout << p -> info << "  ";
	    q = p;
	    p = p -> right;
	 }//end of while
      }//end of if
   } while(q != NULL);
}
//**********************
int main()
{
   threadTree thread;
   int num;
   clrscr();
   while(1)
   {
      cout << "Enter a number:";
      cin >> num;
      if(!num)
	 break;
      thread.maketree(num);
   }
   if(thread.getRoot())
      thread.inorder(thread.getRoot());
   getch();
   return 0;
}



