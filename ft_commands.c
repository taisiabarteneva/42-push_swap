#include "push_swap.h"

// sa - swap a - swap first two elements of the stack a
// 1 4 5 6 8 9 20
void ft_swap(t_list **_head)
{
    t_list      *second_item;
    t_list      *head;

    head = *_head;

    second_item = head->next;
    head->next = second_item->next;
    second_item->next = head;
    head = second_item;
    *_head = head;
}

// sb - swap b - swap first two elements of the stack a