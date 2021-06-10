#include <stdio.h>

int main(void)
{
	int i;
	int insertPos, newElem;
	int ary[6];
	
	printf("Enter 5 elements in array: ");
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
	
	printf("Enter position for enter element: ");
	scanf("%d", &insertPos);
	printf("Enter new element: ");
	scanf("%d", &newElem);
	
	for(i=5; i>=insertPos; i--)
	{
		ary[i] = ary[i-1];
	}
	ary[insertPos-1] = newElem;
	
	printf("Stored data in array: ");
	for(i=0; i<6; i++)
	{
		printf("%d ", ary[i]);
	}
	
	puts("");
	
	return 0;
}

