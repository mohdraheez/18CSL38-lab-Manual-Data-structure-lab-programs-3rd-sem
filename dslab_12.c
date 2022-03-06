#include<stdio.h>
#include<stdlib.h>
int n,m,*ht,count=0,i,flag=0,hi;
void createHT();
void insertHT(int key);
void displayHT();
void main()
{
    int key;
    printf("Enter value of n\n");
    scanf("%d",&n);
    printf("Enter 2 digit memory location\n");
    scanf("%d",&m);
    createHT();
    for(i=0;i<n;i++)
    {
        printf("enter 4 digit key word\n");
        scanf("%d",&key);
        if(count==m){
            printf("hash table is full\n");
            break;
        }
        else{
            insertHT(key);
        }
        
    }
    displayHT();
}

void createHT()
{
    ht=(int*)malloc(m*sizeof(int));
    if(m==0){
        printf("Memory not allocated\n");
    }
    else{
        for(i=0;i<m;i++){
            ht[i]=-1;
        }
    }
}
void insertHT(int key)
{
    hi=key%m;
    while(ht[hi]!=-1){
        hi=(hi+1)%m;
        flag=1;
    }
    if(flag==1){
        printf("collusion detected and resolved using linear probing\n");
        flag=0;
    }
    ht[hi]=key;
    count++;
}
void displayHT()
{
    int i;
    if(count==0){
        printf("hashtable is empty\n");
        exit(0);
    }
    else{
        for(i=0;i<m;i++){
            printf("[%d]->%d\n",i,ht[i]);
        }
    }
    
}
