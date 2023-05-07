#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
struct stack{
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
        exit(1);
    }
    ch=s.arr[s.top--];
    return ch;
}

int palindrome(char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        push(s[i]);
    }
    for(int i=0;i<strlen(s);i++)
    {
        if(pop()!=s[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    s.top=-1;
    char ch[size];
    printf("Enter a string \n");
    scanf("%s",ch);
    if(palindrome(ch))
    {
        printf("The string is a palindrome \n");
    }
    else
    {
        printf("The string is not a palindrome \n");
    }
    return 0;
}

