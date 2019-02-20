#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct entry
{
char key[3];
int value;
struct entry *next;
};
struct entry *symtab[56];
int hashfunction(char key[])
{
int value=0;
value+=(key[0]-65);
value+=(key[1]-65);
printf("%d",value);
return value;
}
void init(){
int i;
for(i=0;i<52;++i)
{
symtab[i]=NULL;
}
}
void display(){
struct entry *ptr=symtab[6];
while(ptr!=NULL)
{
printf("%s",ptr->key);
ptr=ptr->next;
}
}
void insert(){
char str[3];
int index;
int value;
struct entry *newnode=NULL;
struct entry *ptr=NULL;
struct entry *ptr1=NULL;
printf("Enter the key \n");
scanf("%s",str);
index=hashfunction(str);
if(symtab[index]==NULL)
{
newnode=(struct entry*)malloc(sizeof(struct entry));
newnode->next=NULL;
strcpy(newnode->key,str);
printf("Enter the value\n");
scanf("%d",&newnode->value);
symtab[index]=newnode;
}
else{
newnode=(struct entry*)malloc(sizeof(struct entry));
ptr=symtab[index];
if(strcmp(ptr->key,str)==0)
{
printf("Collision\n");
return;
}
while(ptr!=NULL)
{
if(strcmp(ptr->key,str)==0)
{
printf("Collision\n");
return;
}
ptr1=ptr;
ptr=ptr->next;
}
strcpy(newnode->key,str);
printf("Enter the value\n");
scanf("%d",&newnode->value);
newnode->next=NULL;
ptr1->next=newnode;
}
}
void search()
{
char str[3];
int index;
struct entry *ptr=NULL;
printf("Enter the key value");
scanf("%s",str);
index=hashfunction(str);
if(symtab[index]==NULL)
{
printf("Element not present");
return;
}
else{
ptr=symtab[index];
while(ptr!=NULL)
{
if(strcmp(ptr->key,str)==0)
{
printf("\nElement Found");
printf("\nValue=%d",ptr->value);
return;
}
ptr=ptr->next;
}
printf("Element not found");
}
}
void main()
{
int ch=1;
init();
while(ch==1)
{
printf("\n HASH TABLE OPERATIONS \n *****************************\n");
printf("1.INSERTION\n 2.SEARCHING \nENTER YOUR CHOICE\n ");
scanf("%d",&ch);
switch(ch)
{
case 1: insert(); break;
case 2 : search(); break;
case 3: display(); break;
default : printf("INVALID CHOICE\n"); break;
}
printf("DO YOU WANT TO ENTER MORE (0/1)\n");
scanf("%d",&ch);
}
}