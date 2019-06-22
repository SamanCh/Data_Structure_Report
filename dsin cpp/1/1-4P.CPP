#include "iostream.h"
#include "conio.h"
template <class T>
int lSearch(T x[], const int n, T item)
{
  int loc, found = 0;
  for(loc = 0; loc < n && !found; loc ++)
    if(x[loc] == item)
       found = 1;
  return found;
}
//*******************
int main()
{
  const int n = 5;
  int item, x[n];
  clrscr();
  cout << "Enter " << n << " numbers :";
  for(int i = 0; i < n; i ++)
      cin >> x[i];
  cout << "Enter item to search:";
  cin >> item;
  if(lSearch(x, n, item))
     cout << "Item exist.";
  else
     cout << "Item not exist.";
  getch();
  return 0;
}

