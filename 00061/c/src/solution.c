#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
	int data;
	struct Node *next;
};

int fprintlist(FILE *stream, struct Node **head)
{
	int ret = fprintf(stream, "{");
	struct Node *n = *head;
	while (n && n->next)
	{
		ret += fprintf(stream, "%d, ", n->data);
		n = n->next;
	}
	if (n)
	{
		ret += fprintf(stream, "%d", n->data);
	}
	ret += fprintf(stream, "}");
	return ret;
}

struct Node *node_new(int data)
{
	struct Node *ret = NULL;
	ret = malloc(sizeof(struct Node));
	if (!ret)
	{
		fprintf(stderr, "Failed to malloc! Try downloading more RAM.\n");
		return NULL;
	}
	ret->data = data;
	ret->next = NULL;
	return ret;
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

struct Node *node_tail(struct Node **head)
{
	struct Node *n = *head;
	if (!n)
	{
		return NULL;
	}
	while (n->next)
	{
		n = n->next;
	}
	return n;
}

struct Node *node_add(struct Node **head, int data)
{
	struct Node *ret = node_new(data), *n = node_tail(head);
	n->next = ret;
	return ret;
}

int list_length(struct Node **head)
{
	int ret = 0;
	for (struct Node *n = *head; n; n = n->next)
	{
		ret++;
	}
	return ret;
}

struct Node *node_index(struct Node **head, int i)
{
	struct Node *ret = *head;
	for (int k = 0; (k < i) && ret; k++)
	{
		ret = ret->next;
	}
	return ret;
}

struct Node *arr_to_list(int *arr, int size)
{
	struct Node *ret = NULL, *n = NULL;
	if (0 < size)
	{
		ret = node_new(arr[0]);
		n = ret;
	}
	for (int i = 1; i < size; i++)
	{
		n->next = node_new(arr[i]);
		n = n->next;
	}
	return ret;
}

struct Node *rotate_right(struct Node *head, int k)
{
	if (!head)
	{
		return head;
	}
	int length = list_length(&head);
	k = length - k % length;
	node_tail(&head)->next = head;
	struct Node *ret = node_index(&head, k);
	node_index(&head, k - 1)->next = NULL;
	return ret;
}

int main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 5};
	struct Node *head = arr_to_list(arr, 5);
	fprintf(stdout, "list = ");
	fprintlist(stdout, &head);
	fprintf(stdout, "\n");
	fprintf(stdout, "list.length = %d\n", list_length(&head));
	fprintf(stdout, "list[%d] = %d\n", 3, node_index(&head, 3)->data);
	head = rotate_right(head, 2);
	fprintf(stdout, "%d\n", head->data);
	fprintf(stdout, "list = ");
	fprintlist(stdout, &head);
	fprintf(stdout, "\n");
	delete_list(&head);
	return EXIT_SUCCESS;
}
