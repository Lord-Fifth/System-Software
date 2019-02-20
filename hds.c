/*
  EXPERIMENT 2 
    HIERARCHICAL DIRECTORY STRUCTURE
            ROOT
        USER1   USER2
    A        B C      D
                    E   F
    Operations: Create, Delete, Search, Display

*/

#include<stdio.h>
#include<stdlib.h>

#include<string.h>

struct node
{
 int num;
 char name[15];
 struct node *RC;
 struct node *LC;
};

int top=0;
const int size=10;
int STACK[10];

struct node *GETNODE(struct node *);           // Function to create a new node/directory/file
//void INORDER(struct node *);
void PREORDER(struct node *);
//void POSTORDER(struct node *);
struct node *BUILD_ROOT(struct node *root);    // Function to build root.
void BUILD_TREE(struct node *,int);           //  Function to create hierarchical structure
//void INSERT(struct node *root);
int parentsearch(struct node *root,char search[]);
struct node *presearch(struct node *root,char search[]);
int DELETE(struct node *root,char search[]);

int parentsearch(struct node *root,char search[])
{
 int flag=0;
 if(root!=NULL){
   if(strcmp(root->name,search)==0){
     flag=1;
     return flag;
   }
   else{
     return parentsearch(root->LC,search) || parentsearch(root->RC,search);
   }
 }
 return flag;
}

int DELETE(struct node *root,char search[]){
	struct node *ptr=NULL;
	int flag=0;
	if(root!=NULL){
	 if(strcmp(root->name,search)==0){
	  strcpy(root->name," ");
	  return flag;
	 }
	 else
	   return DELETE(root->LC,search) || DELETE(root->RC,search);
       }
       return flag;
}
struct node *GETNODE(struct node *incoming)
{
 incoming=(struct node*)malloc(sizeof(struct node));
 incoming->num=0;
 strcpy(incoming->name,"");
 incoming->RC=NULL;
 incoming->LC=NULL;
 return incoming;
}

struct node *BUILD_ROOT(struct node *root)
{
 struct node *np=NULL;
 if(root==NULL)
 {
  np=GETNODE(np);                           // giving 0 as root node
  np->num=0;
  strcpy(np->name,"ROOT");
  if(np!=NULL)
  {
   root=np;                                 // setting np as root node
  }
 }
 return np;
}

void BUILD_TREE(struct node *ptr,int d_f_num)  // call this function using root
{
 int ch=1;
 int flag;
 //int d_f_num=0;
 char d_f_name[15];
 struct node *lcptr=NULL;
 struct node *rcptr=NULL;
 if(ptr!=NULL)
 {
  ptr->num=d_f_num;
  printf("\n Do you wish to create a subdirectory/file under %s ?(YES=1/NO=0) ",ptr->name);
  scanf("%d",&ch);
  if(ch==1)
  {
   d_f_num++;
   printf("\n Enter the name of the subdirectory/file:  ");
   scanf("%s",&d_f_name);
   lcptr=GETNODE(lcptr);
   lcptr->num=d_f_num;
   strcpy(lcptr->name,d_f_name);
   ptr->LC=lcptr;
   BUILD_TREE(lcptr,d_f_num);
  }
  else
  {
   flag=0;
   lcptr=NULL;
   ptr->LC=NULL;
   BUILD_TREE(lcptr,0);
  }
  // Left children completed.
 d_f_num=0;
 ch=1;
 //if(flag!=0){
 printf(" \n Do you wish to create another subdirectory/file under %s ?(YES=1/NO=0)",ptr->name);
 scanf("%d",&ch);
 if(ch==1)
  {
   d_f_num++;
   printf("\n Enter the name of the subdirectory/file:  ");
   scanf("%s",&d_f_name);
   rcptr=GETNODE(rcptr);
   rcptr->num=d_f_num;
   strcpy(rcptr->name,d_f_name);
   ptr->RC=rcptr;
   BUILD_TREE(rcptr,d_f_num);
  }
  else
  {
   rcptr=NULL;
   ptr->RC=NULL;
   BUILD_TREE(rcptr,0);
  }
// }
  // Right children completed.
 }
 else ;
 // Tree completed.
 lcptr=NULL;
 rcptr=NULL;
}
/*
void INORDER(struct node *head)
{
 struct node *ptr=NULL;
 ptr=head;
 if(ptr!=NULL)
 {
  INORDER(ptr->LC);
  printf(" %s \t",ptr->name);
  INORDER(ptr->RC);
 }
 //free(ptr);
}
*/


void PREORDER(struct node *head)
{
 struct node *ptr=NULL;
 ptr=head;
 if(ptr!=NULL)
 {
  printf(" %s \t",ptr->name);
  PREORDER(ptr->LC);
  PREORDER(ptr->RC);

 }
 //free(ptr);
}

void main()
{
 int key,ch;
 struct node *root=NULL;
 struct node *point=NULL;
 char s[15];
 //clrscr();
 root=BUILD_ROOT(root);
 //BUILD_TREE(root,0);
 while(1){
  printf(" \n MENU --  ");
  printf(" 1. Create ");
  printf(" 2. Search ");
  printf(" 3. Delete ");
  printf(" 4. Display");
  printf(" 5. Exit ");
  printf("\n");
  printf("Enter the choice:  ");
  scanf("%d",&ch);
  switch(ch){
   case 1: {
		BUILD_TREE(root,0);
	   }break;
   case 4: {
		printf("Directory Structure: \t  ");
		PREORDER(root);
	   }break;
   case 3: {
      printf("Enter the name of the directory/file: ");
	    scanf("%s",&s);
      key=DELETE(root,s);
      if(key==1)
	printf(" Sucessfully deleted. ");
      else
	printf(" No such file/directory.  ");
	   }break;
   case 2: {
	    printf("Enter the name of the directory/file: ");
	    scanf("%s",&s);
      key=parentsearch(root,s);
      if(key==1)
	printf(" File/ Directory found. ");
      else
	printf(" No such file/directory. ");
	   }break;
   case 5: {
	    exit(0);
	   }
  }
 }

 free(root);
 getch();
}

