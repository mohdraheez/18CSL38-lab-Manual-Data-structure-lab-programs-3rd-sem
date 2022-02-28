#include<stdio.h>
#include<stdlib.h>
#define max 4
int stack[max],elem,top=-1;
void push()
{
    if(top==max-1)
    {
        printf("overflow\n");
    }
    else
    {
        printf("enter the element\n");
        scanf("%d",&elem);
        stack[++top]=elem;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("underflow\n");
    }
    else
    {
        printf("deleted element is %d\n",stack[top--]);
    }
}
void palindrome()
{
    int i,j,flag=0;
    for(i=0,j=top;i<j/2;i++,j--)
    {
        if(stack[i]==stack[j])
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("palindrome\n");
    }
    else
    {
        printf("not palindrome\n");
    }
}
void display()
{
    int i;
    printf("stack elements are\n");
    for(i=top;i>-1;i--)
    {
        printf("%d\n",stack[i]);
    }
}
void main()
{
    int choice;
    while(1)
    {
        printf("make a choice\n1.push\n2.pop\n3.display\n4.palindrome\n5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:palindrome();
            break;
            case 5: exit(0);
            break;
            default:printf("invalid choice\n");
            break;
        }
    }
}