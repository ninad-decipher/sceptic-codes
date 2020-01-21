#include<stdio.h>
#define max 5
int front,rear;
char q[max];
void enqueue(void);
void dequeue(void);
void qdisplay(void);
void main()
{
int choice;
front=rear=-1;
while(1)
{
printf("\n circular queue operation\n");
printf("\n1.Insert");
printf("\n2.Delete");
printf("\n3.Display");
printf("\n4.Exit");
printf("\n Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: enqueue();
	break;
case 2: dequeue();
	break;
case 3: qdisplay();
	break;
case 4: return;
	break;
default: printf("Invalid choice");
	break;
}
}
}
void enqueue(void)
{
char x;
if((front==0&&rear==max-1)||(front==rear+1))
{
printf("\nQueue is overflow\n");
return;
}
if(front==-1)
{
front=rear=0;
}
else
{
if(rear==max-1)
{
rear=0;
}
else
{
rear++;
}
}
printf("Enter your character:");
fflush(stdin);//it starts with double underscore
scanf("%s",&x);
q[rear]=x;
printf("\n %c successfully inserted\n",x);
return;
}
void dequeue(void)
{
char y;
if(front==-1)
{
printf("\n Queue is underflow\n");
return;
}
y=q[front];
if(front==rear)
{
front=rear=-1;
}
else
{
if(front==max-1)
{
front=0;
}
else
{
front++;
}
}
printf("\n %c successfully deleted\n",y);
return;
}
void qdisplay(void)
{
int i, j,c[100];
if(front==rear==-1)
{
printf("\n q is empty\n");
return;
}
printf("\n element are:\n");
for(i=front;i!=rear;i=(i+1)%max)
{
printf("%c\t",q[i]);
}
printf("%c\n",q[rear]);
return;
}
