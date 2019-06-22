#include "iostream.h"
#include "conio.h"
template <class T>
void select(T x[], const int n)
{
 int min, item;
 for(int i = 0; i < n - 1; i ++)
 {
    min = i;
    for(int j = i + 1; j < n; j ++)
       if(x[j] < x[min])
	 min = j;
    item = x[i];
    x[i] = x[min];
    x[min] = item;
 }
}
//********************
int main()
{
  const int n = 5;
  int  x[n];
  clrscr();
  cout << "Enter " << n << " numbers:";
  for(int i = 0; i < n; i ++)
     cin >> x[i];
  select(x, n);
  cout << "Sorted data is:";
  for(i = 0; i < n; i ++)
     cout <<  x[i] << "  ";
  getch();
  return 0;
}


