#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LEN_MAX 3000

bool slash_slash(char *str, int i)
{
	return
	(str[i] && (str[i] == '/')) &&
	((str[i + 1] == '/') || !str[i + 1]);
}

bool dot(char *str, int i)
{
	return
	(str[i] && (str[i] == '/')) &&
	(str[i + 1] && (str[i + 1] == '.')) &&
	((str[i + 2] == '/') || !str[i + 2]);
}

bool dot_dot(char *str, int i)
{
	return
	(str[i] && (str[i] == '/')) &&
	(str[i + 1] && (str[i + 1] == '.')) &&
	(str[i + 2] && (str[i + 2] == '.')) &&
	((str[i + 3] == '/') || !str[i + 3]);
}

/*
char *canonical_old(char *path)
{
	int top = -1, len_last = 0;
	static char stack[LEN_MAX];
	memset(stack, 0, LEN_MAX * sizeof(char));
	#ifdef DEBUG
	fprintf(stdout, "\t%s\n", path);
	fprintf(stdout, "\t====\n");
	#endif
	for (int i = 0; path[i]; i++)
	{
		#ifdef DEBUG
		char msg[16];
		#endif
		if (dot(path, i))
		{
			#ifdef DEBUG
			memcpy(msg, "dot", 4 * sizeof(char));
			#endif
			i++;
		}
		else if (dot_dot(path, i))
		{
			#ifdef DEBUG
			memcpy(msg, "dot_dot", 8 * sizeof(char));
			#endif
			i += 2;
			top -= len_last;
			len_last = 0;
		}
		else if (slash_slash(path, i)) {}
		else
		{
			#ifdef DEBUG
			memcpy(msg, "other", 6 * sizeof(char));
			#endif
			if ((top < 0) || (stack[top] == '/'))
			{
				len_last = 0;
			}
			if ((top < 0) || !((stack[top] == '/') && (path[i] == '/')))
			{
				stack[++top] = path[i];
				len_last++;
			}
		}
		#ifdef DEBUG
		stack[top + 1] = 0;
		fprintf(stdout, "\t%s\t\t\t(%s) top = %d len_last = %d\n", stack, msg, top, len_last);
		#endif
	}
	if (top < 0)
	{
		stack[++top] = '/';
	}
	if ((stack[top] =='/') && (0 < top))
	{
		top--;
	}
	stack[++top] = 0;
	#ifdef DEBUG
	fprintf(stdout, "\ttop = %d\n", top);
	fprintf(stdout, "\t====\n");
	#endif
	return stack;
}
*/

char *canonical(char *path)
{
	static char ret[3000];
	int top = -1;
	for (int i = 0; path[i]; i++)
	{
		if (dot(path, i))
		{
			i++;
		}
		else if (dot_dot(path, i))
		{
			i += 2;
			while ((0 < top) && (ret[top] != '/'))
			{
				top--;
			}
			if (-1 < top)
			{
				top--;
			}
		}
		else if (slash_slash(path, i))
		{
			while (slash_slash(path, i + 1))
			{
				i++;
			}
		}
		else
		{
			if (top < -1)
			{
				top = -1;
			}
			ret[++top] = path[i];
		}
	}
	if (top < 0)
	{
		ret[top = 0] = '/';
	}
	ret[++top] = '\0';
	return ret;
}

int main(void)
{
	char *paths[] =
	{
		"/home/",
		"/../",
		"/home//foo",
		"/a/./b/../../c",
		"/a//b////c/d//././/////..",
		"/home/foo/.ssh/../.ssh2/authorized_keys/",
		"/a/./b/../../c/",
		"/a/../../b/../c//.//",
	};
	int count = (int) sizeof(paths) / sizeof(paths[0]);
	for (int i = 0; i < count; i++)
	{
		#ifdef DEBUG
		fprintf(stdout, "%s\n", paths[i]);
		#endif
		fprintf(stdout, "%s\n", canonical(paths[i]));
	}
	return EXIT_SUCCESS;
}
