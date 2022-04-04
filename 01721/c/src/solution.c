#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

void fprintlist(struct Node **head)
{
	fprintf(stdout, "{");
	struct Node *n = *head;
	if (n)
	{
		for (; n->next; n = n->next)
		{
			fprintf(stdout, "%d, ", n->data);
		}
		fprintf(stdout, "%d", n->data);
	}
	fprintf(stdout, "}\n");
}

struct Node *node_new(int data)
{
	struct Node *new = NULL;
	new = malloc(sizeof(struct Node));
	if (!new)
	{
		fprintf(stderr, "Failed to malloc. Try downloading more RAM.\n");
		return NULL;
	}
	new->data = data;
	new->next = NULL;
	return new;
}

void delete_list(struct Node **head)
{
	struct Node *n = *head, *next = NULL;
	while (n)
	{
		next = n->next;
		free(n);
		n = next;
	}
}

struct Node *tail(struct Node **head)
{
	struct Node *n = *head;
	if (!n)
	{
		return NULL;
	}
	for (; n->next; n = n->next);
	return n;
}

struct Node *node_add(struct Node **head, int data)
{
	struct Node *new = node_new(data);
	if (*head)
	{
		tail(head)->next = new;
	}
	else
	{
		*head = new;
	}
	return new;
}

struct Node *list_from_arr(int *arr, int size)
{
	if (size < 1)
	{
		return NULL;
	}
	struct Node *head = node_new(arr[0]);
	struct Node *n = head;
	for (int i = 1; i < size; i++)
	{
		n->next = node_new(arr[i]);
		n = n->next;
	}
	return head;
}

struct Node *swap(struct Node *head, int k)
{
	//code 
	return NULL;
}

int main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 5}, size = sizeof(arr) / sizeof(arr[0]);
	struct Node *head = list_from_arr(arr, size);
	fprintlist(&head);
	delete_list(&head);
	return EXIT_SUCCESS;
}
