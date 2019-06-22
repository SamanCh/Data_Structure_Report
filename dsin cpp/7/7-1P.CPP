#include "iostream.h"
#include "conio.h"
template <class T>
void bubble(T a[], const int n)
{
   int i, j;
   T t;
   int switched = 1;
   for(i = n - 1 ; i > 0  && switched; i--)
   {
      switched = 0;
      for(j = 0; j < i; j ++)
	  if(a[j] > a[j + 1])
	  {
	     switched = 1;
	     t = a[j];
	     a[j] = a[j + 1];
	     a[j + 1] = t;
	  }
   }
}
//***************
int main()
{
   const int n = 8;
   int a[n] = {25, 57, 48, 37, 12, 92, 86, 33};
   int i;
   bubble(a, n);
   for(i = 0; i < n; i++)
   {
     cout.width(4);
     cout << a[i];
   }
   getch();
   return 0;
}


