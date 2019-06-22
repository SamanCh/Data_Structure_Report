#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "ctype.h"
#define M 9
char node[M + 2];
class adjList {
    friend class  nodeList;
  private:
    int info;
    adjList *next;
};
class nodeType {
  friend class nodeList;
  private:
    char info;
    adjList *listPtr;
    nodeType *nextNode;
};
//****************
class nodeList{
  public:
    nodeList();
    ~nodeList();
    void makeGraph();
    void print();
    void depth();
  private:
    nodeType *start;
};
nodeList::nodeList()
{
   start = NULL;
}
//****************
nodeList::~nodeList()
{
   nodeType *p;
   while(start != NULL)
   {
     p = start;
     start = start -> nextNode;
     delete p;
   }
}
//****************
class stack {
  friend void nodeList::depth();
  public:
    stack();
    int  empty();
  private:
    int myTop;
    adjList *item[M + 1];
};
//*******************
stack::stack()
{
   myTop = -1;
}
//********************
void nodeList::makeGraph()
{
   nodeType *np, *eofnp = NULL;
   adjList  *ap, *eofap = NULL;
   char data;
   int num, i = 0;
   while(1)
   {
      cout << "Enter data of a node:";
      data = getche();
      cout << "\n";
      if(data == '\r')
	 break;
      else {
	 node[++i] = data;
	 np = new nodeType;
	 np -> info = data;
	 np -> listPtr = NULL;
	 np -> nextNode = NULL;
	 if(start == NULL)
	      start = eofnp = np;
	 else {
	   eofnp -> nextNode = np;
	   eofnp = np;
	 }
	 eofap = NULL;
	 while(1)
	 {
	    cout << "Enter adjacy list node( -1 to end):";
	    cin >> num;
	    if(num == -1)
		break;
	    ap = new adjList;
	    ap -> info = num;
	    ap -> next = NULL;
	    if(eofap == NULL)
	    {
	       eofnp -> listPtr = ap;
	       eofap = ap;
	    }
	    else {
	       eofap -> next = ap;
	       eofap = ap;
	    }//end of else
	 } //end of inner while
      }//end of else
   }//end of while
}
//*****************
void nodeList::print()
{
   nodeType *np;
   adjList *ap;
   np = start;
   cout << "\nAdjacy list is :\n";
   while(np != NULL)
   {
      cout << np -> info << " -> ";
      ap = np -> listPtr;
      while(ap != NULL)
      {
	 cout << ap -> info << "  ";
	 ap = ap -> next;
      }
      cout << "\n";
      np = np -> nextNode;
   }
}
//*******************
void nodeList::depth()
{
  stack s;
  nodeType *h;
  adjList *p, *q;
  int status[M + 1];
  for(int i = 1; i <= M; i++)
     status[i] = 1;
  p = new adjList;
  p -> info = 1;
  p -> next = start -> listPtr;
  s.item[++(s.myTop)] = p; //push to stack
  status[p -> info] = 2;
  q = p;
  cout << "Depth first traversal is:\n";
  while(!(s.empty()))
  {
     p = s.item[(s.myTop) --];  //pop from stack
     status[p -> info] = 3;
     cout << node[p -> info] << " ";
     h = start;
     while(h != NULL)
     {
	if(node[p -> info] == h -> info)
	   break;
	h = h -> nextNode;
     }
     q = h -> listPtr;
     while(q != NULL)
     {
	if(status[q -> info] == 1)
	{
	   status[q -> info] = 2;
	   s.item[++(s.myTop)] = q; //push to stack
	}//end of if
	q = q -> next;
     } //end of while
  }//end of while
}//end of depth
//**********************
int stack::empty()
{
   if(myTop == -1)
      return 1;
   else
      return 0;
}
//**************
int main()
{
    nodeList list;
    clrscr();
    list.makeGraph();
    list.print();
    list.depth();
    getch();
    return 0;
}
