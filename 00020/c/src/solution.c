#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Stack
{
	int top;
	char arr[10000];
};

struct Stack *stack_new(void)
{
	struct Stack *ret = NULL;
	ret = malloc(sizeof(struct Stack));
	if (!ret)
	{
		perror("Malloc failed!\n");
		return NULL;
	}
	ret->top = -1;
	return ret;
}

bool full(struct Stack *stack)
{
	return 9998 < stack->top;
}

char peek(struct Stack *stack)
{
	if (stack->top < 0)
	{
		return '\0';
	}
	return stack->arr[stack->top];
}

void push(struct Stack *stack, char c)
{
	if (full(stack))
	{
		return;
	}
	stack->arr[++(stack->top)] = c;
}

char pop(struct Stack *stack)
{
	if (stack->top < 0)
	{
		return '\0';
	}
	return stack->arr[(stack->top)--];
}

bool close(char c, char open)
{
	return ((c == ')') && (open == '(')) ||
	((c == ']') && (open == '[')) ||
	((c == '}') && (open == '{'));
}

bool valid(char *s)
{
	
	struct Stack stack;	
	for (int i = 0; s[i]; i++)
	{
		if ((s[i] == '(') || (s[i] == '[') || (s[i] == '}'))
		{
			push(&stack, s[i]);
		}
		if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
		{
			if (!close(s[i], pop(&stack)))
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	char str[] = "[[]]()[]";
	fprintf(stdout, "%s\n%s\n", str, (valid(str)) ? "true" : "false");
	return EXIT_SUCCESS;
}
