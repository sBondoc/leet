#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

void print_list(struct Node **head)
{
	struct Node *n = *head;
	fprintf(stdout, "{");
	while (n)
	{
		fprintf(stdout, "%d, ", n->data);
		n = n->next;
	}
	fprintf(stdout, "\b\b}\n");
}

struct Node *node_new(int data)
{
	struct Node *ret = NULL;
	ret = malloc(sizeof(struct Node));
	if (!ret)
	{
		perror("Failed to malloc \"ret\" in \"node_new()\". Try downloading more RAM.\n");
		return NULL;
	}
	ret->data = data;
	ret->next = NULL;
	return ret;
}

struct Node *add_node(struct Node **head, int data)
{
	struct Node *ret = node_new(data);
	struct Node *n = *head;
	if (!*head)
	{
		*head = ret;
		return ret;
	}
	while (n->next)
	{
		n = n->next;
	}
	n->next = ret;
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

struct Node *list_from_arr(int arr[], int size)
{
	struct Node *ret;
	if (0 < size)
	{
		ret = node_new(arr[0]);
	}
	for (int i = 1; i < size; i++)
	{
		add_node(&ret, arr[i]);
	}
	return ret;
}

struct Node *list_no_duplicates_old(struct Node *head)
{
	struct Node *ret = NULL, *n = head;
	int data;
	while (n)
	{
		data = n->data;
		if ((n->next) && (n->next->data == data))
		{
			while ((n->next) && (n->next->data == data))
			{
				n = n->next;
			}
		}
		else
		{
			add_node(&ret, data);
		}
		n = n->next;
	}
	return ret;
}

struct Node *list_no_duplicates(struct Node *head)
{
	struct Node *n = head, *n_prev = NULL;
	int data;
	while (n)
	{
		data = n->data;
		if (n->next && (n->next->data == data))
		{
			struct Node *d = n, *d_next = NULL;
			while (d && (d->data == data))
			{
				d_next = d->next;
				free(d);
				d = d_next;
			}
			if (n_prev)
			{
				n = n_prev;
				n->next = d;
			}
			else
			{
				head = d;
				n = d;
				n_prev = NULL;
			}
		}
		else
		{
			n_prev = n;
			n = n->next;
		}
	}
	return head;
}

int main(int argc, char *argv[])
{
	int arr[] = {1, 1, 1, 2, 3};
	struct Node *head = list_from_arr(arr, 5);
	print_list(&head);
	head = list_no_duplicates(head);
	print_list(&head);
	delete_list(&head);
	return EXIT_SUCCESS;
}
