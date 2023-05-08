#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack Implementation
struct stack {
    int top;
    char arr[MAX_SIZE][MAX_SIZE];
};

void push(struct stack *s, char *item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    strcpy(s->arr[++s->top], item);
}

char *pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->arr[s->top--];
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

char *convertToInfix(char *postfix) {
    struct stack s;
    s.top = -1;
    char *operand1, *operand2, *operator, temp[MAX_SIZE];
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(&s, temp);
        } else if (isOperator(postfix[i])) {
            operand2 = pop(&s);
            operand1 = pop(&s);
            operator = (char*)malloc(sizeof(char));
            operator[0] = postfix[i];
            operator[1] = '\0';
            strcpy(temp, "(");
            strcat(temp, operand1);
            strcat(temp, operator);
            strcat(temp, operand2);
            strcat(temp, ")");
            push(&s, temp);
        }
    }
    return pop(&s);
}

int evaluate(char *infix) {
    struct stack s;
    s.top = -1;
    int i, op1, op2, result;
    char temp[MAX_SIZE];
    char *operand1,*operand2;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            temp[0] = infix[i];
            temp[1] = '\0';
            push(&s, temp);
        } else if (isOperator(infix[i])) {
            operand2 = pop(&s);
            operand1 = pop(&s);
            op1 = atoi(operand1);
            op2 = atoi(operand2);
            switch (infix[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = op1 ^ op2;
                    break;
            }
            sprintf(temp, "%d", result);
            push(&s, temp);
        }
    }
    return atoi(pop(&s));
}

int main() {
    char postfix[MAX_SIZE], *infix;
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    infix = convertToInfix(postfix);
    printf("Infix expression: %s\n", infix);
    printf("Result: %d\n", evaluate(infix));
    return 0;
}
