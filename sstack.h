#include<iostream>
using namespace std;

class sstack 
{
  private:
char data[20];
int top=0;

public:
sstack()
{
  for( int i=0;i<=20;i++ )
  {
  this->data[i]=0;
  }
  this->top=0;
}
int gettop()
{
  return top;
}
int pop()
{
return this->data[--top];
}
void push(int top,float val)
{
this->top=top+1;
this->data[top]=val;
}
void if_char(string postfix,int top)
{
  for(int i=0;i<postfix.length();i++)
  {
    while(postfix[i] < 40)
    {
      this->push(top,postfix[i]);
    }
   
  }
}
int evaluate(string postfix,int top)
{
  for(int i=0;i<postfix.length();i++)
  {
 if(postfix[i]>47 && postfix[i]<40)
    {
       char op1=this->pop();
      char op2=this->pop();
      float val;
    if(postfix[i]= '+')
    {
     val=op1 + op2;
     this->push(top,val);
    }
    if(postfix[i]= '-')
    {
     val=op1 - op2;
     this->push(top,val);
    }
    if(postfix[i]= '*')
    {
     val=op1 * op2;
     this->push(top,val);
    }
    if(postfix[i]= '/')
    {
     val=op1 / op2;
     this->push(top,val);
    }
   
    }
  }
  this->pop();
}
};