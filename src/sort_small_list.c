#include "push_swap.h"

static void sort_three_extra(t_list **head)
{
    if ((*head)->next && (*head)->next->data < (*head)->data)
            swap_shell(head, NULL);
}

void sort_three(t_list **head)
{
    int max;
    int count;

    count = count_nodes(*head);
    if (count < 3)
        sort_three_extra(head);
    else
    {
        max = find_max(*head);
        if ((*head)->i == max)
        {
            rotate_shell(head, NULL);
        }
        else if ((*head)->next->i == max)
        {
            reverse_rotate_shell(head, NULL);
        } 
        sort_three_extra(head);
    }
}

/* Если поступит четыре элемента, второй вызов push_shell будет проигнорирован */
void sort_small_list(t_list **a, t_list **b)
{
    int count;

    count = count_nodes(*a);
    if (count == 2 || count == 3)
    {
        sort_three(a);
    }
    else
    {
        while (count_nodes(*a) > 3)
        {
            if ((*a)->i < 2)
                push_shell(a, b, 'b');
            else
                rotate_shell(a, NULL); 
        }
        sort_three(a);
        push_shell(a, b, 'a');
        push_shell(a, b, 'a');
        if ((*a)->data > (*a)->next->data)
            swap_shell(a, NULL);
    }
}