#include <iostream>
#include <map>
using namespace std;   int main()
{
   map <char, int> m;
   int i;
   for(i = 0; i < 26; i ++)
      m.insert(pair <char, int> ('A' + i, 65 + i));
   char ch;
   cout << "enter key(A-Z) :";
   cin >> ch;
   map <char, int>::iterator p;
   p = m.find(ch);
   if(p != m.end())
       cout << "\its ASCII value is : " << p -> second;
   else
       cout << "\nkey not in map.";
   return 0;
}
