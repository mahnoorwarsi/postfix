#include<iostream>
using namespace std;
class stack
{
  private:
  int array[100];
  int  top;

  public:
  stack()
  {
    for(int i=0;i<100;i++)
  {
    this->array[i]=0;
  }
    this->top=0;
    
  }
  int gettop()
  {
    return top;
  }
  void push(int top,int val)
  {
    
    if(gettop()==0)
    {
      int i = top;
      array[top]=val;
      top++;
      
    }
    else{
      cout<<"stack overflow"<<endl;
    }
  }
  int pop()
  {
    if(this->gettop()==0)
    {
      cout<<"stack underflow"<<endl;
    }
    else
    this->array[top--];
    return gettop();
  }
 void display(int top)
  {
    cout<<"output postfix equation is "<<endl;
    for(int i=top;i<0;i--)
    {
      cout<<this->array[i]<<endl;
    }
  }
int precedance(char op)
{
  if(op == '/' || op == '*')
  {
    return 6;
  }
  else if(op == '+' || op == '-')
  {
    return 5;
  }
  else if(op == '<' || op == '>' || op == '=' || op == '~' )
  {
    return 4;
  }
  else if(op == '&' )
  {
    return 3;
  }
  else if(op == '|')
  {
    return 2;
  }
  else if(op == '(')
  {
  return 1;
  }
}

int getoutput(string infix, stack postfix ,stack operators, int top)
  {
    
    for(int i=0;i<infix.length();i++)
  {
    if(infix[i] > 'a' && infix[i] < 'z' || infix[i] > 'A' && infix[i] < 'Z' )
    {
    postfix.push(top,infix[i]);
  }
    else if(infix[i] > 47 && infix[i] < 40)
    {
      if(infix[i] == '(' && postfix.gettop() !=0)
      {
        operators.push(top,infix[i]);
      }
      else if(infix[i] == ')' && postfix.gettop() !=0)
      {
        while(operators.gettop()!= '(')
        {
          int x;
        x=operators.pop();
        postfix.push(top,x);
        }
      }
      else
      {
      while(postfix.gettop()!=100 && precedance(operators.gettop()) < precedance(infix[i])  )
      {
        operators.push(top,infix[i]);
      }
      while(postfix.gettop()!=100 && precedance(operators.gettop()) >= precedance(infix[i])  )
      {
        int x;
        x=operators.pop();
        postfix.push(top,x);
        operators.push(top,infix[i]);
      }
      }
      
    }
  }
  }
 
};