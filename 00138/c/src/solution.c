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

int length_list(struct Node **head)
{
	int ret = 0;
	for (struct Node *n = *head; n; n = n->next)
	{
		ret++;
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

int index_node(struct Node **head, struct Node *key)
{
	int ret = 0;
	for (struct Node *n = *head; n; n = n->next)
	{
		if (n == key)
		{
			return ret;
		}
		ret++;
	}
	return -1;
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

struct Node *list_copy(struct Node *head)
{
	int length = length_list(&head);
	if (length < 1)
	{
		return NULL;
	}
	int rand[length];
	struct Node *head_src = head, *n_src = head, *ret = NULL, *n_dst = NULL;
	for (int i = 0; i < length; i++)
	{
		rand[i] = index_node(&head_src, n_src->random);
		if (n_dst)
		{
			n_dst->next = node_new(n_src->data);
			n_dst = n_dst->next;
		}
		else
		{
			n_dst = node_new(n_src->data);
			ret = n_dst;
		}
		n_src = n_src->next;
	}
	int i = 0;
	for (struct Node *n = ret; n; n = n->next)
	{
		n->random = node_index(&ret, rand[i]);
		i++;
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
	struct Node *src = list_from_arr(arr, sizeof(arr) / sizeof(arr[0]));
	struct Node *dst = list_copy(src);
	print_list(&src);
	print_list(&dst);
	delete_list(&src);
	delete_list(&dst);
	return EXIT_SUCCESS;
}
