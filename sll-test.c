//15.05.2020 program to test SLL data structure - details in -> README.MD
//17.05.2020 Search function implemented as following my notes from David's Week5 lecture
//17.05.2020 Insert a new node function implemented, bug to be fixed, node is inserted, but its not found when search function used.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//node structure
typedef struct node
{
    int number;
    struct node *next;
}
node;

//Global variable, creating an empty pointer list / type node / AKA head of SLL, currently empty NULL pointer
node *list = NULL;

//traversal global variable point for search function
node *traversal = NULL;

//function declaration
bool search_sll(node *head, int number);
node insert_sll(node *head, int number);

int main(void)
{
    //assigning a dynamic memory to a new node n + error check
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    // assiging a value to a node member number
    n->number = 2;
    // assigning a new pointer to a node member next = NULL
    n->next = NULL;

    //now node member pointer list points towards node member n, now they are linked.
    list = n;

    //link a another number to existing linked list data structure
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 4;
    n->next = NULL;

    list->next = n;

    //add another number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 6;
    n->next = NULL;

    //connect new number to a linked list
    list->next->next = n;

    //add another number
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 10;
    n->next = NULL;
    list->next->next->next = n;

    //insert a new node
    int y;
    printf("Enter a new node: ");
    scanf("%i", &y);
    insert_sll(list, y);

    // DECLARATION set temp node to point where list node points;
    // CONDITION: continue until node temp doesnt hit NULL pointer;
    // CALCULATION / INCREMENTION: which each iteration move pointer temp to a next node member pointer next;
    for (node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("%i\n", temp->number);
    }

    //Search a number in SLL
    int x;
    printf("Enter the number you are searching for in a SLL: ");
    scanf("%i", &x);

    printf("Answer is [0 = True, 1 = False]: %i\n", search_sll(list, x));

    //free used malloced dynamic memory
    while(list != NULL)
    {
        node *temp = list->next;
        free(list);
        list = temp;
    }
}

//Search function definition
bool search_sll(node *head, int number)
{
    //asigning traversal point to the head of the sll; if traversal -> list -> next == number we search Hit !; Incerement a next next
    for (traversal = list; traversal->number == number; traversal = traversal->next)
    {
        //if traversal -> list -> next == NULL or end of the SLL, return false
        if (traversal->next == NULL)
        {
            return false;
        }
        return true;
    }
    return 0;
}

//Insert function definition SLL
node insert_sll(node *head, int number)
{
    node *trav = malloc(sizeof(node));
/*
    if (n == NULL)
    {
        return 1;
    }
*/
    trav->number = number;
    trav->next = list;
    list = trav;

    return *list;
}