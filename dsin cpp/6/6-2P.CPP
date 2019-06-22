#include <iostream.h>
#include <conio.h>
#define M 5
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
//***************
void warshal(int t[][M], int path[M][M])
{
   int i, j, k;
   for(i = 0; i < M; i++)
      for(j = 0; j < M; j++)    //path starts off
	  path[i][j] = t[i][j]; //as ajacent matrix.
   for(k = 0; k < M; k++)
      for(i = 0; i < M; i++)
	 if(path[i][k] == 1)
	      for(j = 0; j < M; j++)
		   path[i][j] = path[i][j] || path[k][j];
}
//*********************
int main()
{
   int path[M][M], i, j;
   int t[M][M] = {{0, 0, 1, 1, 0},
		  {0, 0, 1, 0, 0},
		  {0, 0, 0, 1, 1},
		  {0, 0, 0, 0, 1},
		  {0, 0, 0, 1, 0}};

   clrscr();
   warshal(t, path);
   cout << "The path matrix is:\n";
   print(path);
   getch();
   return 0;
}

