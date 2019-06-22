#include "iostream.h"
#include "conio.h"
template <class T>
void selection(T a[], const int n)
{
   int i, j, minpos;
   T t;
   for(i = 0; i < n - 1; i++)
   {
     minpos = i;
     for(j = i + 1; j < n; j++)
	 if(a[j] < a[minpos])
	      minpos = j;
     //swap a[minpos], a[i]
     t = a[minpos];
     a[minpos] = a[i];
     a[i] = t;
   }
}
//********************
int main()
{
   const int n = 8;
   int a[n] = {88, 66, 77, 33, 55, 44, 22, 99};
   int i;
   clrscr();
   selection(a, n);
   for(i = 0; i < n; i++)
   {
       cout.width(4);
       cout << a[i];
   }
   getch();
   return 0;
}
