#include "iostream.h"
#include "conio.h"
#define M 21
class stack {
  public:
    stack();
    void push(char);
    char pop();
    int  empty();
    void popAndTest(char &, int &);
    void topAndTest(char &, int &);
  private:
    int myTop;
    char items[M];
};
//**************
stack::stack()
{
   myTop = -1;
}
//**************
void stack::push(char x)
{
   items[++myTop] = x;
}
//**************
char stack::pop()
{
  return items[myTop--];
}
//**************
int stack::empty()
{
  return (myTop == -1);
}
//**************
void stack::popAndTest(char &x, int &underflow)
{
   if(empty())
     underflow = 1;
   else
   {
     x = items[myTop--];
     underflow = 0;
   }
}
//****************
void stack::topAndTest(char &x, int &underflow)
{
   if(empty())
     underflow = 1;
   else
   {
     x = items[myTop];
     underflow = 0;
   }
}
//**************
int  isOperand(char);
void convert(char[], char[]);
int  pred(char, char);
int main()
{
   char infix[M], postfix[M];
   clrscr();
   cout << "Enter an infix expression:";
   cin.get(infix, M);
   convert(infix, postfix);
   cout << "Postfix expression is:";
   for(int i = 0; postfix[i]; i++)
      cout << postfix[i] << " ";
   getch();
   return 0;
}
//*****************
void convert(char infix[], char postfix[])
{
  char symbol, topSymbol;
  int underflow, j = 0;
  stack s;
  for(int i = 0; infix[i]; i ++)
  {
       symbol = infix[i];
       if(isOperand(symbol))
	   postfix[j++] = symbol;
       else  if(symbol == '(')
	      s.push(symbol);
       else if(symbol == ')')
       {
	   topSymbol = s.pop();
	   while(topSymbol != '(')
	   {
	      postfix[j++] = topSymbol;
	      topSymbol = s.pop();
	   }//end of while
       } //end of else if
       else
       {
	      s.topAndTest(topSymbol, underflow);
	      //if op1 > op2 then true
	      if(s.empty() || (!pred(topSymbol, symbol)))
		  s.push(symbol);
	      else
	      {
		 s.popAndTest(topSymbol, underflow);
		 while(pred(topSymbol, symbol) && !underflow)
		 {
		     postfix[j++] = topSymbol;
		     s.popAndTest(topSymbol, underflow);
		 }
		 s.push(symbol);
	      } //end of else
       }//end of else
  }//end of for
  while(!s.empty())
  {
	topSymbol = s.pop();
	postfix[j++] = topSymbol;
  }
  postfix[j] = '\0';
}
//*****************
int isOperand(char symbol)
{
   if(symbol >= '0' && symbol <= '9')
       return 1;
   return 0;
}
//****************
int pred(char op1, char op2)
{
    int i, p1, p2;
    /*  ( + - * / % */
    static char op[] = {'(','+', '-', '*', '/','%','\0'};
    static int isp[] = {0, 12, 12, 13, 13, 13};
    for(i = 0; op[i]; i ++)
	if(op[i] == op1)
	{
	   p1 = i;
	   break;
	}
    for(i = 0; op[i]; i ++)
	if(op[i] == op2)
	{
	   p2 = i;
	   break;
	}
    if(isp[p1] >= isp[p2])
       return 1;
    return 0;
}

