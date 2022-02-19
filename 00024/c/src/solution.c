#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

void print_list(struct Node **head)
{
	printf("{");
	if (*head)
	{
		struct Node *n = *head;
		while (n->next)
		{
			printf("%d, ", n->data);
			n = n->next;
		}
		printf("%d", n->data);
	}
	printf("}\n");
}

void delete_list(struct Node **head)
{
	if (*head)
	{
		struct Node *n = *head;
		while (n)
		{
			struct Node *next = n->next;
			free(n);
			n = next;
		}
	}
	*head = NULL;
}

struct Node *node_new(int data)
{
	struct Node *n = NULL;
	n = malloc(sizeof(struct Node));
	if (!n)
	{
		perror("Failed to malloc new node. Try downloading more RAM.\n");
		return NULL;
	}
	n->data = data;
	n->next = NULL;
	return n;
}

struct Node *tail(struct Node **head)
{
	struct Node *ret = NULL;
	if (*head)
	{
		ret = *head;
		while (ret->next)
		{
			ret = ret->next;
		}
	}
	return ret;
}

struct Node *node_add(struct Node **head, int data)
{
	struct Node *n = node_new(data);
	if (*head)
	{
		tail(head)->next = n;
	}
	else
	{
		*head = n;
	}
	return n;
}

struct Node *swap_pairs(struct Node *head)
{
	struct Node *head_new = NULL, *n = head;
	while (n && n->next)
	{
		node_add(&head_new, n->next->data);
		node_add(&head_new, n->data);
		n = n->next->next;
	}
	if (n)
	{
		node_add(&head_new, n->data);
	}
	delete_list(&head);
	return head_new;
}

int main(int argc, char *argv[])
{
	struct Node *head = NULL;
	for (int i = 1; i < ((1 < argc) ? argc : 5); i++)
	{
		node_add(&head, (1 < argc) ? strtol(argv[i], NULL, 10) : i);
	}
	print_list(&head);
	head = swap_pairs(head);
	print_list(&head);
	delete_list(&head);
	return EXIT_SUCCESS;
}
