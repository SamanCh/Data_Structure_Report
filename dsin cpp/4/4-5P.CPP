#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
class bNode{
  friend class bList;
  private:
     bNode *left;
     int num;
     bNode *right;
};
class bList{
  public:
    bList();
    void enter(int what);
    void makeList(int what, int number);
    void add();
    void print();
  private:
    bNode *start1;
    bNode *start2;
    bNode *start3;
};
//*******************
bList::bList()
{
   start1 = new bNode;
   start1 -> left = start1 -> right = start1;
   start1 -> num = 0;
   start2 = new bNode;
   start2 -> left = start2 -> right = start2;
   start2 -> num = 0;
   start3 = new bNode;
   start3 -> left = start3 -> right = start3;
   start3 -> num = 0;
}
//*******************
void bList::enter(int what)
{
   int number;
   while(1)
   {
      cout << "One block(3 digit):";
      cin >> number;
      if(number > 999)
      {
	 cout << "Block is illegal. Enter agin.";
	 getch();
      }
      else if(number == -1)
	 break;
      else
	 makeList(what, number);
   }
}
//******************
void bList::makeList(int what, int number)
{
  bNode *start;
  switch(what) {
      case 1:
	  start = start1;
	  break;
      case 2:
	  start = start2;
	  break;
      case 3:
	  start = start3;
	  break;
  }//end of switch
  (start -> num) ++;
  bNode *help;
  help = new bNode;
  help -> num = number;
  help -> left = start -> left;
  start -> left -> right = help;
  start -> left = help;
  help -> right = start;
}
//*********************
void bList::add()
{
   int num1, num2, temp, result, carry = 0;
   bNode *h1, *h2;
   h1 = start1 -> left;
   h2 = start2 -> left;
   while(h1 != start1 && h2 != start2)
   {
       num1 = h1 -> num;
       num2 = h2 -> num;
       temp = num1 + num2 + carry;
       result = temp % 1000;
       carry = temp / 1000;
       makeList(3, result);
       h1 = h1 -> left;
       h2 = h2 -> left;
   }
   while(h2 != start2)
   {  //if list2 not finished
       num2 = h2 -> num;
       temp = num2 + carry;
       result = temp % 1000;
       carry = temp / 1000;
       makeList(3, result);
       h2 = h2 -> left;
   }
   while(h1 != start1)
   {  //if list1 not finished
       num1 = h1 -> num;
       temp = num1 + carry;
       result = temp % 1000;
       carry = temp / 1000;
       makeList(3, result);
       h2 = h2 -> left;
   }
   if(carry != 0)
       makeList(3, carry);
}
//******************
void bList::print()
{
   bNode *h;
   cout << "Sum of two numbers is :";
   h = start3 -> left;
   while(h != start3)
   {
     if(h -> num < 10)
       cout << 0 << 0 << h -> num << " ";
     else if(h -> num >= 10  && h -> num < 100)
	  cout << 0 << h -> num << " ";
     else
	  cout << h -> num << " ";
     h = h -> left;
   }
}
//********************
int main()
{
   bList list;
   clrscr();
   cout << "Enter first number(-1) to END:\n";
   list.enter(1);
   cout << "Enter second number(-1) to END:\n";
   list.enter(2);
   list.add();
   list.print();
   getch();
   return 0;
}
