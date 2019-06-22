#include "iostream.h"
#include "conio.h"
template <class T>
int bSearch(T x[], const int n, T item)
{
  int loc, found = 0, first = 0, last = n - 1;
  while(first <= last && ! found)
  {
     loc = (first + last) / 2;
     if(item < x[loc])
	last = loc - 1;
     else if(item > x[loc])
	first = loc + 1;
     else
	found = 1;
  }
  return found;
}
//*************************
int main()
{
  const int n = 5;
  int item, x[n];
  clrscr();
  cout << "Enter " << n << " ascending sorted numbers :";
  for(int i = 0; i < n; i ++)
      cin >> x[i];
  cout << "Enter item to search:";
  cin >> item;
  if(bSearch(x, n, item))
     cout << "Item exist.";
  else
     cout << "Item not exist.";
  getch();
  return 0;
}


