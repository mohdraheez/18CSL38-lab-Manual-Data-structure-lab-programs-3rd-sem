#include<stdio.h>
#include<stdlib.h>
struct node
{
    char usn[20],name[20],branch[20],phone_no[25];
    int sem;
    struct node *next;
};
typedef struct node *NODE;
int count=0;
NODE temp,head='\0',cur;
NODE getnode()
{
    temp=(NODE)malloc(sizeof(struct node));
    if(temp=='\0')
    {
        printf("memory not allocated\n");
    }
    return temp;
}
NODE create()
{
    NODE temp;
    temp=getnode();
    printf("ENTER THE USN\n");
    scanf("%s",temp->usn);
    printf("ENTER THE NAME\n");
    scanf("%*c%[^\n]",temp->name);
    printf("ENTER THE BRANCH\n");
    scanf("%s",temp->branch);
    printf("ENTER THE PHONE NUMBER\n");
    scanf("%s",temp->phone_no);
    printf("ENTER THE SEM\n");
    scanf("%d",&temp->sem);
    temp->next='\0';
    return temp;
}
void insert_front()
{
    NODE temp;
    temp=create();
    if(head=='\0')
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    count++;
}
void insert_rear()
{
    NODE temp;
    temp=create();
    if(head=='\0')
    {
        head=temp;
    }
    else
    {
        cur=head;
        while(cur->next!='\0')
        {
            cur=cur->next;
        }
        cur->next=temp;
        cur=temp;
    }
    count++;
}
void display()
{
    temp=head;
    if(head=='\0')
    {
        printf("list is empty\n");
    }
    else
    {
    while(temp!='\0')
    {
    printf("USN :%s  ",temp->usn);
    printf("NAME :%s  ",temp->name);
    printf("BRANCH :%s  ",temp->branch);
    printf("PHONE NUMBER:%s  ",temp->phone_no);
    printf("SEM:%d  \n",temp->sem);
    temp=temp->next;
    }
    }
    printf("NODE COUNT : %d\n",count);
}
void delete_front()
{
    if(head=='\0')
    {
        printf("list is empty\n");
    }
    else
    {
    temp=head;
    printf("Deleted node is USN:%s  NAME:%s  BRANCH:%s  PHONE NUMBER:%s  SEM:%d  \n",temp->usn,temp->name,temp->branch,temp->phone_no,temp->sem);
    head='\0';
    free(head);
    head=temp->next;
    count--;
    }
}
void delete_rear()
{
    temp=head;
    if(head=='\0')
    {
        printf("list is empty\n");
    }
    else
    {
    if(head->next=='\0')
    {
        printf("Deleted node is USN:%s  NAME:%s  BRANCH:%s  PHONE NUMBER:%s  SEM:%d  \n",temp->usn,temp->name,temp->branch,temp->phone_no,temp->sem);
        head='\0';
        free(head);
    }
    else
    {
    while(temp->next!='\0')
    {
        cur=temp;
        temp=temp->next;
    }
    printf("Deleted node is USN:%s  NAME:%s  BRANCH:%s  PHONE NUMBER:%s  SEM:%d  \n",temp->usn,temp->name,temp->branch,temp->phone_no,temp->sem);
    temp='\0';
    cur->next='\0';
    }
    count--;
    }
}
void main()
{
    int choice,n,i;
    while(1)
    {
        printf("-------------------------\n");
        printf("MAKE A CHOICE\n1.CREATE\n2.INSERT FRONT\n3.INSERT REAR\n4.DELETE FRONT\n5.DELETE REAR\n6.DISPLAY\n7.EXIT\n");
        printf("-------------------------\n");
        printf("CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter number of nodes to be created:\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                insert_front();
                printf("--*--\n");
            }
            break;
            case 2:insert_front();
            break;
            case 3:insert_rear();
            break;
            case 4:delete_front();
            break;
            case 5:delete_rear();
            break;
            case 6:display();
            break;
            case 7:printf("THANK YOU\n");
            exit(0);
            break;
            default : printf("Invalid choice\n");
            break;
        }
    }
}
