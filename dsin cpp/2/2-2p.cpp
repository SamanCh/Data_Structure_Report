#include "iostream.h"
#include "conio.h"
long int fact(int n)
{
  int x, y;
  if(n == 0)
       return 1;
  x = n - 1;
  y = fact(x);
  return n * y;
}
//****************
int main()
{
  int n;
  clrscr();
  cout << "Enter value of n:";
  cin >> n;
  cout << "fact(n) = " << fact(n);
  getch();
  return 0;
}

