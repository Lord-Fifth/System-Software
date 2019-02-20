#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 11
char l[10];
struct sym
{
int add;
char label[10];
}sy[11];
void search();
void main()
{
int a[MAX],num,key,i,ch;
char ans;
int create(int);
void lprob(int[],int,int);
void display(int[]);
for(i=0;i<MAX;i++)
a[i]=0;
do
{
printf("\nSELECT\n1.Create an entry in symbol table\n2.Search for label in symbol table\n3.EXIT\n");
scanf("%d",&ch);
if (ch==1)
{
printf("\nEnter address\n");
scanf("%d",&num);
key=create(num);
printf("\nEnter label\n");
scanf("%s",l);
lprob(a,key,num);
display(a);
}
else if(ch==2)
 search();
else 
 break;
}while(ch<=3);
}
int create(int num)
{
int key;
key=num%11;
return key;
}
void lprob(int a[MAX],int key,int num)
{
int flag,i,count=0;
void display(int a[]);
flag=0;
if(a[key]==0)
{
a[key]=num;
sy[key].add=num;
strcpy(sy[key].label,l);
}
else
{
i=0;
while(i<=MAX)
{
if(a[i]!=0)
count++;
i++;
}
if(count==MAX)
{
printf("\nHash table full\n");
display(a);
exit(1);
}
for(i=key+1;i<MAX;i++)
if(a[i]==0)
{
a[i]=num;
flag=1;
sy[key].add=num;
strcpy(sy[key].label,l);
break;
}
for(i=0;i<key&&flag==0;i++)
if(a[i]==0)
{
a[i]=num;
flag=1;
sy[key].add=num;
strcpy(sy[key].label,l);
break;
}}}
void display(int a[MAX])
{
FILE *fp;
int i;
fp=fopen("symbol.txt","w");
printf("\nSymbol Table");
printf("\nHash values \taddress\t   label");
for(i=0;i<MAX;i++)
{
printf("\n%d\t\t%d\t\t%s",i,sy[i].add,sy[i].label);
fprintf(fp,"\n%d\t%d\t%s",i,sy[i].add,sy[i].label);
}
fclose(fp);
}
void search()
{
FILE *fp1;
char la[10];
int set=0,s;
int j,i;
printf("\nEnter label\n");
scanf("%s",la);
fp1=fopen("symbol.txt","r");
for(i=0;i<MAX;i++)
{
fscanf(fp1,"%d%d",&j,&sy[i].add);
if(sy[i].add!=0)
fscanf(fp1,"%s",sy[i].label);
}
for(i=0;i<MAX;i++)
{
if(sy[i].add!=0)
if(strcmp(sy[i].label,la)==0)
{
set=1;
s=sy[i].add;

}}
if(set==1)
printf("\n The label %s is present in the symbol table at address %d",la,s);
else
printf("\n The label %s is  not present in the symbol table ",la);
}



