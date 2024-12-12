#include<stdio.h>
#include<ctype.h>
#define SIZE 50
char stack[SIZE];
int top=-1;
int push(char elem)
{
stack[++top]=elem;
}
char pop()
{
return(stack[top--]);
}
int prec(char symbol)
{
if(symbol=='^')
{
return(3);
}
else if(symbol=='*'||symbol=='/')
{
return(2);
}
else if(symbol=='+'||symbol=='-')
{
return(1);
}
else
{
return(0);
}
}
void main()
{
char infix[50],postfix[50],ch,ele;
int i=0,j=0;
printf("Enter infix expression:");
scanf("%s",infix);
push('#');
while((ch=infix[i++])!='\0')
{
if(ch=='(')
{
push(ch);
}
else if(isalpha(ch))
{
postfix[j++]=ch;
}
else if(ch==')')
{
while(stack[top]!='(')
{
postfix[j++]=pop();
}
ele=pop();
}
else
{
while(prec(stack[top])>=prec(ch))
{
postfix[j++]=pop();
}
push(ch);
}
}
while(stack[top]!='#')
{
postfix[j++]=pop();
}
postfix[j]='\0';
printf("\n Postfix Expression=%s\n",postfix);
}
