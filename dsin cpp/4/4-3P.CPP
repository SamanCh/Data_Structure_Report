#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
class joseph {
  friend class circular;
  private:
    char name[21];
    joseph *next;
};
class circular{
  public:
    circular();
    void print(int n);
    void addList(char name[]);
    void removeList(joseph *h);
  private:
    joseph *start;
};
//*******************
circular::circular()
{
  start = NULL;
}
//*******************
void circular::addList(char name[])
{
  joseph *help, *p;
  help = new joseph;
  strcpy(help -> name, name);
  if(start == NULL)
     help -> next = help;
  else
  {
      help -> next = start -> next;
      start -> next = help;
  }
  start = help;
}//****************
void circular::removeList(joseph *h)
{
  joseph *q;
  if(start == NULL || start == start -> next)
  {
     cout << "You cannot remove frm queue";
     getch();
  }
  else {
     q = start -> next;
     h -> next = q;
     delete start;
     start = q;
  }
}
//*************************
void circular::print(int n)
{
   joseph *h;
   cout << "The order of names:\n";
   while(start != start -> next)
   {
     for(int i = 1; i < n; i ++)
     {
	  h = start;
	  start = start -> next;
      }
      cout << start -> name << "  ";
      removeList(h);
   }//end of while
   //print the last name
   cout <<"\nThe soldier who escapes is:" << start -> name;
   delete start;
}
//***********************
int main()
{
   int i, n;
   circular list;
   char name[21], str[5];
   clrscr();
   cout << "Enter n:";
   cin.getline(str, 5);
   n = atoi(str);
   while(1)
   {
       cout << "Enter name of soldier:";
       cin.getline(name, 21);
       if(!name[0])
	   break;
       list.addList(name);
   }
   list.print(n);
   getch();
   return 0;
}
