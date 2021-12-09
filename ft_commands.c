#include "push_swap.h"

// sa, sb, ss
void ft_swap(t_list **_head)
{
    t_list      *second_item;
    t_list      *head;

    head = *_head;
    second_item = head->next;
    if (!second_item)
        return ;
    head->next = second_item->next;
    second_item->next = head;
    head = second_item;
    *_head = head;
}

// pa, pb
void ft_push(t_list **head_dst, t_list **head_src)
{
    t_list  *src;
    t_list  *dst;
    t_list  *second;

    src = *head_src;
    if (!(*head_src))
        return ;
    dst = *head_dst;
    second = (*head_src)->next;
    src->next = dst;
    dst = src;
    src = second;
    *head_src = src;
    *head_dst = dst;
}

// ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
void ft_rotate(t_list **head)
{
    t_list  *current;
    t_list  *last;
    int     i_last;
    int     first_data;

    current = *head;
    first_data = current->data;
    while (last->next != NULL)
        last = last->next;
    i_last = last->i;
    while (current->next != NULL)
    {
        if (current->i == 0)
        {
            current->data = last->data;
        }
        else if (current->i == i_last)
        {
            current->data = first_data;
        }
        else
        {
            current->data = current->next->data;
        }
        current = current->next;
    }
}