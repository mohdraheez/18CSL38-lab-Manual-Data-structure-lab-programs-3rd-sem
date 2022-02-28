#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 20
char stack[max],postfix[30],infix[30],c,elem;
int top=-1,i=0,j=0,flag;
int precidence(char ch)
{
    switch(ch)
    {
        case '#':return 0;
        break;
        case '(':return 1;
        break;
        case '+':return 2;
        break;
        case '-':return 2;
        break;
        case '*':return 3;
        break;
        case '/':return 3;
        break;
        case '%':return 4;
        break;
        case '^':return 5;
        break;
        default:printf("wrong expression\n");
        exit(0);
        break;
    }
}
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return(stack[top--]);
}
void main()
{
    printf("enter the infix expression\n");
    scanf("%s",infix);
    stack[++top]='#';
    while((c=infix[i++])!='\0')
    {
        if(c=='(')
        {
            push(c);
        }
        else if(isalnum(c))
        {
            postfix[j++]=c;
        }
        else if(c==')')
        {
            if(stack[top]=='#')
            {
                printf("invalid expression\n");
                flag=0;
                
            }
            else
            {
            while(stack[top]!='(')
            {
                postfix[j++]=pop();
            }
        
            elem=pop();
            }
        }
        else
        {
            int p=precidence(c);
            if(c=='^')
            {
                p++;
            }
            while(precidence(stack[top])>p)
            {
                postfix[j++]=pop();
            }
            push(c);
        }
    }
    while(stack[top]!='#')
    {
        postfix[j++]=pop();
    }
    printf("postfix expression is %s\n",postfix);
}