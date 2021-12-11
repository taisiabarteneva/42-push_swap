#include "push_swap.h"

// Add to the back
void ft_list_add_back(t_list *head, int data)
{
    t_list  *current;

    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = (t_list *)malloc(sizeof(t_list));
    if (current->next == NULL)
        ft_fatal_error(MEM_ERR);
    current->next->data = data;
    current->next->i = 0;
    current->next->next = NULL;
}

// Count of nodes
int ft_count_nodes(t_list **head)
{
    t_list  *current;
    int     count;

    current = *head;
    count = 0;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
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
        // printf("[%d] [%d]\n", current->data, current->i);
        printf("[%d]\n", current->data);
        current = current->next;
        i++;
    }
}