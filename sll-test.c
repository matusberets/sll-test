//15.05.2020 program to test SLL data structure - details in -> README.MD

#include <stdio.h>
#include <stdlib.h>

//node structure
typedef struct node
{
    int value;
    struct node *next;
}
node;

int main(void)
{
    // creating a head of SLL, curently empty NULL pointer
    node *list = NULL
    list = malloc(sizeof(node));
    if (list = NULL)
    {
        return 1;
    }


}