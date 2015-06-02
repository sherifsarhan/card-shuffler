//Sherif Sarhan
//This part of the program allows for a linked list representation of any data type.

#include <stdio.h>
#include <stdlib.h>
//defines a structure for the nodes;
struct Node
{
	int data;
	struct Node *next;
};

//pre-processor function declarations
struct Node *newList(void);
struct Node *delete(struct Node * prev);
struct Node *insert(struct Node *prev, int data);
int length(struct Node *head);
void printList(struct Node *head);

int main()
{
	//seeds the random function with last four of g number
	srandom(5457);
	//creates new head node that points to empty list
	struct Node* head = newList();
	//inserts 10 random numbers between 0-1000
	int i;
	for (i=0; i<10; i++)
	{
		int rand_num = random()%1000;
		insert(head, rand_num);
		printf("The Length is: %d\n", length(head));
		printf("Here is the list: \n");
		printList(head);
	}
	//insert(head, 50);
	//printList(head);
	//delete(head);
	//printList(head);
}

//returns a head of a new empty list
struct Node *newList(void)
{
	//allocates memory for the node pointer
	struct Node* head = malloc(sizeof(struct Node));
	//sets next to NULL
	head->next = NULL;
	return head;
}

//deletes the node after prev
struct Node *delete(struct Node *prev)
{
	//creates temp node to store the node after the one to be deleted
	struct Node* temp = prev->next->next;
	//frees the memory for the one to be deleted
	free(prev->next);
	//sets the link between the deleted node
	prev->next = temp;
}

//inserts a new node with data field data after prev
struct Node *insert(struct Node *prev, int data)
{
	//creates a new node
	struct Node* nodeNew = malloc(sizeof(struct Node));
	//assigns the random number to its data
	nodeNew->data = data;
	//makes a new head node to be used as copy
	struct Node* temp = newList();
	temp = prev;
	//checks to see if there is a value after node
	while (temp->next != NULL)
		{
			//checks if the data is less than next node
			if (temp->next->data < data)
			{
				//if so, keep moving until you find data >
				temp = temp->next;
			}
			else
			{
				break;
			}
		}
	//sets the new node's next equal to the temp's next
	nodeNew->next = temp->next;	
	temp->next=nodeNew;	
}

//TODO
//number of elements in the list
int length(struct Node *head)
{
	int count=0;
	//counts how many have 
	while (head->next != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

//TODO
//print the data fields for the entire list
void printList(struct Node *head)
{
	//finds length
	int listlen = length(head);
	int i;
	//loops until length
	for (i=0; i<listlen; i++)
	{
		printf("%d\n", head->next->data);
		head = head->next;
	}
}
