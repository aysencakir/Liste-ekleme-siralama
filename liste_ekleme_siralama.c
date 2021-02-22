
#include <stdio.h> 
#include <stdlib.h> 

typedef struct node

{
	int data;
	struct node* next;

}Liste;

Liste* getNode()

{
	Liste* node;

	node = (Liste*)malloc(sizeof(Liste));

	return node;
}

Liste* insert(Liste* head, int data)

{

	if (head == NULL)

	{
		head = getNode();
		head->data = data;
		head->next = NULL;
		return head;

	}

	Liste* temp = getNode();
	temp->data = data;
	temp->next = NULL;
	Liste* list = head;

	while (head->next != NULL)
	{
		head = head->next;
	}

	head->next = temp;
	return list;

}

void printList(Liste* head)
{
	if (head == NULL)
		return;

	printf("%d ", head->data);
	printList(head->next);

}
void swap(Liste* a, Liste* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;

}
void bubbleSort(Liste* start)

{
	int swapped, i;
	Liste* ptr1;
	Liste* lptr = NULL;

	if (start == NULL)
		return;

	do

	{

		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;

	} while (swapped);

}

int main()

{

	int a;

	Liste* list = NULL;

	list = insert(list, 4);
	list = insert(list, 2);
	list = insert(list, 1);
	list = insert(list, 5);
	list = insert(list, 6);

	printf("Dizinin suanki hali: ");
	printList(list);

	printf("\nEklemek istediginiz sayiyi giriniz:");
	scanf_s("%d", &a);
	list = insert(list, a);


	bubbleSort(list);

	printList(list);

	return 0;

}