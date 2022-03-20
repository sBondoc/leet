#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *random;
};

void print_list(struct Node **head)
{
	for (struct Node *n = *head; n; n = n->next)
	{
		fprintf(stdout, "%p: data = %d, random = %p\n", (void *) n, n->data, (void *) n->random);
	}
}

struct Node *node_new(int data)
{
	struct Node *ret = NULL;
	ret = malloc(sizeof(struct Node));
	if (!ret)
	{
		fprintf(stderr, "Failed to malloc(). Try downloading more RAM.\n");
		return NULL;
	}
	ret->data = data;
	ret->next = NULL;
	ret->random = NULL;
	return ret;
}

struct Node *tail(struct Node **head)
{
	struct Node *ret = *head;
	if (!ret)
	{
		return NULL;
	}
	while (ret->next)
	{
		ret = ret->next;
	}
	return ret;
}

struct Node *node_add(struct Node **head, int data)
{
	struct Node *ret = node_new(data), *t = tail(head);
	if (t)
	{
		t->next = ret;
	}
	else
	{
		*head = ret;
	}
	return ret;
}

void delete_list(struct Node **head)
{
	struct Node *n = *head, *next = NULL;
	if (!n)
	{
		return;
	}
	while (n)
	{
		next = n->next;
		free(n);
		n = next;
	}
}

struct Node *node_index(struct Node **head, int k)
{
	if (k < 0)
	{
		return NULL;
	}
	struct Node *ret = *head;
	for (int i = 0; i < k; i++)
	{
		if (!ret)
		{
			return NULL;
		}
		ret = ret->next;
	}
	return ret;
}

struct Node *list_from_arr(int arr[][2], int size)
{
	struct Node *ret = NULL;
	if (0 < size)
	{
		ret = node_new(arr[0][0]);
	}
	else
	{
		return NULL;
	}
	struct Node *n = ret;
	for (int i = 1; i < size; i++)
	{
		n->next = node_new(arr[i][0]);
		n = n->next;
	}
	n = ret;
	for (int i = 0; i < size; i++)
	{
		n->random = node_index(&ret, arr[i][1]);
		n = n->next;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int arr[][2] = 
	{
		{7, -1},
		{13, 0},
		{11, 4},
		{10, 2},
		{1, 0},
	};
	struct Node *head = list_from_arr(arr, sizeof(arr) / sizeof(arr[0]));
	print_list(&head);
	delete_list(&head);
	fprintf(stdout, "end\n");
	return EXIT_SUCCESS;
}
