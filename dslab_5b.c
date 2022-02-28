#include<stdio.h>
int count=0;
void tower(int n,char beg,char aux,char end )
{
    if(n==1)
    {
        printf("move %d disk from %c to %c\n",n,beg,end);
        count++;
        printf("count is %d\n",count);
    }
    else
    {
        tower(n-1,beg,end,aux);
        printf("move %d disk from %c to %c\n",n,beg,end);
        count++;
        printf("count is %d\n",count);
        tower(n-1,aux,beg,end);
    }
}
void main()
{
    int n;
    printf("enter the number of disk\n");
    scanf("%d",&n);
    printf("sequence of steps involved in tower of hanoi\n");
    tower(n,'a','b','c');
}