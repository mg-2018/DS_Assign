#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *getNode(node *head, int index)
{
	int i;
	node *current = head;
	for(i=0; i<index; i++)
	{
		current = current->next;
	}
	
	return current;
}

void addData(node *head, node *tail, int data)
{
	node *newNode, *current;
	newNode = (node*) malloc(sizeof(node));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(head->next == NULL)
	{
		head->next = newNode;
	}
	
	else
	{
		current = head;
		while(current->next != NULL)
		{
			current = current->next;
		}
		
		current->next = newNode;
	}
	
	tail = newNode;
}

void insertData(node *head, int data, int index)
{
	node *newNode, *current;
	newNode = (node*) malloc(sizeof(node));
	
	newNode->data = data;
	newNode->next = getNode(head, index);
	
	getNode(head, index-1)->next = newNode;
}

int main(void)
{
	int i, data;
	int insertPos;
	node *list;
	list = (node*) malloc(sizeof(node));
	
	node *head, *tail;
	head = list;
	tail = list;
	list->next = NULL;
	
	printf("Enter 5 elements in list: ");
	for(i=0; i<5; i++)
	{
		scanf("%d", &data);
		addData(head, tail, data);
	}
	
	printf("Stored element in list: ");
	
	i = 0;
	while(getNode(head, i)->next != NULL)
	{
		printf("%d ", getNode(head, ++i)->data);
	}
	
	printf("\nEnter position for enter element: ");
	scanf("%d", &insertPos);
	printf("Enter new element: ");
	scanf("%d", &data);
	
	insertData(head, data, insertPos);
	printf("Stored data in list: ");
	
	i = 0;
	while(getNode(head, i)->next != NULL)
	{
		printf("%d ", getNode(head, ++i)->data);
	}
	
	free(list);
	puts("");
	
	return 0;
}

