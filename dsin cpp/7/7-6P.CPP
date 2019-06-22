#include "iostream.h"
#include "stdlib.h"
#include "conio.h"
template <class T>
void mergArr(T a[], const int n1, T b[], const int n2, T c[], int n3)
{
   int i, j, k;
   i = 0;
   j = 0;
   if((n1 + n2) != n3)
   {
      cout << "Size of n3 is incorrect.";
      getch();
      exit(0);
   }
   for(k = 0; i < n1 && j < n2; k++)
      if(a[i] < b[j])
	 c[k] = a[i++];
      else
	 c[k] = b[j++];
   while(i < n1)
      c[k++] = a[i++];
   while(j < n2)
      c[k++] = b[j++];
}
//*****************
int main()
{
   const int n1 = 8, n2 = 5;
   int a[n1] = {15, 20, 25, 35, 45, 60, 65, 70};
   int b[n2] = {10, 30, 40, 50, 55};
   int c[n1 + n2];
   int i;
   clrscr();
   mergArr(a, n1, b, n2, c, n1 + n2);
   for(i = 0; i < n1 + n2; i++)
   {
       cout.width(3);
       cout << c[i];
   }
   getch();
   return 0;
}

