#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

struct stack{
    int top;
    char arr[size][100];
};

void push(struct stack *s,char item[])
{
    if(s->top==size-1)
    {
        printf("Invlaid expression \n");
    }
    else
    {
        strcpy(s->arr[++s->top],item);
    }
}

char *pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("Invalid expression \n");
        return '\0';
    }
    else
    {
        return s->arr[s->top--];
    }
}

int operate(char a[],char b[],char c)
{
    if(c=='+')
    {
        return atoi(a)+atoi(b);
    }
    else if(c=='-')
    {
        return atoi(a)-atoi(b);
    }
    else if(c=='*')
    {
        return atoi(a)*atoi(b);
    }
    else if(c=='/')
    {
        return atoi(a)/atoi(b);
    }
    return 0;
}

void evaluate(char prefix[])
{
    char string3[100];
    int ans;
    struct stack s;
    s.top=-1;
    for(int i=strlen(prefix)-1;i>=0;i--)
    {
        if(prefix[i]>='0'&& prefix[i]<='9')
        {
            char temp[]={prefix[i],'\0'};
            push(&s,temp);
        }
        else
        {
            char *string2=pop(&s);
            char *string1=pop(&s);
            ans=operate(string1,string2,prefix[i]);
            sprintf(string3,"%d",ans);
            push(&s,string3);
        }
    }
    printf("%d",ans);
}

void convert(char prefix[])
{
    char *string1;
    char *string2;
    char string3[100];
    char infix[100];
    struct stack s;
    s.top=-1;
    for(int i=strlen(prefix)-1;i>=0;i--)
    {
        if(prefix[i]>='0'&&prefix[i]<='9')
        {
            char temp[]={prefix[i],'\0'};
            push(&s,temp);
        }
        else
        {
            char temp[]={prefix[i],'\0'};
            string2=pop(&s);
            string1=pop(&s);
            strcat(string3,"(\0");
            strcat(string3,string2);
            strcat(string3,temp);
            strcat(string3,string1);
            strcat(string3,")\0");
            push(&s,string3);
            strcpy(string3,"\0");
        }
        
    }
    printf("%s\n",s.arr[0]);
}

int main()
{
    char prefix[100];
    printf("Enter a prefix expression: ");
    scanf("%s",prefix);
    convert(prefix);
    evaluate(prefix);
    return 0;
}