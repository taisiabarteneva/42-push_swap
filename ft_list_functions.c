#include "push_swap.h"

// Add to the back
int ft_list_add_back(t_list *head, int data)
{
    t_list  *current;

    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = (t_list *)malloc(sizeof(t_list));
    if (current->next == NULL)
        return (1);
    current->next->data = data;
    current->next->next = NULL;
    return (0);
}

// Iterate over a List
void ft_print_list(t_list *node)
{
    t_list  *current;
    int     i;

    current = node;
    i = 0;
    while (current != NULL)
    {
        printf("[%d] ", current->data);
        current = current->next;
        i++;
    }
    printf("\n");
}