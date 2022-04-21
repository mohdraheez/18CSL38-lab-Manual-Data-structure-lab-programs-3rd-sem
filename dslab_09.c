#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int expox,expoy,expoz,coef;
    struct node *next;
};

typedef struct node *NODE;

NODE createHead()
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->coef=0;
    temp->expox=-1;
    temp->expoy=-1;
    temp->expoz=-1;
    temp->next=temp;
    return temp;
}

NODE createpoly(int c,int x,int y,int z)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->coef=c;
    temp->expox=x;
    temp->expoy=y;
    temp->expoz=z;
    temp->next=NULL;
    return temp;
}

void insert_poly(int c,int x,int y,int z,NODE poly)
{
    NODE temp=createpoly(c,x,y,z);
    if(poly->next==poly){
        poly->next=temp;
        temp->next=poly;
    }
    else{
        NODE cur=poly;
        while(cur->next!=poly)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->next=poly;
    }
    poly->coef=(poly->coef+1);

}

void display(NODE poly)
{
    if(poly->next==poly){
        printf("polynomial is empty\n");
    }
    else{
        NODE cur = poly->next;
        while(cur!=poly){
            if(cur->coef>0){
                printf("+");
            }
            printf("%dx^%dy^%dz^%d ",cur->coef,cur->expox,cur->expoy,cur->expoz);
            cur=cur->next;
        }
        printf("Total number of terms :%d\n",poly->coef);
    }
}

NODE createnode(NODE poly)
{
    int x,y,z,c,n;
    printf("Enter number of terms\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value of coef\n");
        scanf("%d",&c);
        printf("Enter expo of x\n");
        scanf("%d",&x);
        printf("Enter expo of y\n");
        scanf("%d",&y);
        printf("Enter expo of z\n");
        scanf("%d",&z);
        insert_poly(c,x,y,z,poly);
    }
    return poly;
}

double evaluate(NODE poly,int x,int y,int z)
{
    double value=0;
    if(poly->next==poly){
        printf("polynomial is empty\n");
    }
    else{
        NODE cur=poly->next;
        while(cur!=poly){
           
            value=value+((cur->coef)*(pow(x,cur->expox))*pow(y,cur->expoy)*pow(z,cur->expoz));
             cur=cur->next;
            
        }
    }
    return value;
}

NODE add(NODE poly1,NODE poly2)
{
    NODE a=poly1->next,b=poly2->next,polysum;
    polysum=createHead();
    int sum=0;
    while((a!=poly1)&&(b!=poly2)){
        if((a->expox==b->expox)&&(a->expoy==b->expoy)&&(a->expoz==b->expoz)){
            sum=a->coef+b->coef;
            insert_poly(sum,a->expox,a->expoy,a->expoz,polysum);
            a=a->next;
            b=b->next;
        }
        else if(a->expox>b->expox){
            insert_poly(a->coef,a->expox,a->expoy,a->expoz,polysum);
            a=a->next;
        }
        else if(a->expox==b->expox && a->expoy>b->expoy){
            insert_poly(a->coef,a->expox,a->expoy,a->expoz,polysum);
            a=a->next;
        }
        else if(a->expox==b->expox && a->expoy==b->expoy && a->expoz>b->expoz){
            insert_poly(a->coef,a->expox,a->expoy,a->expoz,polysum);
            a=a->next;
        }
        else{
            insert_poly(b->coef,b->expox,b->expoy,b->expoz,polysum);
            b=b->next;
        }
    }
    while(a!=poly1){
        insert_poly(a->coef,a->expox,a->expoy,a->expoz,polysum);
            a=a->next;
    }
    while(b!=poly2){
        insert_poly(b->coef,b->expox,b->expoy,b->expoz,polysum);
            b=b->next;
    }
    
    return polysum;
}

void main()
{
    NODE poly1,poly2,polysum=NULL;
    int x,y,z;
    double value=0;
    poly1=createHead();
    poly1=createnode(poly1);
    display(poly1);
    printf("Enter value for x,y,z\n");
    scanf("%d%d%d",&x,&y,&z);
    value=evaluate(poly1,x,y,z);
    printf("After evaluation value: %lf\n",value);
    free(poly1);
    poly1=NULL;
    poly1=createHead();
    poly1=createnode(poly1);
    display(poly1);
    poly2=createHead();
    poly2=createnode(poly2);
    display(poly2);
    printf("sum is\n");
    polysum=add(poly1,poly2);
    display(polysum);
}   
