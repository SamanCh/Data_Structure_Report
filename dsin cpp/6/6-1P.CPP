#include <iostream.h>
#include <conio.h>
#define M 5
void prod(int a[][M], int b[][M], int c[][M])
{
   int i, j, k;
   for(i = 0; i < M; i++)
	for(j = 0; j < M; j++)
	{
	   c[i][j] = 0;
	   for(k = 0; k < M; k++)
	       c[i][j] = c[i][j] || (a[i][k] && b[k][j]);
	}//end of for
}
//******************
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
void transClose(int t[][M], int path[M][M])
{
  int i, j, k;
  int newProd[M][M], adjProd[M][M];
  for(i = 0; i < M; i++)
     for(j = 0; j < M; j++)
	adjProd[i][j] = path[i][j] = t[i][j];
  for(i = 1; i < M; i++)
  {
	 //i represent the number of times
	 // t has been multiplied by itself
	 //to obtain adjProd. At this point
	 //path represents all paths of length
	 //i or less
	 prod(adjProd, t, newProd);
	 for(j = 0; j < M; j++)
	     for(k = 0; k < M; k++)
		path[j][k] = path[j][k] || newProd[j][k];
	 for(j = 0; j < M; j++)
	    adjProd[j][k] = newProd[j][k];
  }//end of for i = 1
}
//***************************
int main()
{
   int path[M][M], i, j;
   int t[M][M] = {{0, 0, 1, 1, 0},
		  {0, 0, 1, 0, 0},
		  {0, 0, 0, 1, 1},
		  {0, 0, 0, 0, 1},
		  {0, 0, 0, 1, 0}};

   clrscr();
   transClose(t, path);
   cout << "The path matrix is:\n";
   print(path);
   getch();
   return 0;
}
