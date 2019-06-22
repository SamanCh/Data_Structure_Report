#include "iostream.h"
#include "conio.h"
template <class T>
void shell(T a[], const int n, int numinc, int incrmnt[])
{
   int i, j, k, span, y;
   for(i = 0; i < numinc; i++)
   {
     span = incrmnt[i];
     for(j = span; j < n; j++)
     {
	//insert element a[j] into its proper
	//position within its subfile
	y = a[j];
	for(k = j - span; k >= 0 && y < a[k]; k -= span)
	   a[k + span] = a[k];
	a[k + span] = y;
     }//end of for
   }
}
//**********************
int main()
{
   const int n = 8;
   int a[n] = {25, 57, 48, 37, 12, 92, 86, 33};
   int incrmnt[3] = {5, 3, 1};
   int numinc = 3;
   int i;
   clrscr();
   shell(a, n, numinc, incrmnt);
   for(i = 0; i < n; i++)
   {
       cout.width(4);
       cout << a[i];
   }
   getch();
   return 0;
}
