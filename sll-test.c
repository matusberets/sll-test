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
bool search_sll(node *head, int *number);
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
    int new_nodes_amount;
    printf("How many new nodes do you want to enter ? ");
    scanf("%i", &new_nodes_amount);

    for (int i = 0; i < new_nodes_amount; i++)
    {
        int new_node;
        printf("Enter a new node no.%i : ", i + 1);
        scanf("%i", &new_node);
        insert_sll(list, new_node);
    }

    // DECLARATION set temp node to point where list node points;
    // CONDITION: continue until node temp doesnt hit NULL pointer;
    // CALCULATION / INCREMENTION: which each iteration move pointer temp to a next node member pointer next;
    for (node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("%i\n", temp->number);
    }

    //Search a number in SLL
    int *searched_number = malloc(sizeof(int));
    if (searched_number == NULL)
    {
        return 1;

    }
    printf("Enter the number you are searching for in a SLL: ");
    scanf("%i", searched_number);

    printf("Answer is [0 = True, 1 = False]: %i\n", search_sll(list, searched_number));

    //free used malloced dynamic memory
    while (list != NULL)
    {
        node *temp = list->next;
        free(list);
        list = temp;
    }
}

//Search function definition
bool search_sll(node *head, int *searched_number)
{
    // boolean variable declaration
    bool result_status;

    node *travers = NULL;

    for (travers = list; travers->number != *searched_number; travers = travers->next)
    {
        if (travers->number == *searched_number)
        {
            result_status = true;
        }

        else
        {
            result_status = false;
        }

        if (travers->next == NULL)
        {
            result_status = false;

            return 1;
        }

    }

    return result_status;
}

//Insert function definition SLL
node insert_sll(node *head, int number)
{
    node *trav = NULL;
    trav = malloc(sizeof(node));

    trav->number = number;
    trav->next = list;
    list = trav;

    return *list;
}