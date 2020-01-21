#include<stdio.h>
#include<stdlib.h>
struct node
{
char ssn[10],name[10],dept[10],desig[10],phno[12];
int sal;
struct node*llink;
struct node*rlink;
};
typedef struct node*NODE;
NODE temp,FIRST=NULL,END=NULL;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
return x;
}
void read()
{
temp=getnode();
temp->llink=NULL;
temp->rlink=NULL;
printf("Enter SSN");
scanf("%s",temp->ssn);
printf("Enter Name");
scanf("%s",temp->name);
printf("Enter Department");
scanf("%s",temp->dept);
printf("Enter Designation");
scanf("%s",temp->desig);
printf("Enter Phno");
scanf("%s",temp->phno);
printf("Enter salary");
scanf("%d",&temp->sal);
}
void create_DLL()
{
int n,i=1;
printf("Enter the number of Employees ");
scanf("%d",&n);
while(i<=n)
{
printf("Enter the details of %d Employee\n",i++);
read();
if(FIRST==NULL)
{
FIRST=temp;
END=temp;
}
else
{
END->rlink=temp;
temp->llink=END;
END=temp;
}
}
}
void display_count()
{
temp=FIRST;
int count=1;
printf("Employee details:\n");
if(FIRST==NULL)
{
printf("Employee detail is NULL and count is %d",count-1);
}
else
{
while(temp!=END)
{
count++;
printf("%s\t%s\t%s\t%s\t%s\t%d\n",temp->ssn,temp->name,temp->dept,temp->desig,temp->phno,temp->sal);
temp=temp->rlink;
}
printf("%s\t%s\t%s\t%s\t%s\t%d\n",temp->ssn,temp->name,temp->dept,temp->desig,temp->phno,temp->sal);
printf("Employee count:%d",count);
}
return;
}
void Insertionfront()
{
printf("Enter the detais of the employee\n");
read();
if(FIRST==NULL)
{
FIRST=temp;
END=temp;
}
else
{
temp->rlink=FIRST;
FIRST->llink=temp;
FIRST=temp;
}
}
void Insertionend()
{
printf("Enter the detais of new employee\n");
read();
if(FIRST==NULL)
{
FIRST=temp;
END=temp;
}
else
{
END->rlink=temp;
temp->llink=END;
END=temp;
}
return;
}
void Deletionfront()
{
temp=FIRST;
if(FIRST==NULL)
{
printf("List is empty\n");
}
else if(FIRST==END)
{
printf("Deleted element is %s\n",temp->ssn);
FIRST=FIRST->rlink;
FIRST->llink=NULL;
free(temp);
}
else
{
printf("Deleted element is %s",temp->ssn);
FIRST=FIRST->rlink;
FIRST->llink=NULL;
free(temp);
}
return;
}
void Deletionend()
{
temp=END;
if(FIRST==NULL)
{
printf("List is empty");
}
else if(FIRST==END)
{
printf("Deleted element is %s\n",temp->ssn);
FIRST=NULL;
END=NULL;
free(temp);
}
else
{
printf("Deleted element is %s",temp->ssn);
END=END->llink;
END->rlink=NULL;
free(temp);
}
return;
}
void main()
{
int choice;
while(1)
{
printf("----MENU----\n");
printf("1.Create a DLL of N employee\n");
printf("2.Display DLL\n");
printf("3.Insertion at front\n");
printf("4.Insertion at end\n");
printf("5.Deletion from front\n");
printf("6.Deletion from end\n");
printf("7.Exit\n");
printf("Enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1: create_DLL();
	break;
case 2: display_count();
	break;
case 3: Insertionfront();
	break;
case 4: Insertionend();
	break;
case 5: Deletionfront();
	break;
case 6: Deletionend();
	break;
case 7: return;
default:printf("\n Invalid choice\n");
}
}
}

