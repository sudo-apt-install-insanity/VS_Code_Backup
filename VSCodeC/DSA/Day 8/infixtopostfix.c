// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};

Stack *createStack(unsigned capacity)
{
	Stack *st = (Stack *)
		malloc(sizeof(Stack));

	if (!st)
		return NULL;

	st->top = -1;
	st->capacity = capacity;

	st->array = (int *)malloc(st->capacity * sizeof(int));

	return st;
}
int isEmpty(Stack *st)
{
	return st->top == -1;
}
char peek(Stack *st)
{
	return st->array[st->top];
}
char pop(Stack *st)
{
	if (!isEmpty(st))
		return st->array[st->top--];
}
void push(Stack *st, char op)
{
	st->array[++st->top] = op;
}

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int infixToPostfix(char *exp)
{
	int i, k;

	Stack *st = createStack(strlen(exp));
	if (!st)
		return -1;

	for (i = 0, k = -1; exp[i]; ++i)
	{

		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(st, exp[i]);
		else if (exp[i] == ')')
		{
			while (!isEmpty(st) && peek(st) != '(')
				exp[++k] = pop(st);
			if (!isEmpty(st) && peek(st) != '(')
				return -1;
			else
				pop(st);
		}
		else
		{
			while (!isEmpty(st) && precedence(exp[i]) <= precedence(peek(st)))
				exp[++k] = pop(st);
			push(st, exp[i]);
		}
	}
	while (!isEmpty(st))
		exp[++k] = pop(st);

	exp[++k] = '\0';
	printf("Postfix expression : %s", exp);
}

int main()
{
	char exp[20];
	printf("Enter expression : ");
	scanf("%s",exp);
	infixToPostfix(exp);
	return 0;
}
