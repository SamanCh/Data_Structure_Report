#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#define M 20
class binNode {
   friend class huffTree;
   private:
     binNode *left;
     binNode *right;
     binNode *father;
     int freq;
     char sym;
};
class huffTree {
   public:
     huffTree();
     void makeTree(int x, int y, char, char);
     void printCode();
   private:
     binNode *root;
};
class stack {
  public:
    friend void huffTree::printCode();
    stack();
    int  empty();
  private:
    int myTop;
    binNode *item[M];
};
//****************
stack::stack()
{
   myTop = -1;
}
//***************
int stack::empty()
{
   if(myTop == -1)
      return 1;
   else
      return 0;
}
//**************
huffTree::huffTree()
{
   root = NULL;
}
//************************
void huffTree::makeTree(int x, int y, char symbol1, char symbol2)
{
   binNode *p1, *p2, *p;
   p1 = new binNode;
   p2 = new binNode;
   p =  new binNode;
   p ->  freq = x + y;
   p1 -> freq = x;
   p1 -> sym = symbol1;
   p1 -> left = p1 -> right = NULL;
   p2 -> freq = y;
   p2 -> sym = symbol2;
   p2 -> left = p2 -> right = NULL;
   p ->  left = p1;
   p ->  right = p2;
   p ->  father = NULL;
   p1 -> father = p2 -> father = p;
   if(root == NULL)
      root = p;
   else
   {
      if(p1 -> freq == root -> freq)
      {
	 p1 -> left = root -> left;
	 p1 -> right = root -> right;
	 p1 -> left -> father = p1 -> right -> father = p1;
	 delete root;
	 root = p;
      }
      else
      {
	 p2 -> left = root -> left;
	 p2 -> right = root -> right;
	 p2 -> left -> father = p2 -> right -> father = p2;
	 delete root;
	 root = p;
      }
   }
}
//****************
void huffTree::printCode()
{
  int code [M], k, j;
  binNode *p1, *q, *p = root;
  stack s;
  cout << "Generated code is:\n";
  do
  {
     // travel down left branches as far as possible
     //saving pointers to nodes passed
     while(p != NULL)
     {
	 s.item[++(s.myTop)] = p; //push to stack
	 p = p -> left;
     }
     // check if finished
     if(!s.empty())
     {
       //at this point the left subtree is empty
	 p = s.item[(s.myTop) --];  //pop from stack
	 if(p -> right == NULL)  //p is leaf
	 {      //traverae tree up to generate code
		  k = M - 1;
		  p1 = p;
		  while(p1 !=  NULL)
		  {
		       q = p1 -> father;
		       if(q -> left == p1)
				code[k--] = 1;
			else
				code[k--] = 0;
			p1 = q;
		   }
		   cout << p -> sym << " = ";
		   for(j = k + 2; j < M; j ++)
			cout <<  code[j];
		   cout << "\n";
	 }
	 p = p -> right;   //traverse right subtree
     }
  } while(!s.empty() || p != NULL);
} //end of printCode
//******************
class qNode {
   friend class queue;
   private:
     qNode *next;
     int info;
     char sym;
};
//**************
class queue {
   public:
     queue();
     int getInfo(){return start -> info;}
     void pqInsert(int num, char symbol);
     void qremove(int *num, char *symbol);
   private:
      qNode *start;
};
//*********************
queue::queue()
{
   //create head node
   start = new qNode;
   start -> next = NULL;
   start -> info = 0;
}
//**********************
void queue::pqInsert(int num, char symbol)
{
     qNode *q, *h, *p;
     q = new qNode;
     q -> next = NULL;
     q -> info = num;
     q -> sym = symbol;
     p = start;
     h = start -> next;
    while(h != NULL)
    {
	    if(q -> info > h -> info)
	     {
		p = h;
		h = h -> next;
	     }
	     else
		break;
    }//end of while
    q -> next = h;
    p -> next = q;
    (start -> info) ++;
}
//****************
void queue::qremove(int *num, char *symbol)
{
   qNode *p;
   if(start -> info > 0)
   {
      (start -> info) --;
      p = start -> next;
      *num = start -> next -> info;
      *symbol = start -> next -> sym;
      start -> next = p ->next;
      delete p;
   }
}
//*********************
int  main()
{
   queue pq;
   huffTree hf;
   char symbol1, symbol2, str[5];
   int n, fr, x, y, i;
   clrscr();
   cout << "Enter number of symbols:";
   cin.getline(str, 5);
   n = atoi(str);
   for(i = 0; i < n; i ++)
   {
      cout << "Enter symbol:";
      symbol1 = getche();
      cout << " Enter frequency:";
      cin.getline(str, 5);
      fr = atoi(str);
      pq.pqInsert(fr, symbol1);
   }
   while(pq.getInfo() > 1)
   {
       pq.qremove(&x, &symbol1);
       pq.qremove(&y, &symbol2);
       hf.makeTree(x, y, symbol1, symbol2);
       pq.pqInsert(x + y, '*');
   }
   hf.printCode();
   getch();
   return 0;
}
