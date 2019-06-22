#include "iostream.h"
#include "conio.h"
template <class T>
void heap(T a[], int k, const int n)
{
   int j;
   T t;
   t = a[k];
   while(k < n / 2)
   {
      j = 2 * k + 1;
      if(j + 1 < n && a[j] < a[j + 1])
	   ++j;
      if(t > a[j])
	   break;
      a[k] = a[j];
      k = j;
   }
   a[k] = t;
}
//*****************
template <class T>
void sort(T a[], const int n)
{
   int i;
   T t;
   for(i = n/2 - 1; i >= 0; i--)
       heap(a, i, n);
   for(i = n - 1; i > 0; i--)
   {
      t = a[0];
      a[0] = a[i];
      a[i] = t;
      heap(a, 0, i);
    }
}

int main()
{
   const int n = 8;
   int a[n] = {88, 66, 77, 33, 55, 44, 22, 99};
   int i;
   clrscr();
   sort(a, n);
   for(i = 0; i < n; i++)
   {
       cout.width(4);
       cout << a[i];
   }
   getch();
   return 0;
}
