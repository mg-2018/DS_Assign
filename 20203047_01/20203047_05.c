#include <stdio.h>

int main(void)
{
	int i;
	int frontTrack=0, rearTrack=0;
	int mode, data;
	int queue[3] = {0};
	int size = sizeof(queue)/sizeof(int);
	
	while(1)
	{
		puts("1. Insertion\n2. Deletion\n3. Display\n0. Exit\n");
		printf(">> Select option: ");
		scanf("%d", &mode);
		
		switch(mode)
		{
			case 0:
				return 0;
				
			case 1:
				printf("Element: ");
				scanf("%d", &data);
				if(frontTrack == size && rearTrack == size)
				{
					frontTrack = 0;
					rearTrack = 0;
				}
				
				else if(frontTrack >= size)
				{
					puts("Queue is full\n");
					break;
				}
				queue[frontTrack++] = data;
				puts("Successfully insert\n");
				
				break;
				
			case 2:
				if(frontTrack == rearTrack)
				{
					puts("Queue is empty\n");
				}
				
				else
				{
					printf("Deleted item: %d\n\n", queue[rearTrack]);
					queue[rearTrack++] = 0;
				}
				break;
				
			case 3:
				printf("Items: ");
				for(i=rearTrack; i<frontTrack; i++)
				{
					printf("%d ", queue[i]);
				}
				puts("\n");
				break;
		}
	}
}

