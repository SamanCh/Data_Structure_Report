#include "iostream.h"
#include "conio.h"
template <class T>
void sTranspose(T b[5][3], T bt[5][3])
{
   int i, j, k;
   int m = b[0][1]; //number of columns
   int t = b[0][2]; //number of non zero elements
   bt[0][0] = m;
   bt[0][1] = b[0][0];
   bt[0][2] = t;
   k = 1;
   for(i = 0; i < m; i ++)
      for(j = 1; j <= t; j ++)
	 if(i ==b[j][1])
	 {
	    bt[k][0] = b[j][1];
	    bt[k][1] = b[j][0];
	    bt[k][2] = b[j][2];
	    k ++;
	 }
}
//************************
int main()
{
  int i, j, b[5][3], bt[5][3];
  clrscr();
  for(i = 0; i < 5; i ++)
     for(j = 0; j < 3; j ++)
     {
	cout << "Enter b[" << i << "][" << j << "]:";
	cin >> b[i][j];
     }
  sTranspose(b, bt);
  cout << "Transpose of sparse matrix b:\n";
  for(i = 0; i < 5; i ++)
  {
     for(j = 0; j < 3; j ++)
     {
	cout.width(5);
	cout << bt[i][j];
     }
    cout << "\n";
  }
  getch();
  return 0;
}



