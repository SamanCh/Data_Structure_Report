#include "iostream.h"
#include "conio.h"
template <class T>
void readArray(T x[][3], int row)
{
 int i,j;
 for(i = 0; i < row; i ++)
 {
     cout << "Enter three numbers for row " << i << ":";
     for(j = 0; j < 3; j ++)
	cin >> x[i][j];
 }
}
//***************************
template <class T>
void add(T a[4][3], T b[5][3], T c[5][3])
{
  int i, j, k, x, h;
  c[0][0] = a[0][0];
  c[0][1] = a[0][1];
  i = j = k = 1;
  while(i <= a[0][2] && j <= b[0][2])
  {
    switch(compare(a[i][0], b[j][0]))
    {
      case -1:
	  c[k][0] = a[i][0];
	  c[k][1] = a[i][1];
	  c[k][2] = a[i][2];
	  k ++;
	  i ++;
	  break;
      case 0:
	  switch(compare(a[i][1], b[j][1]))
	  {
	    case -1:
	      c[k][0] = a[i][0];
	      c[k][1] = a[i][1];
	      c[k][2] = a[i][2];
	      k ++;
	      i ++;
	      break;
	    case 0:
	      x = a[i][2] + b[j][2];
	      if(x)
	      {
		c[k][0] = a[i][0];
		c[k][1] = a[i][1];
		c[k][2] = x;
		k ++;
	      }//enf of if
	      i ++;
	      j ++;
	      break;
	    case 1:
	      c[k][0] = b[j][0];
	      c[k][1] = b[j][1];
	      c[k][2] = b[j][2];
	      k ++;
	      j ++;
	      break;
	  }
	  break;
      case 1:
	  c[k][0] = b[j][0];
	  c[k][1] = b[j][1];
	  c[k][2] = b[j][2];
	  k ++;
	  j ++;
	  break;
    }
  }//end of while
  for(h = i; h <= a[0][2]; h ++)
  {
       c[k][0] = a[h][0];
       c[k][1] = a[h][1];
       c[k][2] = a[h][2];
       k ++;
  }
  for(h = j; h <= b[0][2]; h++)
  {
      c[k][0] = b[h][0];
      c[k][1] = b[h][1];
      c[k][2] = b[h][2];
      k ++;
  }
     c[0][2] = k - 1;
}
//*********************
template <class T>
int  compare(T x, T y)
{
   if(x < y)
       return -1;
   else if(x == y)
       return 0;
   else
       return 1;
}
//******************
int  main()
{
   int i, j, a[4][3], b[5][3], c[5][3];
   clrscr();
   //read a[4][3]
   cout << "***Read first sparse array***\n";
   readArray(a, 4);
   //read b[5][3]
   cout << "***Read second sparse array***\n";
   readArray(b, 5);
   add(a, b, c);
   cout << "***Sum of two sparse matrix***\n";
   for(i = 0; i < 5; i ++)
   {
       for(j = 0; j < 3; j++)
       {
	  cout.width(5);
	  cout <<  c[i][j];
       }
       cout << "\n";
   }
   getch();
   return 0;
}


