// Jonathan Prawiromaruto
// Zendesk Internship Coding Challenge 2022
// 11/29/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INVALID -1
#define EXIT 0
#define CREATETICKET 1
#define SEARCHTICKET 2
#define VIEWTICKETS 3
#define PAGE 25

// Every node has a piece of data,
// and a pointer to the next node.
typedef struct Node
{
	int data;
	char *subject;
	char *desc;
	char *status;
	struct Node *next;

} Node;

void clearScreen();
int displayMenu();
void createTicket(Node *list, int n);

// Takes in a pointer to the current front,
// Returns a pointer to the new front
Node *insertFront(Node *front, int value, char *subject, char *desc)
{
	// Dynamically allocate space for a single node
	Node *newNode = malloc(sizeof(Node));

	// Put the new value in the node.
	newNode->data = value;
	newNode->subject = subject;
	newNode->desc = desc;
	newNode->status = "<Created>";

	// Set the new node to point to the current front
	newNode->next = front;

	// The new node will become the new front, so return it.
	return newNode;
}

// Print the contents of a linked list iteratively
void printList(Node *front, char *subject)
{
	if (front == NULL)
	{
		return;
	}

	if (strcmp(front->subject, subject) != 0)
	{
		printList(front->next, subject);
	}

	else if (strcmp(front->subject, subject) == 0)
	{
		printf("\nTicket found!\n");
		printf("\nTicket #%d", front->data);
		printf("\nSubject: '%s'", front->subject);
		printf("\nDescription: %s", front->desc);
		printf("\nStatus: %s \n", front->status);
		return;
	}
	return;
}

// Prints the contents of the Linked List recursively
void printListRecursive(Node *front)
{
	// BASE CASE: We pass in a NULL pointer
	if (front == NULL)
	{
		// We've reached the end, stop recursing.
		printf("\n");
		return;
	}

	else if(front->data == PAGE)
	{
		printf("\npage #2\n");
	}
	else if(front->data == (PAGE*2))
	{
		printf("\npage #3\n");
	}
	else if(front->data == (PAGE*3))
	{
		printf("\npage #4\n");
	}

	printf("\nTicket #%d", front->data);
	printf("\nSubject: '%s'", front->subject);
	printf("\nDescription: %s", front->desc);
	printf("\nStatus: %s \n", front->status);

	// Pass the remaining list to the recursive function
	// Its just the current list minus the front.
	printListRecursive(front->next);
}

// We can't do this going "forwards,"
// we'll be accessing the "next" member of a struct that's already been freed.
void freeList(Node *front)
{
	if (front == NULL)
	{
		return;
	}

	// Free everything else,
	// than free the current node.
	freeList(front->next);
	free(front);
}

int main(void)
{
	// Create an empty linked list.
	Node *list = NULL;
	int choice = INVALID, n = 0;

	list = insertFront(list, n += 1, "taco", "love of my life, I am really hungry.");
	list = insertFront(list, n += 1, "cats", "lost cats alert! I need my cat back!");
	list = insertFront(list, n += 1, "error", "can't print my stuff here man...");
	list = insertFront(list, n += 1, "lol", "just a meme page.");
	list = insertFront(list, n += 1, "dogs", "Best friend for the world.");
	list = insertFront(list, n += 1, "crypto", "maybe making you rich?");
	list = insertFront(list, n += 1, "so muc food", "super full bro");
	list = insertFront(list, n += 1, "Zendesk", "awesome place to work in!");
	list = insertFront(list, n += 1, "tacos", "love of my life, I am really hungry.");
	list = insertFront(list, n += 1, "cat", "singular");
	list = insertFront(list, n += 1, "errors", "more than one error");
	list = insertFront(list, n += 1, "lols", "just pages.");
	list = insertFront(list, n += 1, "dog", "singular pup");
	list = insertFront(list, n += 1, "cryptos", "you decide");
	list = insertFront(list, n += 1, "so much food", "typo corrected!");
	list = insertFront(list, n += 1, "coding challenge", "awesome learning opportunity.");
	list = insertFront(list, n += 1, "fried rice", "faves food");
	list = insertFront(list, n += 1, "turtle", "gotta safe em!");
	list = insertFront(list, n += 1, "vegan", "healthy choice");
	list = insertFront(list, n += 1, "eggs", "white and yellow");
	list = insertFront(list, n += 1, "smoothie machine", "best investment!");
	list = insertFront(list, n += 1, "invesment", "not always money man");
	list = insertFront(list, n += 1, "rent", "so expensive");
	list = insertFront(list, n += 1, "friends", "I need to make new ones!");
	list = insertFront(list, n += 1, "work", "do what you love");
	list = insertFront(list, n += 1, "boba", "the closest thing to heaven");
	list = insertFront(list, n += 1, "debugging", "gotta pey attention to the details");
	list = insertFront(list, n += 1, "learning", "never stops!");
	list = insertFront(list, n += 1, "don't worry", "you got this");
	list = insertFront(list, n += 1, "codes", "sometimes unreadable lines");
	list = insertFront(list, n += 1, "why?", "why not?");
	list = insertFront(list, n += 1, "interview", "learn learn learn.");

	while (choice != EXIT)
	{
		choice = displayMenu();
		char *subject = malloc(sizeof(char) * 22);
		char *title = malloc(sizeof(char) * 22);
		char *desc = malloc(sizeof(char) * 102);

		switch (choice)
		{
		case CREATETICKET:
			printf("Ticket subject <20 char max>: \n");
			scanf("%s", subject);
			if (strlen(subject) > 20)
			{
				printf("Error, too many characters\n");
				break;
			}

			printf("In short, please describe the problem here <100 char max:>: \n");
			scanf("%s", desc);
			if (strlen(subject) > 100)
			{
				printf("Error, too many characters\n");
				break;
			}

			list = insertFront(list, n += 1, subject, desc);
			break;
		case SEARCHTICKET:
			printf("Search ticket title here: \n");
			scanf("%s", title);
			printList(list, title);
			break;
		case VIEWTICKETS:
			printListRecursive(list);
			break;
		case EXIT:
			system("cls");
			printf("Thank you for using our ticket viewer service. see you again next time.\n");
			exit(EXIT);
			break;
		}
	}
	return 0;
}

int displayMenu()
{
	int choice = INVALID;

	while (choice == INVALID)
	{
		printf("\n\t< Ticket Viewer Menu >\n\n");
		printf("Enter the number of your selection:\n");
		printf("1. Create ticket\n2. Search ticket\n3. View all tickets\n0. Exit\n");

		scanf("%d", &choice);

		if (choice < 0 || choice > 3)
		{
			printf("\nThere is an error to the selection.\n");
			choice = INVALID;
		}
	}
	return choice;
}

void clearScreen()
{
	// prompt user to click enter
	char enter;
	printf("\n<Hit ENTER to continue>\n\n");
	// scanning enter key
	scanf("%c", &enter);

	// windows
	system("cls");

	// Linux or MAC
	// system("clear");
}

void createTicket(Node *list, int ticketNum)
{
	char *subject = malloc(sizeof(char) * 22);
	char *desc = malloc(sizeof(char) * 102);

	printf("Ticket subject <20 char max>: \n");
	scanf("%s", subject);
	if (strlen(subject) > 20)
	{
		printf("Error, too many characters");
		return;
	}

	printf("In short, please describe the problem here <100 char max:>: \n");
	scanf("%s", desc);
	if (strlen(subject) > 100)
	{
		printf("Error, too many characters");
		return;
	}

	list = insertFront(list, ticketNum, subject, desc);
	return;
}
