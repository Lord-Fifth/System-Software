#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE
{
        char name[20];
        int type;
        struct NODE *rlink;
        struct NODE *dlink;
        struct NODE *ulink;
        int level;
};
void main()
{
        char name[20];int ch;char temp[20];int flag;
        struct NODE *ptr,*ptr1,*ptr2;
        struct NODE *root;struct NODE *new1;
        root=(struct NODE*)malloc(sizeof(struct NODE));
        strcpy(root->name,"root");     
        root->ulink=NULL;
        root->dlink=NULL;
        root->rlink=NULL;
        root->level=0;
        root->type=0;
        ptr=root;
        while(1)
        {
                printf("\n\nCurrent directory: %s\n",ptr->name);
                printf("\nPress\n1. Add a file \n2. Add a directory \n3. Change to a directory \n4. Delete a file or directory \n5. Display contents of current directory\n6. Exit \n");
                scanf("%d",&ch);
                if(ch==1)
                {
                        printf("Enter the name of the file ");
                        scanf("%s",temp);
                        new1=(struct NODE*)malloc(sizeof(struct NODE));
                        strcpy(new1->name,temp);
                        new1->rlink=NULL;
                        new1->dlink=NULL;
                        new1->ulink=ptr;
                        new1->type=1;
                        new1->level=(ptr->level)+1;                     
                        if(ptr->dlink==NULL)
                        {
                                ptr->dlink=new1;
                        }
                        else
                        {
                                ptr1=ptr->dlink;
                                while(ptr1->rlink!=NULL)
                                        ptr1=ptr1->rlink;
                                ptr1->rlink=new1;
                        }

                }
                else if(ch==2)
                {       
                        printf("Enter the name of the directory ");
                        scanf("%s",temp);
                        new1=(struct NODE*)malloc(sizeof(struct NODE));
                        strcpy(new1->name,temp);
                        new1->rlink=NULL;
                        new1->dlink=NULL;
                        new1->ulink=ptr;
                        new1->type=0;
                        new1->level=(ptr->level)+1;                     
                        if(ptr->dlink==NULL)
                        {
                                ptr->dlink=new1;
                        }
                        else
                        {
                                ptr1=ptr->dlink;
                                while(ptr1->rlink!=NULL)
                                        ptr1=ptr1->rlink;
                                ptr1->rlink=new1;
                        }

                }
                else if(ch==3)
                {
                        printf("Press\n1. To move to parent directory\n2. To move to sub directory\n");
                        scanf("%d",&ch);
                        if(ch==1)
                        {
                                if(ptr->level==0)
                                        printf("Already at the root level");
                                else
                                {
                                        ptr=ptr->ulink;
                                }
                        }
                        else
                        {
                                ptr1=ptr->dlink;
                                if(ptr1==NULL)
                                        printf("\nNo subdirectories\n");
                                else
                                {
                                        printf("\nEnter the name of the directory ");
                                        scanf("%s",temp);
                                        flag=0;
                                        while(ptr1!=NULL)
                                        {
                                                if((strcmp((ptr1->name),temp)==0)&&((ptr1->type)==0))
                                                {
                                                        flag=1;break;
                                                }
                                                ptr1=ptr1->rlink;
                                        }
                                        if(flag==1)
                                                ptr=ptr1;
                                        else
                                                printf("No such directory");
                                }
                        }
                }
                else if(ch==4)
                {

                        ptr1=ptr->dlink;
                        if(ptr1==NULL)
                                printf("\nNo subdirectories\n");
                        else
                        {
                                printf("\nEnter the name of the file or directory to be deleted ");
                                scanf("%s",temp);
                                flag=0;
                                if(ptr1->rlink==NULL)
                                {
                                        if((strcmp((ptr1->name),temp)==0))
                                        {
                                                ptr->dlink=NULL;
                                                ptr1=NULL;
                                        }
                                }
                                else                           
                                {
                                        ptr2=ptr1;                                                             
                                        while(ptr1!=NULL)
                                        {
                                                if((strcmp((ptr1->name),temp)==0))
                                                {
                                                        flag=1;break;
                                                }
                                                ptr2=ptr1;
                                                ptr1=ptr1->rlink;
                                        }
                                        if(flag==1)
                                        {
                                                ptr2->rlink=ptr1->rlink;
                                                ptr1=NULL;
                                        }               
                                        else
                                                printf("\nNo such directory\n");
                                }
                        }
                }
                else if(ch==5)
                {
                        ptr1=ptr->dlink;
                        if(ptr1==NULL)
                                printf("\nDirectory is empty\n");
                        else
                        {
                                printf("\nContents\n");
                                printf("\nDirectories\n");
                                while(ptr1!=NULL)
                                {
                                        if(ptr1->type==0)
                                                printf("\n%s",ptr1->name);     
                                        ptr1=ptr1->rlink;
                                }
                                ptr1=ptr->dlink;
                                printf("\n\nFiles\n");
                                while(ptr1!=NULL)
                                {
                                        if(ptr1->type==1)
                                                printf("\n%s",ptr1->name);     
                                        ptr1=ptr1->rlink;
                                }
                        }
                }
                else if(ch==6)
                        break;         
                else
                        printf("Wrong Input");
        }
}
