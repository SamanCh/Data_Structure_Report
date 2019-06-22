#include <iostream.h>
#include <conio.h>
#define M 4
void print(int a[][M])
{
   int i, j;
   for(i = 0; i < M; i++)
   {
     for(j = 0; j < M; j++)
     {
	cout.width(4);
	cout << a[i][j];
     }
     cout << "\n";
   }
}
//*******************
int min(int x, int y)
{
   if(x < y)
      return x;
   return y;
}
//***************
void shortPath(int w[][M], int spath[M][M])
{
   int i, j, k;
   int q[M][M];
   for(i = 0; i < M; i++)
      for(j = 0; j < M; j++)    //spath starts off
	  spath[i][j] = w[i][j]; //as weight matrix.

   for(k = 0; k < M; k++)
   {
      for(i = 0; i < M; i++)
	 for(j = 0; j < M; j++)
	    q[i][j] = min(spath[i][j], spath[i][k] + spath[k][j]);
      for(i = 0; i < M; i++)
	 for(j = 0; j < M; j++)
	     spath[i][j] = q[i][j];
   }
}
//***********
int main()
{
   int spath[M][M], i, j;
   int w[M][M] = {{7  , 5  , 100, 100},
		  {7  , 100, 100, 2  },
		  {100, 3  , 100, 100},
		  {4  , 100, 1  , 100}};
   clrscr();
   shortPath(w, spath);
   cout << "Short path matrix is:\n";
   print(spath);
   getch();
   return 0;
}

