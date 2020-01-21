#include<stdio.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top=-1;
void push(void);
void pop(void);
void display(void);
int palindrome(void);
void main()
{
int choice;
while (1)
{
printf("STACK OPERATION\n");
printf("\t 1.PUSH");
printf("\t 2.POP");
printf("\t 3.DISPLAY");
printf("\t 4.PALINDROME");
printf("\t 5.EXIT");
printf("\n ENTER YOUR CHOICE");
scanf("%d",&choice);
switch (choice)
{
case 1: push();
	break;
case 2: pop();
	break;
case 3: display();
	break;
case 4: if(palindrome()==0)
printf("\n STACK HAS PALINDROME CONTENT\n");
else
printf("\n STACK HAS NO PALINDROME CONTENT\n");
	break;
case 5: return;
default:printf("ENTER A VALID CHOICE");
}
}
}
void push()
{
int c;
if(top==(MAXSIZE-1))
{
printf("\nSTACK OVERFLOW\n");
return;
}
else
{
printf("ENTER THE ELEMENT TO BE PUSHED\n");
scanf("%d",&c);
stack[++top]=c;
}
return;
}
void pop()
{
if(top==-1)
{
printf("\nSTACK UNDERFLOW\n");
}
else
{
printf("POPED ELEMENT IS=%d\n",stack[top--]);
}
}
void display()
{
int i;
if(top==-1)
{
printf("\nSTACK UNDERFLOW\n");
return;
}
else
{
printf("\nTHE ELEMENTS OF STACK ARE:\n");
for(i=top;i>=0;i--)
printf("%d\n",stack[i]);
}
}
int palindrome()
{
int rev[MAXSIZE];
int i,j;
for(i=0;i<=top;i++)
rev[i]=stack[i];
for(i=0,j=top;i<=top;i++,j--)
{
if(rev[i]==stack[j])
continue;
else
return -1;
}
return 0;
}


