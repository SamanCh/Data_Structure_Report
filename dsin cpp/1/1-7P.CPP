#include "iostream.h"
#include "conio.h"
template <class T>
void multiply(T m1[][3], T m2[][4], T m3[][4])
{
     //multiply mat1 by mat2
     for(int i = 0 ; i < 2 ; i++)
	for(int j = 0 ; j < 4 ; j++)
	  for(int k = 0 ;k < 3 ; k ++)
	      m3[i][j] = m3[i][j] + m1[i][k] * m2[k][j];
}
//***************************
int main()
{
     int m1[2][3], m2[3][4], m3[2][4] = {0} ;
     int i, j ;
     clrscr();
     //read mat1
     for(i = 0 ; i < 2 ; i++)
       for(j = 0 ; j<3 ;j++)
       {
	 cout << "Enter m1[" << i << "][" << j << "]:";
	 cin >> m1[i][j] ;
       }
     //read mat2
     for(i = 0 ; i < 3 ; i++)
       for(j = 0 ; j < 4 ; j++)
       {
	 cout << "Enter m2[" << i << "][" << j << "]:";
	 cin >> m2[i][j] ;
       }
     multiply(m1, m2, m3);
     cout << "\n Produc of mat1 & mat2 is : \n" ;
     for(i = 0 ;i < 2 ; i++) {
       for(j = 0 ; j < 4 ; j++)
       {
	  cout.width(5);
	  cout << m3[i][j];
       }
       cout << "\n";
     }
     getch();
     return 0;
}
