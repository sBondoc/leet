#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *create_node(int data)
{
	struct Node *new = NULL;
	new = malloc(sizeof(struct Node));
	if (!new)
	{
		fprintf(stderr, "Failed to malloc! Try downloading more RAM.\n");
	}
	new->data = data;
	new->next = NULL;
	return new;
}
int fprintarr(FILE *stream, int *arr, int size)
{
	int c = fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		c += fprintf(stream, "%d, ", arr[i]);
	}
	return c + fprintf(stream, "%d}", arr[size - 1]);
}
int fprintlist(FILE *stream, struct Node *head)
{
	int c = fprintf(stream, "{");
	struct Node *n = NULL;
	for (n = head; n->next; n = n->next)
	{
		c += fprintf(stream, "%d, ", n->data);
	}
	return c + fprintf(stream, "%d}", n->data);
}
void delete_node(struct Node **node)
{
	memset(*node, 0, sizeof(struct Node));
	free(*node);
}
struct Node *tail(struct Node *head)
{
	struct Node *n = head->next;
	while (n->next)
	{
		n = n->next;
	}
	return n;
}
struct Node *list_from_arr(int *arr, int size)
{
	struct Node *head = create_node(arr[0]);
	struct Node *n = head;
	for (int i = 1; i < size; i++)
	{
		n->next = create_node(arr[i]);
		n = n->next;
	}
	return head;
}
struct Node *node_from_index(struct Node *head, int index)
{
	struct Node *n = head->next;
	for (int i = 0; (i < index - 1) && (n->next); i++)
	{
		n = n->next;
	}
	return n;
}
struct Node *detect_cycle(struct Node *head)
{
	if (!head)
	{
		return NULL;
	}
	struct Node *slow = head->next, *fast;
	if (head->next)
	{
		fast = head->next->next;
	}
	while (fast != slow)
	{
		if (!fast || !slow)
		{
			return NULL;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
		}
		else
		{
			return NULL;
		}
	}
	if (!fast || !slow)
	{
		return NULL;
	}
	struct Node *from_start = head, *from_intersection = slow;
	while (from_start != from_intersection)
	{
		from_start = from_start->next;
		from_intersection = from_intersection->next;
	}
	return from_start;
}
void delete_list(struct Node *head)
{
	struct Node *n = head, *next = NULL;
	while (n)
	{
		next = n->next;
		delete_node(&n);
		n = next;
	}
}
int main(void)
{
	int arr[] = {3, 2, 0, -4};
	int size = sizeof(arr) / sizeof(arr[0]);
	fprintarr(stdout, arr, size);
	fprintf(stdout, "\n");
	struct Node *head = list_from_arr(arr, size);
	fprintlist(stdout, head);
	fprintf(stdout, "\n");
	fprintf(stdout, "Tail value is %d.\n", tail(head)->data);
	tail(head)->next = node_from_index(head, 1);
	fprintf(stdout, "Cycle start: %p\n", (void *) detect_cycle(head));
	delete_list(head);
	return EXIT_SUCCESS;
}
