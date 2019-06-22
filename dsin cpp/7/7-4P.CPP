#include "iostream.h"
#include "conio.h"
template <class T>
void insertion(T a[], const int n)
{
   int i, j;
   T t;
   for(i = 1; i < n; i++)
   {
      t = a[i];
      for(j = i; j > 0 && a[j - 1] > t; j--)
	  a[j] = a[j - 1];
      a[j] = t;
   }
}
//******************
int main()
{
   const int n = 8;
   int a[n] = {25, 57, 48, 37, 12, 92, 86, 33};
   int i;
   clrscr();
   insertion(a, n);
   for(i = 0; i < n; i++)
   {
       cout.width(4);
       cout << a[i];
   }
   getch();
   return 0;
}
