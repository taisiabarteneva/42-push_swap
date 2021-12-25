#include "push_swap.h"

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
