//Sherif Sarhan
//This part of the program allows for a deck of cards to be shuffled randomly.

#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------------------------
//nested structure called data with suit and values fields
struct Data_Struct
{
	char* suit;
	char* values;
	struct Data_Struct *data_point;
};
//creates structure for cards
struct Node
{
	struct Data_Struct *data;
	struct Node *next;
};
//-------------------------------------------------------------------
//pre-processor function declarations
int length(struct Node *head);
void printList(struct Node *head);
struct Node *makeDeck(void);
struct Node *newDeck(void);
struct Node *randomShuffle(struct Node *olddeck);
struct Node *insert(struct Node *prev, struct Data_Struct *data);
//-------------------------------------------------------------------
int main()
{
	//printf("~~~~~~~MAIN FUNCTION~~~~~~~\n");
	struct Node *head = makeDeck();
	printf("-------------------------------------------------------------------------------");
	//printf("\nTHE LENGTH OF THIS DECK IS: %d\n",length(head));
	printf("Here is an ordered Deck: \n");
	printList(head);
	printf("Here is a shufled Deck: \n");
	struct Node *shuffledHead = randomShuffle(head);
	printList(shuffledHead);
}
//-------------------------------------------------------------------
//return a new, unshuffled deck
struct Node *makeDeck(void)
{
	//printf("~~~~~~~MAKEDECK FUNCTION~~~~~~~\n");
	//make new dummy card
	struct Node *head = newDeck();

	//loop through card values and suits and create pairs
	//of values to represent the cards
	//those pairs are then inserted into the list
	//representing the deck.
	
	int suit;
	int value;
	//int count=0;

	//creates char* (string) array for suits
	char* suits[4]= 
	{
		"S","D","H","C"
	};
	//creates one for values
	char* values[13]=
	{
		"A","2","3","4","5","6","7","8","9","10","J","Q","K"
	};
	//loops through suits and values
	for(suit=0; suit<4; suit++)
	{
		for(value=0; value<13; value++)
		{
			//creates new data structure
			struct Data_Struct *card_data = malloc(sizeof(struct Data_Struct));
			//stores suit data
			card_data->suit = suits[suit];
			//printf("SUIT SHOULD BE: %s \n",suits[suit]);
			//printf("SUIT ACTUALLY IS: %s \n\n",card_data->suit);

			//stores values data
			card_data->values = values[value];
			//printf("VALUE SHOULD BE: %s\n",values[value]);
			//printf("VALUE ACTUALLY IS: %s\n\n\n\n",card_data->values);
			
			//inserts card data into a new node
			insert(head, card_data);
			//count++;
		}
	}
	//printf("COUNT IS: %d\n",count);
	return head;
}
//-------------------------------------------------------------------

//Given a deck of cards, return a new, shuffled deck
struct Node *randomShuffle(struct Node *olddeck)
{
	int len = length(olddeck);
	//Make a new linked list newdeck
	struct Node *shuffledDeck = newDeck();
	//int count = 0;
	int i;
	for (i=len-1; i>=0; i--)
	{
		int j = random()%(i+1);
		//move the jth card from olddeck
		//to the front of shuffleDeck
		//make copy of head to move around deck
		struct Node *temp = newDeck();
		temp = olddeck;
		int z;
		//printf("I value is: %d",count);
		//move through old deck until get pointer to removal card
		for (z=0;z<j;z++)
		{
			temp = temp->next;
		}
		//found card at temp->next
		//attempt insertion
		//check if shuffledDeck is last card in new deck
		struct Node *shuffledDeck_temp = newDeck();
		shuffledDeck_temp = shuffledDeck;
		while (shuffledDeck_temp->next != NULL)
		{
			//attempt to make it last card
			shuffledDeck_temp = shuffledDeck_temp->next;
		}
		//set last card in new deck's next to the new card
		struct Node *cardCopy = newDeck();
		cardCopy->data = temp->next->data;
		shuffledDeck_temp->next = cardCopy;
		//set temp->next equal to afterCard
		struct Node *afterCard = newDeck();
		afterCard = temp->next->next;
		//don't want duplicate cards
		free(temp->next);
		temp->next=afterCard;		
		//count++;
	}
	return shuffledDeck;
}

//-------------------------------------------------------------------
//returns a head of a new empty list
struct Node *newDeck(void)
{
	//printf("~~~~~~~NEWDECK FUNCTION~~~~~~~\n");
	struct Node* head = malloc(sizeof(struct Node));
	head->next = NULL;
	return head;
}
//-------------------------------------------------------------------
//inserts a new node with data field data after prev
struct Node *insert(struct Node *prev, struct Data_Struct *datax)
{
	//printf("~~~~~~~INSERT FUNCTION~~~~~~~\n");
	//printf("DATA VALUE: %s\n", datax->suit);
	//make next card
	struct Node* nodeNew = newDeck();
	//give it the data
	nodeNew->data= datax;

	//struct Data_Struct dataCopy = malloc

	//creates temp node
	struct Node* temp = newDeck();
	//sets temp node to prev
	temp = prev;
	while (temp->next != NULL)
	{
		//prev = prev->next;
		temp= temp->next;
	}

	//nodeNew->data->values = datax->values;

	//link new card to previous card
	temp->next = nodeNew;
	//printf("@@@PREV->NEXT->DATA->SUIT = %s\n", prev->next->data->suit);

}
//-------------------------------------------------------------------
void printList(struct Node *head)
{
	//finds list length
	int listlen = length(head);
	int i;
	for (i=0; i<listlen; i++)
	{
		//prints suit and data value for every card
		printf("(%s,%s)", head->next->data->suit, head->next->data->values);
		//moves along the cards
		head = head->next;
	}
	printf("\n");	
}

//number of elements in the list
int length(struct Node *head)
{	
	//printf("ENTERED LENGTH FUNCTION\n");
	int count=0;
	//checks if there is card after current card
	while (head->next != NULL)
	{
		//counts
		count++;
		//moves along the cards
		head = head->next;
	}
	
	return count;
}