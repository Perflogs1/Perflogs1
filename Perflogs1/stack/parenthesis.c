#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
struct  stack{
    char arr[size];
    int top;
};
struct stack s;
int isEmpty()
{
    if(s.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(s.top==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char ch)
{
    if(isFull())
    {
        printf("Stack overflow \n");
        exit(1);
    }
    s.arr[++s.top]=ch;
}
char pop()
{
    char ch;
    if(isEmpty())
    {
        printf("Stack underflow \n");
    }
    ch=s.arr[s.top--];
    return ch;
}


int matchparenthesis(char a,char b)
{
    if(a=='{'&&b=='}')
    {
        return 1;
    }
    if(a=='['&&b==']')
    {
        return 1;
    }
    if(a=='('&&b==')')
    {
        return 1;
    }
    
    return 0;
}

int  validity(char expr[100])
{
    char temp;
    for(int i=0;i<strlen(expr);i++)
    {
        if(expr[i]==' ')
        {
            continue;
        }
        
        if(expr[i]=='{'||expr[i]=='['||expr[i]=='(')
        {
            push(expr[i]);
        }
        else if(expr[i]=='}'||expr[i]==']'||expr[i]==')')
        {
            
            if(isEmpty())
            {
                printf("Closing parenthesis more than opening ones \n");
                return 0;
            }
            else
            {
                temp=pop();
                if(!matchparenthesis(temp,expr[i]))
                {
                    printf("Mismatched brackets \n");
                    return 0;
                }
                
            }
        }
    }
    
    if(isEmpty())
    {
        printf("Parenthesis are well balanced \n");
        return 1;
    }
    else
    {
        printf("Opening brackets more than closing ones \n");
        return 0;
    }
}

int main()
{
    s.top=-1;
    char expression[size];
    printf("Enter the expression \n");
    scanf("%s",expression);
    if(validity(expression)==1)
    {
        printf("Strings/brackets are well balanced \n");
    }
    else
    {
        printf("Strings/brackets are not well balanced \n");
    }
    return 0;
}


