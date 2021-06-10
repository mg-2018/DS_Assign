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

void deleteData(node *head, node *tail, int index)
{
	node *temp;
	temp = getNode(head, index);
	
	if(temp == tail)
	{
		free(temp);
		tail = getNode(head, index-1);
		tail->next = NULL;
	}
	
	else
	{
		getNode(head, index-1)->next = getNode(head, index+1);
		free(temp);
	}
}

int main(void)
{
	int i=0, data;
	int deletePos;
	node *list;
	list = (node*) malloc(sizeof(node));
	
	node *head, *tail;
	head = list;
	tail = list;
	list->next = NULL;
	
	printf("Enter element in list: ");
	for(i=0; i<5; i++)
	{
		scanf("%d", &data);
		addData(head, tail, data);
	}
	
	i = 0;
	printf("Stored element in list: ");
	
	while(getNode(head, i)->next != NULL)
	{
		printf("%d ", getNode(head, ++i)->data);
	}
	
	printf("\nEnter pos. of element to delete: ");
	scanf("%d", &deletePos);
	deleteData(head, tail, deletePos);
	
	i = 0;
	printf("After deletion elements in list: ");
	
	while(getNode(head, i)->next != NULL)
	{
		printf("%d ", getNode(head, ++i)->data);
	}
	
	free(list);
	puts("");
	
	return 0;
}

