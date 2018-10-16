#include<iostream>
#include<conio.h>
#include<string>
#include"nodestack.h"
#include"sstack.h"

using namespace std;
int main()
{
string postfix;
cout<<"enter postfix equation"<<endl;
getline(cin, postfix);

nodestack *topp=NULL;
nodestack operands;  //node type stack for var and their values
sstack var;  //to separate variables from equation
int top=0;
operands.getvariables(postfix,var,top);
operands.operandnode(topp,var,operands);
sstack output;
output.if_char(postfix,top);
output.evaluate(postfix,top);
char op;   //operand can be a var or number
system("pause");
return 0;
}


 

   
  
