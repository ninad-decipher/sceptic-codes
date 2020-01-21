#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void towers(int,char,char,char);
int i,top;
float op1,op2,res;
char symbol,postfix[20];
float s[30];
float value[20];
float compute()
{
switch(symbol)
{
case'+':return op1+op2;
case'-':return op1-op2;
case'*':return op1*op2;
case'%':return((int)op1%(int)op2);
case'/':
if(op2==0)
{
printf("Operation cannot be performed because dividing by zero\n\n");
exit(0);
}
return op1/op2;
case'^':return pow(op1,op2);
}
}
void main()
{
int choice,num;
while(1)
{
i=0;
printf("\n Stack opertaion\n");
printf("\n 1.Evaluation of suffix expression");
printf("\n 2.Solving tower of Hanoi problem with n disks");
printf("\n 3.Exit");
printf("\n Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Enter the suffix expression\n\n\n");
scanf("%s",postfix);
top=-1;
while(postfix[i]!='\0')
{
if(isalpha(postfix[i]))
{
printf("Enter the value for %c\n",postfix[i]);
scanf("%f",&value[i]);
}
i++;
}
for(i=0;i<strlen(postfix);i++)
{
symbol=postfix[i];
if(isalpha(postfix[i]))
{
s[++top]+value[i];
}
else
{
op2=s[top--];
op1=s[top--];
res=compute();
s[++top]=res;
}
}
printf("The value after solving postfix expression is %f\n",res);
break;
case 2:printf("Enter the number of disks:");
scanf("%d",&num);
printf("The sequence of moves involved in the Towers of Hanoi are:\n");
towers(num,'A','C','B');
break;
case 3: return;
default:printf("\n Enter a valid choice\n");
}
}
}
void towers(int num,char frompeg,char topeg, char auxpeg)
{
if(num==1)
{
printf("\n Move disk1 frompeg%c to peg%c",frompeg,topeg);
return;
}
towers(num-1,frompeg,auxpeg,topeg);
printf("\n Move disk%d from peg%c to peg%c",num,frompeg,topeg);
towers(num-1,auxpeg,topeg,frompeg);
}








