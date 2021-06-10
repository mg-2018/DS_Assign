#include <stdio.h>

int main(void)
{
	int i;
	int deletePos;
	int ary[6];
	
	printf("Enter element in array: ");
	for(i=0; i<5; i++)
	{
		scanf("%d", (ary+i));
	}
		
	printf("Stored element in array: ");
	for(i=0; i<5; i++)
	{
		printf("%d ", ary[i]);
	}
		
	puts("");
	
	printf("Enter pos. of element to delete: ");
	scanf("%d", &deletePos);
	
	for(i=deletePos; i<5; i++)
	{
		ary[i-1] = ary[i];
	}
	
	printf("After deletion elements in array: ");
	for(i=0; i<4; i++)
	{
		printf("%d ", ary[i]);
	}
	
	puts("");
	
	return 0;
}

