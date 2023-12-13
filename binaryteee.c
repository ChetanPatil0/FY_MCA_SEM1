#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct btree
{
	int data;
	struct btree *left;
	struct btree *right;
};

typedef struct btree *NODEPTR;
#define NODEALLOC (struct btree *)malloc(sizeof(struct btree))

NODEPTR create(NODEPTR);
void insert(NODEPTR, NODEPTR);
void inorder(NODEPTR);
void preorder(NODEPTR);
void postorder(NODEPTR);
void printLeafNodes(NODEPTR);
NODEPTR mirrorImage(NODEPTR);
void displayLevelWise(NODEPTR);

void main()
{
	NODEPTR root = NULL;
	int choice;
	do
	{
		printf("\n\nMENU");
		printf("\n\n1. Create Binary Tree");
		printf("\n2. Preorder Traversal");
		printf("\n3. Print Leaf Nodes");
		printf("\n4. Mirror Image");
		printf("\n5. Display Level Wise");
		printf("\n6. height");
printf("\n7. Exit");
		printf("\n\n----------------------");
		printf("\n\nEnter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			root = create(root);
			break;

		case 2:
			printf("\nPreorder Traversal : ");
			preorder(root);
			break;

		case 3:
			printf("\nLeaf Nodes : ");
			printLeafNodes(root);
			break;

		case 4:
			root = mirrorImage(root);
			printf("\nMirror Image created.");
			break;

		case 5:
			printf("\nDisplaying Level Wise:\n");
			displayLevelWise(root);
			break;
			case 6:
			printf("\nHeight of Tree %d:\n",height(root));

			break;
		}
	} while (choice != 7);
	getch();
}

NODEPTR create(NODEPTR root)
{
	NODEPTR n;
	char ans;
	do
	{
		n = NODEALLOC;
		n->left = NULL;
		n->right = NULL;

		printf("Enter the element : ");
		scanf("%d", &n->data);
		if (root == NULL)
			root = n;
		else
			insert(root, n);
		printf("\nDo you want to continue(Y/N)?\t : ");

		ans = getch();
	} while (ans == 'Y' || ans == 'N');
	return root;
}

void insert(NODEPTR root, NODEPTR n)
{
	char ch;
	printf("\nWhere to insert data to left/right of %d(L/R) : ", root->data);

	ch = getch();
	if (ch == 'r' || ch == 'R')
	{
		if (root->right == NULL)
			root->right = n;
		else
			insert(root->right, n);
	}
	else
	{
		if (root->left == NULL)
			root->left = n;
		else
			insert(root->left, n);
	}
}

void preorder(NODEPTR root)
{
	if (root != NULL)
	{
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void printLeafNodes(NODEPTR root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
			printf("%d\t", root->data);
		else
		{
			printLeafNodes(root->left);
			printLeafNodes(root->right);
		}
	}
}

NODEPTR mirrorImage(NODEPTR root)
{
	if (root != NULL)
	{
		NODEPTR temp;
		// Swap left and right subtrees
		temp = root->left;
		root->left = root->right;
		root->right = temp;

		// Recursively mirror left and right subtrees
		mirrorImage(root->left);
		mirrorImage(root->right);
	}
	return root;
}

int height(NODEPTR root)
{
	if (root == NULL)
		return 0;
	else
	{
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
	}
}

void printGivenLevel(NODEPTR root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

void displayLevelWise(NODEPTR root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		printf("Level %d: ", i);
		printGivenLevel(root, i);
		printf("\n");
	}
}
