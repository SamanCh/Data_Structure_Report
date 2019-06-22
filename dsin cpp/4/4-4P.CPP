#include "iostream.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
class node{
   friend class linkedList;
   private:
      char name[15];
      node *next;
};
class linkedList{
   public:
     linkedList();
     void sorted(char str[]);
     void print();
   private:
     node *start;
};
//******************
linkedList::linkedList()
{
  start = NULL;
}
//******************
void linkedList::sorted(char str[])
{
   node *h, *p, *help;
   help = new node;
   strcpy((help -> name), str);
   help -> next = NULL;
   if(start == NULL)
      start = help;
   else
   {
       p = h = start;
       while(h != NULL)
       {
	     if(strcmp((help -> name), h -> name) > 0)
	     {
		p = h;
		h = h -> next;
	     }
	     else
		break;
       }//end of while
       help -> next = h;
       if(h == start)
	  start = help;
       else
	  p -> next = help;
   }//end of else
}
//***************
void linkedList::print()
{
   node *h;
   h = start;
   while(h != NULL)
   {
      cout << h -> name << "  ";
      h = h -> next;
   }
}
//**********************
int main()
{
   linkedList list;
   char str[15];
   clrscr();
   while(1)
   {
      cout << "Enter name:";
      cin.getline(str, 15);
      if(!str[0])
	 break;
      list.sorted(str);
   }
   list.print();
   getch();
   return 0;
}




