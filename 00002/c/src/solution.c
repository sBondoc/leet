#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void print_list(struct Node **head)
{
	printf("{");
	struct Node *n = *head;
	while (n != NULL)
	{
		printf("%d, ", n->data);
		n = n->next;
	}
	printf("\b\b}\n");
}

struct Node *node_new(void)
{
	struct Node *new = NULL;
	new = malloc(sizeof(struct Node));
	if (new == NULL)
	{
		perror("Failed to allocate memory. Try downloading more RAM.\n");
	}
	new->data = -1;
	new->next = NULL;
	return new;
}

void push_data(struct Node **head, int data)
{
	struct Node *new = node_new();
	new->data = data;
	if (*head == NULL)
	{
		*head = new;
	}
	else if (((*head)->data < 0) || (9 < (*head)->data))
	{
		(*head)->data = data;
		free(new);
	}
	else 
	{
		struct Node *n = *head;
		while (n->next != NULL)
		{
			n = n->next;
		}
		n->next = new;
	}
}

void delete_list(struct Node **head)
{
	struct Node *n = *head, *next = NULL;
	while (n != NULL)
	{
		next = n->next;
		free(n);
		n = next;
	}
}

int size_list(struct Node **head)
{
	struct Node *n = *head;
	int ret = 0;
	while (n->next != NULL)
	{
		n = n->next;
		ret++;
	}
	return ret;
}

void int_to_list(struct Node **head, int n)
{
	while (0 < n)
	{
		push_data(head, n % 10);
		n /= 10;
	}
}

struct Node *sum(struct Node *l1, struct Node *l2)
{
	struct Node *a = l1, *b = l2, *ret = node_new();
	int carry = 0, digit_a, digit_b, res;
	while ((a != NULL) || (b != NULL))
	{
		digit_a = (a == NULL) ? 0 : a->data;
		digit_b = (b == NULL) ? 0 : b->data;
		res = digit_a + digit_b + carry;
		push_data(&ret, res % 10);
		carry = res / 10;
		if (a != NULL)
		{
			a = a->next;
		}
		if (b != NULL)
		{
			b = b->next;
		}
	}
	if (carry != 0)
	{
		push_data(&ret, carry);
	}
	return ret;	
}

int main(int argc, char **argv)
{
	struct Node *l1 = NULL, *l2 = NULL;
	int_to_list(&l1, 9999999);
	int_to_list(&l2, 9999);
	print_list(&l1);
	print_list(&l2);
	struct Node *result = sum(l1, l2);
	print_list(&result);
	delete_list(&l1);
	delete_list(&l2);
	delete_list(&result);
	return EXIT_SUCCESS;
}
