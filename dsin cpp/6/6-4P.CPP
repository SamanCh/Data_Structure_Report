#include <iostream.h>
#include <conio.h>
#define INFINITY 100
#define MEMBER 1
#define NOMEMBER 0
#define M 5
void shortest(int w[][M], int s, int t, int *pd)
{
   int distance[M], found[M];
   int current, i, k, dc;
   int smallDist, newDist;
   //initialization
   for(i = 0; i < M; i++)
   {
      found[i] = NOMEMBER;
      distance[i] = INFINITY;
   }
   found[s] = MEMBER;
   distance[s] = 0;
   current = s;
   while(current != t)
   {
      smallDist = INFINITY;
      dc = distance[current];
      for(i = 0; i < M; i++)
	 if(found[i] == NOMEMBER)
	 {
	     newDist = dc + w[current][i];
	     if(newDist < distance[i])
		 distance[i] = newDist;
	     //determine the smallest distance
	     if(distance[i] < smallDist)
	     {
		 smallDist = distance[i];
		 k = i;
	     }
	 }//end of for, if
      found[k] = MEMBER;
      current = k;
   }//end of while
   *pd = distance[t];
}
//********************
int main()
{
   int w[M][M] = {{100, 7  , 4  , 6  ,  1},
		  {100, 100, 100, 100, 100},
		  {100, 2  , 100, 5  , 100},
		  {100, 3  , 100, 100, 100},
		  {100, 100, 100, 1  , 100}};
    int pd, s = 0, t = 1;
    clrscr();
    shortest(w, s, t, &pd);
    cout << "Source is:" << s << ", Destination is:" << t;
    cout << "\nLength of shortest path is:" << pd;
    getch();
    return 0;
}
