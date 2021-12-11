#include "push_swap.h"

int ft_find_min(t_list **head)
{
    t_list  *current;
    int     min_val;

    current = *head;
    min_val = INT_MAX;
    while (current != NULL)
    {
        if (current->data <= min_val)
        {
            min_val = current->data;
        }
        current = current->next;
    }
    return (min_val);
}

void ft_side_index_elems(t_list **head, int min, int count)
{
    int i;
    int tmp;
    t_list *current;
    t_list *holder;

    i = 1;
    while (i < count)
    {
        current = *head;
        tmp = INT_MAX;
        while (current)
        {
            if (current->data > min && current->data < tmp)
            {
                tmp = current->data;
                holder = current;
            }
            current = current->next;
        }
        holder->i = i;
        min = holder->data;
        i++;
    }
}

void ft_index_elems(t_list **head)
{
    int     min;
    int     count;

    min = ft_find_min(head);
    count = ft_count_nodes(head);
    ft_side_index_elems(head, min, count);
}
