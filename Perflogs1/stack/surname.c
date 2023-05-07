#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

typedef struct{
    char arr[size];
    int top;
}Stack;

Stack *create()
{
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->top=-1;
    return s;
}
int isEmpty(Stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Stack *s)
{
    if(s->top==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Stack *s,char ch)
{
    if(isFull(s))
    {
        printf("Stack overflow \n");
        return;
    }
    else
    {
        s->arr[++s->top]=ch;
    }
}

char pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow \n");
        return '\0';
    }
    else
    {
        return s->arr[s->top--];
    }
}

void display(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty \n");
        return;
    }
    printf("Stack: ");
    for(int i=0;i<=s->top;i++)
    {
        printf("%c",s->arr[i]);
    }
    printf("\n");
}
int main()
{
    char name[size];
    printf("Enter your name in the order of First Name,Middle Name,Surname: ");
    fgets(name,size,stdin);
    int len=strlen(name);
    if(name[len-1]=='\n')
    {
        name[len-1]='\0';
    }
    Stack *first=create();
    Stack *middle=create();
    Stack *last=create();
    int i=0;
    while(name[i]!=' ')
    {
        push(first,name[i]);
        i++;
    }
    i++;
    while(name[i]!=' ')
    {
        push(middle,name[i]);
        i++;
    }
    i++;
    while(name[i]!='\0')
    {
        push(last,name[i]);
        i++;
    }
    printf("Name in format of Surname,First name and middle name \n");
    printf("Last name: ");
    display(last);
    printf("First name: ");
    display(first);
    printf("Middle name: ");
    display(middle);
    free(first);
    free(middle);
    free(last);
    return 0;
}