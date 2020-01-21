#include<stdio.h>
#include<stdio_ext.h>
#define max 10
int create(int);
void linear_prob(int[],int);
void display(int []);
void main()
{int a[max],num,i,choice;
for(i=0;i<max;i++)
a[i]=-1;
while(1)
{printf("collision handeling by linear probing");
printf("\n1.insert into hash table\n2.display hash table\n3.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{case 1:linear_prob(a,num);
        break;
case 2:display(a);
break;
case 3:return;
}
}
}
int create(int num)
{int key;
key=num%10;
return key;
}
void linear_prob(int a[max],int num)
{int flag,i,key,count;
char ans='y';
while(ans=='y')
{flag=0;
count=0;
printf("\n enter 4 digit key:");
scanf("%4d",&num);
key=create(num);
if(a[key]==-1)
a[key]=num;
else
{printf("\n collision detected\n");
i=0;
while(i<max)
{if(a[i]!=-1)
count++;
i++;
}
printf("collision avoided using linear probe\n");
if(count==max)
{printf("\n hash table is full\n");
display(a);
return;
}
for(i=key+1;i<max;i++)
if(a[i]==-1)
{a[i]=num;
flag=1;
break;
}
i=0;
while((i<key)&&(flag==0))
{if(a[i]==-1)
{a[i]=num;
flag=1;
break;
}
i++;
}
}
printf("do you wish to continue?(y/n)");
fflush(stdin);
scanf(" %c",&ans);
}
}
void display(int a[max])
{int i;
printf("\n the has table is\n");
for(i=0;i<max;i++)
printf("%d\t%d\n",i,a[i]);
}
