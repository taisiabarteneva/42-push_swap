#include "push_swap.h"

// Add to the back
void ft_list_add_back(t_list *head, int data, int i)
{
    t_list  *current;
    t_list  *new;

    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = (t_list *)malloc(sizeof(t_list));
    if (current->next == NULL)
        ft_fatal_error(MEM_ERR);
    current->next->data = data;
    current->next->i = i;
    current->next->next = NULL;
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