#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 20
struct BrowserHistory
{
	int current;
	int pages_size;
	int *page_sizes;
	char **pages;
};
void delete_pages(struct BrowserHistory *obj, int from)
{
	if (obj->pages_size <= from)
	{
		return;
	}
	for (int i = from; i < obj->pages_size; i++)
	{
		free(obj->pages[i]);
		obj->pages[i] = NULL;
	}
}
void visit(struct BrowserHistory *obj, char *url)
{
	delete_pages(obj, obj->current + 1);
	int pages_size = ++obj->current + 1;
	obj->pages_size = pages_size;
	obj->page_sizes = realloc(obj->page_sizes, pages_size * sizeof(int));
	obj->pages = realloc(obj->pages, pages_size * sizeof(char *));
	int url_length = strlen(url);
	obj->page_sizes[pages_size - 1] = url_length;
	obj->pages[pages_size - 1] = malloc((url_length + 1) * sizeof(char));
	memcpy(obj->pages[pages_size - 1], url, url_length + 1);

}
struct BrowserHistory *create_browser_history(char *homepage)
{
	struct BrowserHistory *new = NULL;
	new = malloc(sizeof(struct BrowserHistory));
	memset(new, 0, sizeof(struct BrowserHistory));
	new->current = -1;
	visit(new, homepage);
	return new;
}
void delete_browser_history(struct BrowserHistory *obj)
{
	delete_pages(obj, 0);
	free(obj->page_sizes);
	obj->page_sizes = NULL;
	free(obj->pages);
	obj->pages = NULL;
	free(obj);
	obj = NULL;
}
char *back(struct BrowserHistory *obj, int steps)
{
	if (steps <= obj->current)
	{
		return obj->pages[obj->current -= steps];
	}
	return NULL;
}
char *forward(struct BrowserHistory *obj, int steps)
{
	if (obj->current + steps < obj->pages_size)
	{
		return obj->pages[obj->current += steps];
	}
	return NULL;
}
int main(void)
{
	struct BrowserHistory *obj = create_browser_history("google.com");
	char *sites[] =
	{
		"leetcode.com",
		"stackoverflow.com",
		"facebook.com",
	};
	for (int i = 0; i < (int) (sizeof(sites) / sizeof(sites[0])); i++)
	{
		visit(obj, sites[i]);
	}
	for (int i = 0; i < obj->pages_size; i++)
	{
		fprintf(stdout, "%s\n", obj->pages[i]);
	}
	fprintf(stdout, "%s\n", back(obj, 2));
	fprintf(stdout, "%s\n", forward(obj, 1));
	delete_browser_history(obj);
	return EXIT_SUCCESS;
}
