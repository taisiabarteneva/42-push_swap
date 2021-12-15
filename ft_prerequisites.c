#include "push_swap.h"

int find_min(t_list **head)
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

void side_index_elems(t_list **head, int min, int count)
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

void index_elems(t_list **head)
{
    int     min;
    int     count;

    min = find_min(head);
    count = count_nodes(*head);
    side_index_elems(head, min, count);
}
