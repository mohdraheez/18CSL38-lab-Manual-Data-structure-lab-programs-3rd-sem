#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define max 20

char stack[max],postfix[100],ch;
int i=0,op1,op2,top=-1;

void push(int elem)
{
    stack[++top]=elem;
}

void main()
{
    printf("enter the expression\n");
    scanf("%s",postfix);
    while((ch=postfix[i++])!=0)
    {
        if(isalpha(ch))
        {
            printf("wrong expression\n");
            return;
        }
        else if(isdigit(ch))
        {
            push(ch-48);
        }
        else
        {
            op2=stack[top--];
            if(top==-1)
            {
                printf("invalid expression\n");
                return;
            }
            op1=stack[top--];
            switch(ch)
            {
                case '+':
                push(op1+op2);
                break;
                case '-':
                push(op1-op2);
                break;
                case '*':
                push(op1*op2);
                break;
                case '/':
                push(op1/op2);
                break;
                case '%':
                push(op1%op2);
                break;
                case '^':
                push(pow(op1,op2));
                break;
                default:
                printf("invalid expression\n");
                break;

            }
        }
    }
    
    if(top!=0)
    {
        printf("invalid expression\n");
    }
    else
    {
    printf("answer is %d\n",stack[top]);
    }

}
