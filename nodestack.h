#include<iostream>
#include"sstack.h"
using namespace std;

class nodestack 
{
  private:
int data;
char operand;
nodestack * next;

public:
nodestack()
{
  this->data=0;
  this->operand=0;
  this->next=NULL;
}
int pop(nodestack **top)
{
 cout<<"entering pop"<<endl; 
if(*top==0)
{
  return 0;
  
}
else 
{
  int temp=(*top)->data;
  nodestack *curr=*top;
  *top=(*top)->next;
  free(curr);
  cout<<"top value popped"<<endl;
  return temp;
}

}
nodestack * newnode(int val,char op)
{
  cout<<"creating node type stack"<<endl;
  nodestack * ptr=new nodestack;
  ptr->data=val;
  ptr->operand=op;
  ptr->next=NULL;
return ptr;
}

void push(nodestack **topp,int val,char op)
{
    cout<<"entering push"<<endl;
  if(*topp==NULL)
  {
    cout<<"if top is null"<<endl;
    *topp=newnode(val,op);
    cout<<"stack created"<<endl;
  }
  else
  {
    nodestack *temp;
  temp=newnode(val,op);
  temp->next=(*topp);
  *topp=temp;
  //*top=temp;
  //(*top)->next=newnode(val);
  //free(temp);
    cout<<"node pushed"<<endl;

  }
}

void getvariables(string postfix,sstack var,int top)
{
  int i;
    for(i=0;i<postfix.length();i++)
  {
    if(postfix[i] > 'a' && postfix[i] < 'z' || postfix[i] > 'A' && postfix[i] < 'Z' )
    {
      var.push(top,postfix[i]);
    }    
  }
}
void operandnode(nodestack *topp,sstack var,nodestack operands)
{
  for(int i=var.gettop();i<=0;i--)
  {
    cout<<"enter values for: "<< var.pop()<<endl;
   char op=var.pop();
   cin>>data;
    operands.push(&topp,data,op);
  }
  
}


};