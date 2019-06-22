#include "iostream.h"
#include "stdlib.h"
#include "conio.h"
template <class T>
class node {
   friend class linkedList <T>;
   private:
       T info ;
       node <T> *next;
};
template <class T>
class linkedList {
   public:
      linkedList();
      ~linkedList();
      void enter ();
      void display ();
      void delNode ();
   private:
      node <T> *first;
      node <T> *last;
};
//***************
template <class T>
linkedList <T>::linkedList()
{
  first = last = NULL;
}
//***************
template <class T>
linkedList <T>::~linkedList()
{
  node <T> *curPtr = first;
  node <T> *temp;
  while(curPtr)
  {
     temp = curPtr;
     delete temp;
     curPtr = curPtr -> next;
  }
}
//***************
template <class T>
void linkedList <T>::enter()
{
   node <T> *help;
   help = new node <T>;
   help -> next = NULL ;
   if (first == NULL)
       first = last = help ;
   else
   {
	last -> next = help;
	last = help;
   }
   cout << "Enter number :";
   cin >> last -> info;
}
//********************
template <class T>
void linkedList <T>::display()
{
   node <T> *h;
   int i ;
   if (first == NULL) {
      cout << "List is empty .";
      getch() ;
      return;
   }
   h = first ;
   clrscr() ;
   do {
	  cout << h -> info << " ";
	  h = h -> next ;
      } while (h != NULL) ;
      cout << "\nPress a key to continue.";
      getch() ;
}
//*****************
template <class T>
void linkedList<T>::delNode()
{
    node <T> *h, *p;
    int stnum ;
    if(!first)
    {
       cout << "List is empty.";
       getch();
       return;
    }
    cout << "Enter number for delete:";
    cin >> stnum ;
    h = p = first ;
    while (h != NULL)
    {
       if (h -> info != stnum)
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
    linkedList <int> list;
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
   cout << "1.Enter number to list\n";
   cout << "2.Remove number from list\n";
   cout << "3.Print the list\n";
   cout << "4.Exit from program\n";
   cout << "Enter your select(1-4):";
   cin.getline(c, 5);
   return atoi(c);
}
