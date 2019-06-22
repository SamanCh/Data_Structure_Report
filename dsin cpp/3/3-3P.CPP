#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#define SIZE 5
class  pqueue{
  public:
    pqueue();
    int  empty();
    void addQ(int , int &);
    void retrieve(int &, int &);
    void qremove(int &, int &);
    void print();
  private:
    int items[SIZE];
    int front;
    int rear;
};
//*******************
pqueue::pqueue()
{
   front = 0;
   rear = 0;
}
//***************
int pqueue::empty()
{
   if(rear == front)
       return 1;
    return 0;
}
//********************
void pqueue::addQ(int x, int &overflow)
{
   if(rear == SIZE)
      overflow = 1;
   else if(rear == 0) //there is no items
   {
      items[rear++] = x;
      overflow = 0;
   }
   else
   {
      for(int i = rear - 1; i >= 0; i --)
      {
	  if(x > items[i])
	      items[i + 1] = items[i];
	  else
	      break;
       }//end of for
       items[i + 1] = x;
       rear++;
       overflow = 0;
   }
}
//********************
void pqueue::retrieve(int &x, int &underflow)
{
   if(empty())
       underflow = 1;
   else
   {
       underflow = 0;
       x = items[rear - 1];
   }
}
//*******************
void pqueue::qremove(int &x, int &underflow)
{
   if(empty())
       underflow = 1;
   else
   {
       underflow = 0;
       x = items[rear - 1];
       rear--;
   }
}
//*******************
void pqueue::print()
{
  if(empty())
     cout << "Queue is empty.";
  for(int i = front; i < rear; i ++)
     cout << items[i] << "  ";
  cout << "\nPress a key to continue.";
  getch();
}
//**********************
int menu();
int main()
{
   pqueue pq;
   int x, overflow, underflow;
   while(1)
   {
      clrscr();
      switch(menu())
      {
	 case 1:
	      pq.print();
	      break;
	 case 2:
	      cout << "Enter a value to enter pq:";
	      cin >> x;
	      pq.addQ(x, overflow);
	      if(overflow)
	      {
		 cout << "pqueue is full. press a key to continue.";
		 getch();
	      }
	      break;
	 case 3:
	      pq.qremove(x, underflow);
	      if(underflow)
	      {
		 cout << "pqueue is empty. press a key to continue.";
		 getch();
	      }
	      else
	      {
		 cout << "Removed value is:" << x;
		 getch();
	      }
	      break;
	 case 4:
	      pq.retrieve(x, underflow);
	      if(underflow)
	      {
		 cout << "pqueue is empty. press a key to continue.";
		 getch();
	      }
	      else
	      {
		 cout << "Retrieved value is:" << x;
		 getch();
	      }
	      break;
	 case 5:
	      exit(1);
      }//end of switch
    }//end of while
}//end of program
//********************
int menu()
{
   int c;
   cout << "1. Print queue.\n";
   cout << "2. Add to quue.\n";
   cout << "3. Remove from queue.\n";
   cout << "4. Retrieve from queue.\n";
   cout << "5. Exit.\n";
   cout << "Enter your select(1-5):";
   cin >> c;
   return c;
}


