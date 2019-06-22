#include "iostream.h"
#include "conio.h"
template <class T>
void subAdd(T a[][3], T b[][3], T sub[][3], T add[][3])
{
   const int n = 3;
   int i, j;
   for(i = 0; i < n; i ++)
       for(j = 0; j < n; j ++)
       {
	   sub[i][j] = a[i][j] - b[i][j];
	   add[i][j] = a[i][j] + b[i][j];
       }
}
//****************************
int main()
{
   const int n = 3;
   int i, j, a[n][n], b[n][n], sub[n][n], add[n][n];
   clrscr();
   //read a[n][n]
   for(i = 0; i < n; i ++)
       for(j = 0; j < n; j ++)
       {
	  cout << "Enter a[" << i <<"][" << j <<"]:";
	  cin >> a[i][j];
       }
   //read b[n][n]
   for(i = 0; i < n; i ++)
       for(j = 0; j < n; j ++)
       {
	  cout << "Enter a[" << i <<"][" << j <<"]:";
	  cin >> b[i][j];
       }
   subAdd(a, b, sub, add);
   //print sub[n][n]
   cout << "sub[n][n] is:\n";
   for(i = 0; i < n; i ++)
   {
       cout.width(5);
       for(j = 0; j < n; j ++)
       {
	  cout.width(5);
	  cout <<  sub[i][j] ;
       }
       cout << "\n";
   }
   cout << "add[n][n] is:\n";
   for(i = 0; i < n; i ++)
   {
       for(j = 0; j < n; j ++)
       {
	  cout.width(5);
	  cout <<  add[i][j] ;
       }
       cout << "\n";
   }
   getch();
   return 0;
}
