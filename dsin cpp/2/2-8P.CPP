#include "iostream.h"
#include "conio.h"
#define M 21
class stack {
  public:
     stack();
     void  push(float);
     float pop();
  private:
     int myTop;
     float items[M];
};
//*****************
stack::stack()
{
  myTop = -1;
}
//******************
void stack::push(float x)
{
   items[++myTop] = x;
}
//******************
float stack::pop()
{
   return  items[myTop--];
}
//**************
int   isDigit(char);
float evaluate(char []);
float operate(char, float, float);
int main()
{
   char postfix[M];
   clrscr();
   cout << "Enter a postfix expression:";
   cin.get(postfix, M);
   cout.precision(2);
   cout << "Evaluation of expression is:" << evaluate(postfix);
   getch();
   return 0;
}
//*****************
float evaluate(char postfix[])
{
    float value, operand1, operand2;
    char symbol;
    stack s;
    for(int i = 0; postfix[i]; i++)
    {
       symbol = postfix[i];
       if(isDigit(symbol))
	   s.push((float)(symbol - '0'));
       else
       {
	   operand2 = s.pop();
	   operand1 = s.pop();
	   value = operate(symbol, operand1, operand2);
	   s.push(value);
       }//end of else
    }//end of for
    value = s.pop();
    return value;
}
//**************
int isDigit(char symbol)
{
   return (symbol >= '0' && symbol <= '9');
}
//**************
float operate(char symbol, float operand1, float operand2)
{
   switch(symbol)
   {
      case '+':
	 return operand1 + operand2;
      case '-':
	 return operand1 - operand2;
      case '*':
	 return operand1 * operand2;
      case '/':
	 return operand1 / operand2;
   }
}
