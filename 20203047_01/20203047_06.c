#include <stdio.h>

int main(void)
{
	int i;
	int top=0, data;
	int mode;
	int stack[1000] = {0};
	
	while(1)
	{
		printf("1. push\n2. pop\n3. display\n4. exit\n\n");
		
		printf("Enter your choice: ");
		scanf("%d", &mode);
		
		switch(mode)
		{
			case 1:
				printf("Enter element in stack: ");
				scanf("%d", &data);
				stack[top++] = data;
				break;
				
			case 2:
				if(top == 0)
				{
					puts("Stack is empty\n");
				}
				
				else
				{
					printf("deleted data is: %d\n\n", stack[--top]);
					stack[top] = 0;
				}
				break;
				
			case 3:
				for(i=top-1; i>=0; i--)
				{
					printf("%d\n", stack[i]);
				}
				break;
			
			case 4:
				return 0;
		}
		while(getchar() != '\n');
		
		while(1)
		{
			printf("Pushed an element (Y/N): ");
			scanf("%c", &mode);
			
			if(mode == 'y' || mode == 'Y')
			{
				printf("Enter element in stack: ");
				scanf("%d", &data);
				stack[top++] = data;
			}
			
			else
			{
				break;
			}
			while(getchar() != '\n');
		}
	}
}

