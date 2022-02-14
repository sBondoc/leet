#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

void node_next(struct Node *n, int depth, int *depth_max)
{
	if (n != NULL)
	{
		if ((n->left == NULL) && (n->right == NULL) && (*depth_max < depth))
		{
			*depth_max = depth;
		}
		else
		{
			node_next(n->left, depth + 1, depth_max);
			node_next(n->right, depth + 1, depth_max);
		}
	}
}

int depth_max(struct Node *root)
{
	int ret = 0;
	node_next(root, 1, &ret);
	return ret;
}

int main(int argc, char *argv[])
{
	struct Node node7 =
	{
		.data = 7,
		.left = NULL,
		.right = NULL,
	};
	struct Node node15 =
	{
		.data = 15,
		.left = NULL,
		.right = NULL,
	};
	struct Node node20 =
	{
		.data = 20,
		.left = &node15,
		.right = &node7,
	};
	struct Node node9 =
	{
		.data = 9,
		.left = NULL,
		.right = NULL,
	};
	struct Node node3 =
	{
		.data = 3,
		.left = &node9,
		.right = &node20,
	};
	printf("Max depth = %d\n", depth_max(&node3));
	return EXIT_SUCCESS;
}
