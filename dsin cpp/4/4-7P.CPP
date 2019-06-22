#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
class polyNode {
   friend class polyList;
   private:
     int coef;
     int expo;
     polyNode *next;
};
class polyList {
   public:
     void enter(int , int n);
     void makePoly (int, int);
     void header();
     void polyAdd();
     void print();
   private:
     polyNode *ptrA;
     polyNode *ptrB;
     polyNode *ptrC;
     polyNode *last;
};
//************************
void polyList::header()
{
   ptrC = new polyNode;
   ptrC -> coef = 0;
   ptrC -> expo = 0;
   ptrC -> next = NULL;
   last = ptrC;
}
//********************
void polyList::print()
{
   polyNode *h;
   h = ptrC -> next;
   cout << "Degree of result is :";
   cout << ptrC -> expo << "\n";
   while(h != NULL)
   {
      if(h -> coef > 0)
	 cout << " + ";
      cout <<  h -> coef<< "x^" << h -> expo;
      h = h -> next;
   }
}
//**********************
void polyList::makePoly (int co, int ex)
{
   polyNode *help;
   help = new polyNode;
   help -> coef = co;
   help -> expo = ex;
   help -> next = NULL;
   last -> next = help ;
   last = help ;
} /* end of makePoly */
//*********************
void polyList::enter(int what, int n)
{
    polyNode *start;
    start = new polyNode;
    start = new polyNode;
    start -> coef = 0;
    start -> expo = n;
    start -> next = NULL;
    if(what == 1)
       ptrA = last = start;
    else
       ptrB = last = start;
   int co, ex;
   if(n != 0) //if polyNodenomial is not zero
      do {
	  cout << "Enter coef, expo:";
	  cin >> co >> ex;
	  makePoly(co, ex);
      } while( ex != n);
}
//****************
void polyList::polyAdd()
{
   polyNode *p1, *p2, *p3, *h;
   int sum = 0;
   p1 = ptrA -> next;
   p2 = ptrB -> next;
   p3 = ptrC;
   int degree = 0;
   while(p1 != NULL && p2 != NULL)
   {
      if(p1 -> expo == p2 -> expo)
      {
	 sum = p1 -> coef + p2 -> coef;
	 if(sum != 0)
	 {
	    degree = p1 -> expo;
	    makePoly(sum, degree);
	 } //end of inner if
	 p1 = p1 -> next;
	 p2 = p2 -> next;
      }//end of outter if
      else if(p1 -> expo < p2 -> expo)
      {
	  degree = p1 -> expo;
	  makePoly(p1 -> coef, degree);
	  p1 = p1 -> next;
	  ptrC -> expo = degree;
      } //end of else if
      else{
	  degree = p2 ->expo;
	  makePoly(p2 -> coef, degree);
	  p2 = p2 -> next;
	  ptrC -> expo = degree;
       }//end of else
   }//end of while
   while(p2 != NULL)
   {
	  degree = p2 ->expo;
	  makePoly(p2 -> coef, degree);
	  p2 = p2 -> next;
	  ptrC -> expo = degree;
   }
   while(p1 != NULL)
   {
	  degree = p1 -> expo;
	  makePoly(p1 -> coef, degree);
	  p1 = p1 -> next;
	  ptrC -> expo = degree;
   }
}
//*************
int main()
{
   int n, co, ex;
   polyList list;
   clrscr();
   cout << "Enter the degree of polyNodenomial 1:";
   cin >> n;
   list.enter(1, n);
   cout << "Enter the degree of polyNodenomial 2:";
   cin >> n;
   list.enter(2, n);
   list.header();
   list.polyAdd();
   list.print();
   getch();
   return 0;
}
