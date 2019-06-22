#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#define SIZE 5
class queue {
  public:
    queue();
    int  empty();
    void addQ(int &, int &);
    void retrieve(int &, int &);
    void qremove(int &, int &);
    void print();
  private:
    int items[SIZE];
    int front;
    int rear;
};
//**************
queue::queue()
{
   front = 0;
   rear = -1;
}
//*************
int queue::empty()
{
   if(rear < front)
       return 1;
    return 0;
}
//*************
void queue::addQ(int &x, int &overflow)
{
   if(rear == SIZE-1)
      overflow = 1;
   else
   {
      overflow = 0;
      items[++rear] = x;
   }
}
//*************
void queue::retrieve(int &x, int &underflow)
{
   if(empty())
       underflow = 1;
   else
   {
       underflow = 0;
       x = items[front];
   }
}
//*************
void queue::qremove(int &x, int &underflow)
{
   if(empty())
       underflow = 1;
   else
   {
       underflow = 0;
       x = items[front++];
   }
}
//*************
void queue::print()
{
  if(empty())
     cout << "Queue is empty.";
  for(int i = front; i <= rear; i ++)
     cout << items[i] << "  ";
  cout << "\nPress a key to continue.";
  getch();
}
//*************
int menu();
int main()
{
   queue q;
   int x, overflow, underflow;
   while(1)
   {
      clrscr();
      switch(menu())
      {
	 case 1:
	      q.print();
	      break;
	 case 2:
	      cout << "Enter a value to enter q:";
	      cin >> x;
	      q.addQ(x, overflow);
	      if(overflow) {
		 cout << "queue is full. press a key to continue.";
		 getch();
	      }
	      break;
	 case 3:
	      q.qremove(x, underflow);
	      if(underflow){
		 cout << "queue is empty. press a key to continue.";
		 getch();
	      }
	      else {
		 cout << "Removed value is:" << x;
		 getch();
	      }
	      break;
	 case 4:
	      q.retrieve(x, underflow);
	      if(underflow) {
		 cout << "queue is empty. press a key to continue.";
		 getch();
	      }
	      else {
		 cout << "Retrieved value is:" << x;
		 getch();
	      }
	      break;
	 case 5:
	      exit(1);
      }//end of switch
    }//end of while
}//end of program
//*******************
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


