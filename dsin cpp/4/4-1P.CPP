#include "iostream.h"
#include "stdlib.h"
#include "conio.h"
class node {
   friend class linkedList;
   private:
       char name[30] ;
       int stno ;
       int unit ;
       node *next;
};
class linkedList {
   public:
      linkedList();
      ~linkedList();
      void enter ();
      void display ();
      void delNode ();
   private:
      node *first;
      node *last;
};
//***************
linkedList::linkedList()
{
  first = last = NULL;
}
//***************
linkedList::~linkedList()
{
  node *curPtr = first;
  node *temp;
  while(curPtr)
  {
     temp = curPtr;
     delete temp;
     curPtr = curPtr -> next;
  }
}
//***************
void linkedList::enter()
{
   node *help;
   help = new node;
   help -> next = NULL ;
   if (first == NULL)
       first = last = help ;
   else
   {
	last -> next = help;
	last = help;
   }
   cout << "Enter name of student:";
   cin.getline(last -> name, 30) ;
   cout << "Enter student number :";
   cin >> last -> stno;
   cout << "Enter number of unit :";
   cin >> last -> unit;
}
//********************
void linkedList::display()
{
   node *h;
   int i ;
   if (first == NULL) {
      cout << "List is empty .";
      getch() ;
      return;
   }
   h = first ;
   clrscr() ;
   gotoxy(5,4) ;
   cout << "name               st.number    unit ";
   gotoxy(5, 5);
   cout <<"---------          ---------    -----" ;
   i = 6 ;
   do {
	   gotoxy(1, i);
	   cout << h -> name;
	   gotoxy(25, i);
	   cout << h -> stno;
	   gotoxy(38, i);
	   cout << h -> unit;
	   i ++ ;
	   h = h -> next ;
      } while (h != NULL) ;
      gotoxy(5, i++) ;
      cout << "**********************" ;
      cout << "***************" ;
      gotoxy(10, i++) ;
      cout << "Press a key to continue.";
      getch() ;
}
//*****************
void linkedList::delNode()
{
    node *h, *p;
    int stnum ;
    if(!first)
    {
       cout << "List is empty.";
       getch();
       return;
    }
    cout << "Enter student number for delete:";
    cin >> stnum ;
    h = p = first ;
    while (h != NULL)
    {
       if (h -> stno != stnum)
       {
	  p = h ;
	  h = h -> next ;
	  continue ;
       }
       else {  //remove from start
	if (h == first) {
	    first = h -> next ;
	    delete h ;
	    delete p ;
	    break ;
	 }//end of if
	 else  {
	     if(h == last)
		 last = p;
	     p -> next = h -> next;
	     delete h ;
	     break ;
	 }//end of else
     }//end of else
    }//end of while
}
//****************
int menu();
//****************
int main ()
{
    linkedList list;
    while (1)
    {
       clrscr() ;
       switch (menu())
       {
	   case 1:
	       list.enter() ;
	       break ;
	   case 2:
	       list.delNode() ;
	       break ;
	   case 3:
	       list.display() ;
	       break ;
	   case 4:
	       exit(0) ;
     }//end of switch
   } //end of while
} // end of main
//********************
int menu()
{
   char c[5];
   cout << "1.Enter name to list\n";
   cout << "2.Remove name from list\n";
   cout << "3.Print the list\n";
   cout << "4.Exit from program\n";
   cout << "Enter your select(1-4):";
   cin.getline(c, 5);
   return atoi(c);
}
