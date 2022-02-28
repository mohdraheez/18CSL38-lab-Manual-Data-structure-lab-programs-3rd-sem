#include<stdio.h>
#include<stdlib.h>
#define max 4
int front=-1,rear=-1,i;
char queue[max],elem;
void insert()
{
    if((rear+1)%max==front)
    {
        printf("overflow\n");
    }
    else
    {
        printf("enter the element\n");
        scanf("%*c%c",&elem);
        rear=(rear+1)%max;
        queue[rear]=elem;
        if(front==-1)
        {
            front++;
        }
    }
}
void delete()
{
    if(front==-1)
    {
        printf("underflow\n");
    }
    else
    {
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
        printf("deleted element is %c\n",queue[front]);
        front=(front+1)%max;
        }

    }
}
void display()
{
    if(front==-1)
    {
        printf("underflow\n");
    }
    else
    {
        i=front;
        if(front!=rear)
        {
        while(i!=rear)
        {
            printf("%c\n",queue[i]);
            i=(i+1)%max;
        }
        }
        printf("%c\n",queue[i]);
    }
}
void main()
{
    int choice;
    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
            break;
            case 2: delete();
            break;
            case 3:
            display();
            break;
            case 4: exit(0);
            break;
            default:printf("invalid choice\n");
            break;
        }
    }
}