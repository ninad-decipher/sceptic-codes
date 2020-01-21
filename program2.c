#include<stdio.h>
#include<string.h>
int compare(char[],char[]);
int search(char[],char[]);
int main()
{
int loc;
char str[25],pat[25],rep[25],t[25],d[25];
int ls=0,lp=0,lr=0;
int i,j,l,ll=0,k=0;
printf("Enter main string\n");
scanf("%s",str);
printf("Enter pattern string\n");
scanf("%s",pat);
printf("Enter replace string\n");
scanf("%s",rep);
if(search(str,pat)==-1)
printf("\n Pattern not found");
else
{
//find the length of the string 
for(i=0;str[i]!='\0';i++)
ls++;
for(i=0;pat[i]!='\0';i++)
lp++;
for(i=0;rep[i]!='\0';i++)
lr++;
//string replacement
for(i=0;i<ls;i++)
{
for(j=0;j<lp;j++)
t[j]=str[i+j];
t[j]='\0';
if(compare(t,pat)==0)
{
k++;
for(l=0;l<lr;l++)
{
d[ll]=rep[l];
ll++;
}
i=i+(lp-1);
}
else
{
d[ll]=str[i];
ll++;
}
}
d[ll]='\0';
printf("\n The number of string=%d\n",k);
printf("\n The original string is=%s\n",str);
printf("\n The pattern string=%s\n",pat);
printf("\n The replacement string=%s\n",rep);
printf("\n The string after replacement=%s\n",d);
}
}
int search(char src[],char str[])
{
int i,j,firstOcc;
i=0,j=0;
{
while(src[i]!=str[0]&&src[i]!='\0')
i++;
if(src[i]=='\0')
return -1;
firstOcc=i;
while(src[i]==str[j]&&src[i]!='\0'&&str[j]!='\0')
{
i++;
j++;
}
if(str[j]=='\0')
return(firstOcc);
if(src[i]=='\0')
return (-1);
i=firstOcc+1;
j=0;
}
}
int compare(char str1[25],char str2[25])
{
int i=0;
while(str1[i]==str2[i]&&str1[i]!='\0')
i++;
if(str1[i]>str2[i])
return 1;
else if(str1[i]<str2[i])
return -1;
else
return 0;
}

