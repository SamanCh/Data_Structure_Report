#include "iostream.h"
#include "conio.h"
template <class T>
void transpose(T m[3][4], T t[4][3])
{
     for(int i = 0 ; i < 4 ; i++)
	for(int j = 0 ; j < 3 ; j++)
	    t[i][j] = m[j][i];
}
//*********************
int main()
{
     int m[3][4], t[4][3] ;
     int i, j ;
     clrscr();
     //read m[3][4]
     for(i = 0 ; i < 3 ; i++)
       for(j = 0 ; j < 4 ;j++)
       {
	 cout << "Enter m[" << i << "][" << j << "]:";
	 cin >> m[i][j] ;
       }
     transpose(m, t);
     cout << "\n Transpose of m is : \n";
     for(i = 0 ;i < 4 ; i++)
     {
       for(j = 0 ; j < 3 ; j++)
       {
	  cout.width(5);
	  cout << t[i][j] ;
       }
       cout << "\n" ;
     }
     getch();
     return 0;
}
