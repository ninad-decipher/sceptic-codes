#include<stdio.h>
#include<string.h>
int F(char symbol)
{
switch (symbol)
{
case '+':
case '-':return 2;
case '%':
case '*':
case '/':return 4;
case '^':
case '$':return 5;
case '(':return 0;
case '#':return -1;
default :return 8;
}
}
int G(char symbol)
{
switch (symbol)
{
case '+':
case '-':return 1;
case '%':
case '*':
case '/':return 3;
case '^':
case '$':return 6;
case '(':return 9;
case ')':return 0;
default:return 7;
}
}
void infix_postfix(char in[],char po[])
{
int i,j,top=-1;
char s[40],symbol;
s[++top]='#';
j=0;
for(i=0;i<strlen(in);i++)
{
symbol=in[i];
while(F(s[top])>G(symbol))
{
po[j]=s[top--];
j++;
}
if(F(s[top])!=G(symbol))
s[++top]=symbol;
else
top--;
}
while(s[top]!='#')
{
po[j++]=s[top--];
}
po[j]='\0';
}
void main()
{
int i,c=0;
char infix[30],postfix[30];
printf("Enter the infix expression\n");
scanf("%s",infix);
for(i=0;i<strlen(infix);i++)
{
if(infix[i]=='(')
c++;
if(infix[i]==')')
c--;
}
if(c==0)
{
infix_postfix(infix,postfix);
printf("Postfix for an infix expression is:\n");
printf("%s\n",postfix);
}
else
printf("Invalid expression\n\n");
}







