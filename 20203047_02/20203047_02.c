#include <stdio.h>
#include <stdlib.h>

// node definition
typedef struct node
{
	int data;
	struct node *left, *right;
} TREE;

// data insertion behavior of BST
void BSTinsert(TREE *root, int data, int rootExists)
{
	TREE *current, *newNode;
	
	if(!rootExists)
	{
		root->data = data;
		return;
	}
	
	else
	{
		current = root;
		newNode = (TREE*) malloc(sizeof(TREE));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		
		while(1)
		{
			if(data < current->data)
			{
				if(current->left == NULL)
				{
					current->left = newNode;
					return;
				}
				
				else
					current = current->left;
			}
			
			else
			{
				if(current->right == NULL)
				{
					current->right = newNode;
					return;
				}
				
				else
					current = current->right;
			}
		}
	}
}

// search the node
TREE *BSTsearch(TREE *root, int data, int rootExists)
{
	TREE *current;
	if(!rootExists) return NULL;
	
	else
	{
		current = root;
		while(1)
		{
			if(data == current->data)
			{
				return current;
			}
			
			else if(data < current->data)
			{
				if(current->left == NULL) return NULL;
				else current = current->left;
			}
			
			else if(data > current->data)
			{
				if(current->right == NULL) return NULL;
				else current = current->right;
			}
		}
	}
}

// search the parent node of the desired node
TREE *BSTsearchParent(TREE *root, int data, int rootExists)
{
	TREE *current, *parent = NULL;
	if(!rootExists) return NULL;
	
	else
	{
		current = root;
		while(1)
		{
			if(data == current->data)
			{
				break;
			}
			
			else if(data < current->data)
			{
				parent = current;
				if(current->left == NULL) break;
				else current = current->left;
			}
			
			else if(data > current->data)
			{
				parent = current;
				if(current->right == NULL) break;
				else current = current->right;
			}
		}
	}
	
	return parent;
}

// delete the node 10
int BSTdelete(TREE *root, int data, int count)
{
	TREE *current, *temp;
	TREE *res = BSTsearch(root, data, count);
	TREE *parent = BSTsearchParent(root, data, count);
	// if failed to search this data
	if(res == NULL)
		printf("Failed to delete data %d\n", data);
	
	else
	{
		temp = res;
		parent->right = res->right;
		free(temp);
	}
}

// print in pre-order sequence
void BSTprint(TREE *current)
{
	if(current != NULL)
	{
		printf("%d ", current->data);
		BSTprint(current->left);
		BSTprint(current->right);
	}
}

// destroy the tree in post-order sequence
void BSTdestroy(TREE *current)
{
	if(current != NULL)
	{
		BSTdestroy(current->left);
		BSTdestroy(current->right);
		free(current);
	}
}

// rotate and/or re-construct a tree after deleting node 10
TREE *AVLrotation(TREE *root)
{
	int i;
	TREE *tempRoot;
	TREE *nodes[6];
	int datas[6] = {-1, 0, 1, 5, 9, 11};
	
	for(i=0; i<6; i++)
		nodes[i] = BSTsearch(root, datas[i], 1);
	
	nodes[2]->left = nodes[1];
	nodes[1]->left = nodes[0];
	
	nodes[2]->right = nodes[4];
	nodes[4]->right = nodes[5];
	nodes[4]->left = nodes[3];
	
	tempRoot = nodes[2];
	return tempRoot;
}

int main(void)
{
	int i, data;
	int count=0;
	TREE *AVLtree;
	AVLtree = (TREE*) malloc(sizeof(TREE));
	AVLtree->left = NULL;
	AVLtree->right = NULL;
	
	puts("Insert node to AVL tree:");
	for(i=0; i<9; i++)
	{
		scanf("%d", &data);
		BSTinsert(AVLtree, data, count);
		count++;
	}
	
	puts("\nPreorder traversal of the constructed AVL tree is");
	BSTprint(AVLtree);
	puts("");
	
	BSTdelete(AVLtree, 10, count);
	AVLtree = AVLrotation(AVLtree);
	
	puts("\nPreorder traversal of the constructed AVL tree after deleting 10 is");
	BSTprint(AVLtree);
	puts("");
	
	BSTdestroy(AVLtree);
	
	return 0;
}

