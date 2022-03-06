#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *lchild,*rchild;
};
typedef struct node *NODE;
NODE create_node(int data)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=data;
    temp->rchild=NULL;
    temp->lchild=NULL;
    return temp;
}
void bst(NODE root,NODE newnode)
{
    if(root->data==newnode->data)
    {
        printf("data aldready exist\n");
    }
    else if(newnode->data<root->data)
    {
        if(root->lchild==NULL)
        {
            root->lchild=newnode;
        }
        else
        {
            bst(root->lchild,newnode);
        }
    }
    else if(newnode->data>root->data)
    {
        if(root->rchild==NULL)
        {
            root->rchild=newnode;
        }
        else
        {
            bst(root->rchild,newnode);
        }
    }
    
}
void inorder(NODE temp)
{
    if(temp!=NULL)
    {
        inorder(temp->lchild);
        printf("%d ",temp->data);
        inorder(temp->rchild);
    }
}
void preorder(NODE temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}
void postorder(NODE temp)
{
    if(temp!=NULL)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d ",temp->data);
    }
}

NODE search(int item,NODE root)
{
    if(root==NULL)
    return NULL;
    else {
        NODE cur=root;
        while(cur!=NULL){
            if(cur->data==item){
                return cur;
            }
            else if(item>root->data){
                cur=cur->rchild;
            }
            else{
                cur=cur->lchild;
            }
        }
    }
}
void main()
{
    int choice,n,data,i,item;
    NODE root=NULL,newnode=NULL;
    while(1)
    {
        printf("\n1.BST\n2.traversal of BST\n3.search\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter number of Integers\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("Enter the data\n");
                scanf("%d",&data);
                newnode=create_node(data);
                if(root==NULL)
                {
                    root=newnode;
                }
                else{
                    bst(root,newnode);
                }
            }
            break;

            case 2:
            if(root==NULL)
            {
                printf("tree is empty\n");
            }
            else
            {
                NODE temp=root;
                printf("inorder:");
                inorder(temp);
                printf("preorder:");
                preorder(temp);
                printf("postorder:");
                postorder(temp);

            }
            break;
            case 3:
            printf("Enter the element to be searched\n");
            scanf("%d",&item);
            NODE cur=search(item,root);
            if(cur==NULL){
                printf("item not found\n");
            }
            else{
                printf("item found\n");
            }
            break;
            case 4:exit(0);
            break;
            default:printf("invalid choice\n");
            break;

        }
    }
}
