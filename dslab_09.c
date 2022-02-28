#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
struct node {
    int coef,expox,expoy,expoz;
    struct node *next;
};
typedef struct node *NODE;

NODE insert_poly(int c,int x,int y,int z,NODE head);
NODE create_node(int c,int x,int y,int z);

NODE create_head()
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->coef=0;
    temp->expox=-1;
    temp->expoy=-1;
    temp->expoz=-1;
    temp->next=temp;
    return temp;
}

NODE create_poly(NODE poly1)
{
    int x,y,z,c,n,i;
    printf("enter number of terms in polynomial\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the coefficient\n");
        scanf("%d",&c);
        printf("Enter the expo of x\n");
        scanf("%d",&x);
        printf("Enter the expo of y\n");
        scanf("%d",&y);
        printf("enter the expo of z\n");
        scanf("%d",&z);
        insert_poly(c,x,y,z,poly1);
    }
        return poly1;
}

NODE insert_poly(int c,int x,int y,int z,NODE head)
{
    NODE temp=create_node(c,x,y,z);
    if(head->next==head)
    {
        head->next=temp;
        temp->next=head;
    }
    else{
        NODE cur=head;
        while(cur->next!=head)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->next=head;
    }
    head->coef=((head->coef)+1);
    return head;
}

NODE create_node(int c,int x,int y,int z)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->coef=c;
    temp->expox=x;
    temp->expoy=y;
    temp->expoz=z;
    temp->next=NULL;
    return temp;
}
void display(NODE head)
{
    if(head->next==head)
    {
        printf("list is empty\n");
    }
    else{
    NODE temp=head->next;
    while(temp!=head){
        if(temp->coef<0)
        printf("%dx^%dy^%dz^%d ",temp->coef,temp->expox,temp->expoy,temp->expoz);
        else
        printf("+%dx^%dy^%dz^%d ",temp->coef,temp->expox,temp->expoy,temp->expoz);
        temp=temp->next;
    }
    }
 
}
double evaluate(int x,int y,int z,NODE poly)
{
    double value;
    if(poly==poly->next)
    {
        printf("list is empty\n");
    }
    else{
        NODE temp=poly;
        while(temp->next!=poly){
            temp=temp->next;
            value=value+(temp->coef)*(pow(x,temp->expox))*(pow(y,temp->expoy))*(pow(z,temp->expoz));
        }
        return value;
    }
}

NODE add(NODE poly1,NODE poly2)
{
    NODE starta=poly1->next,startb=poly2->next,polysum;
    polysum=create_head();
    int sum;
    while((starta!=poly1) && (startb!=poly2))
    {
        if(starta->expox==startb->expox && starta->expoy==startb->expoy && starta->expoz==startb->expoz)
        {
            sum=starta->coef+startb->coef;
            insert_poly(sum,starta->expox,starta->expoy,starta->expoz,polysum);
            starta=starta->next;
            startb=startb->next;
        }
        else if(starta->expox>startb->expox && starta->expoy==startb->expoy && starta->expoz==startb->expoz)
        {
            insert_poly(starta->coef,starta->expox,starta->expoy,starta->expoz,polysum);
            starta=starta->next;

        }
        else if(starta->expox>startb->expox && starta->expoy>startb->expoy && starta->expoz==startb->expoz)
        {
            insert_poly(starta->coef,starta->expox,starta->expoy,starta->expoz,polysum);
            starta=starta->next;
        }
        else if(starta->expox>startb->expox && starta->expoy>startb->expoy && starta->expoz>startb->expoz)
        {
            insert_poly(starta->coef,starta->expox,starta->expoy,starta->expoz,polysum);
            starta=starta->next;
        }
        else
        {
            insert_poly(startb->coef,startb->expox,startb->expoy,startb->expoz,polysum);
            starta=starta->next;
        }
    }
    while(poly1!=starta)
    {
        insert_poly(starta->coef,starta->expox,starta->expoy,starta->expoz,polysum);
            starta=starta->next;

    }
    while(poly2!=startb)
    {
        insert_poly(startb->coef,startb->expox,startb->expoy,startb->expoz,polysum);
        starta=starta->next;
    }
    return polysum;
}
void main()
{
    NODE poly1,poly2,polysum;   
    int x,y,z;
    double value;
    poly1=create_head();
    poly1=create_poly(poly1);
    printf("Enter value of x\n");
    scanf("%d",&x);
    printf("Enter value of y\n");
    scanf("%d",&y);
    printf("Enter value of z\n");
    scanf("%d",&z);
    value = evaluate(x,y,z,poly1);
    printf("value after evaluation is %lf\n",value);
    display(poly1);
    free(poly1);
    poly1=NULL;
    poly1=create_head();
    poly1=create_poly(poly1);
    display(poly1);
    poly2=create_head();
    poly2=create_poly(poly2);
    display(poly2);
    printf("sum is \n");
    polysum=add(poly1,poly2);
    display(polysum);
    printf("thank you\n");
}