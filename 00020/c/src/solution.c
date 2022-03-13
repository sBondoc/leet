#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool match(char c, char open)
{
	return ((c == ')') && (open == '(')) ||
	((c == ']') && (open == '[')) ||
	((c == '}') && (open == '{'));
}

bool valid(char *s)
{
	int top = -1;
	int arr[10000] = {0};
	for (int i = 0; s[i]; i++)
	{
		if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
		{
			arr[++top] = s[i];
		}
		if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
		{
			if (!match(s[i], arr[top--]))
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	char str[] = "()[]{}";
	fprintf(stdout, "%s\n%s\n", str, (valid(str)) ? "true" : "false");
	return EXIT_SUCCESS;
}
