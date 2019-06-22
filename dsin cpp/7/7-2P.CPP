#include "iostream.h"
#include "conio.h"
template <class T>
void quicksort(T a[], int first, int last)
{

   int pos;   //final position of pivot
   if(first < last)
   {
       //split into two sublists
       split(a, first, last, &pos);
       //sort left sublist
       quicksort(a, first, pos - 1);
       //sort right sublidt
       quicksort(a, pos + 1, last);
   }
   //else list has 0 or 1 element
   //and requires no sorting
}
//********************
template <class T>
void split(T a[], int first, int last, int *pos)
{
   int left = first, right = last, pivot = a[first];
   T t;
   while(left < right)
   {
     //search from right for element <= pivot
     while(a[right] > pivot)
	right --;
     //search from right for element <= pivot
     while(left < right && a[left] <= pivot)
	left ++;
     //interchange element if searches havn't met
     if(left < right)
     {
       t = a[left];
       a[left] = a[right];
       a[right] = t;
      }
   } //end of while
   //end of searches. place pivot in correct position
   *pos = right;
   a[first] = a[*pos];
   a[*pos] = pivot;
}
//********************
int main()
{
   const int n = 8;
   int a[n] = {25, 57, 48, 37, 12, 92, 86, 33};
   int i;
   clrscr();
   quicksort(a, 0, n - 1);
   for(i = 0; i < n; i++)
   {
       cout.width(4);
       cout << a[i];
   }
   getch();
   return 0;
}



