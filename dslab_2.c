#include<stdio.h>
#include<stdlib.h>
void patternmatch();
char str[40],pat[40],rep[30],ans[30];
int i=0,s=0,p=0,r=0,a=0,flag=0;
void main()
{
    printf("enter the main string\n");
    scanf("%[^\n]",str);
    printf("enter the pattern string\n");
    scanf("%*c%[^\n]",pat);
    printf("enter the replacement string\n");
    scanf("%*c%[^\n]",rep);
    patternmatch();
}
void patternmatch()
{
    while(str[i]!='\0')
    {
        if(str[s]==pat[p])
        {
            s++;
            p++;
            if(pat[p]=='\0')
            {
                for(r=0;rep[r]!='\0';r++)
                {
                    ans[a]=rep[r];
                    a++;
                    i=s;
                    flag=1;
                    p=0;
                }
            }
        }
    else
    {
        ans[a]=str[i];
        i++;
        a++;
        s=i;
        p=0;
    }
}
    if(flag==1)
    {
    printf("answer string is %s\n",ans);
    }
    else
    {
        printf("pattern dint match\n");
    }
}