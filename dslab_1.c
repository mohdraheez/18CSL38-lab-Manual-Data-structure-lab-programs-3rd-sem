#include<stdio.h>
#include<stdlib.h>
int array[100],n,i,elem,pos;
void create()
{
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
}
void display()
{
    printf("array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",array[i]);
    }
}
void insert()
{
    printf("enter the position and element\n");
    scanf("%d %d",&pos,&elem);
    for(i=n-1;i>=pos-1;i--)
    {
        array[i+1]=array[i];
    }
    n++;
    array[pos-1]=elem;
    
}
void delete()
{
    printf("enter the position\n");
    scanf("%d",&pos);
    printf("deleted element is %d\n",array[pos-1]);
    for(i=pos-1;i<n;i++)
    {
        array[i]=array[i+1];
    }
    n--;
}
void main()
{
    int choice;
    while(1)
    {
        printf("make a choice\n1.create\n2.display\n3.insert\n4.delete\n5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:insert();
            break;
            case 4:delete();
            break;
            case 5:exit(0);
            break;
            default:printf("invalid choice\n");
            break;
        }
    }
}