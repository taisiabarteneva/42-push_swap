#include "push_swap.h"

/* sa, sb, ss */
static int swap(t_list **_head)
{
    t_list      *second_item;
    t_list      *head;

    if (!(*_head) || !(*_head)->next)
        return (1);
    head = *_head;
    second_item = head->next;
    head->next = second_item->next;
    second_item->next = head;
    head = second_item;
    *_head = head;
    return (0);
}

void swap_shell(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b)
    {
        if (swap(stack_a) == 0)
            write(1, "sa\n", 3);
    }
    else if (!stack_a)
    {
       if (swap(stack_b) == 0)
            write(1, "sb\n", 3);
    }
    else
    {
        if (swap(stack_a) == 0 && (swap(stack_b) == 0))
	        write(1, "ss\n", 3);
    }
}

/* pa, pb */
static int push(t_list **head_dst, t_list **head_src)
{
    t_list *second;

    if (!(*head_src))
        return (1);
    second = (*head_src)->next;
    (*head_src)->next = *head_dst;
    *head_dst = *head_src;
    *head_src = second;
    return (0);
}

void push_shell(t_list **stack_a, t_list **stack_b, char dest)
{
    if (dest == 'a')
    {
        if (push(stack_a, stack_b) == 0)
            write(1, "pa\n", 3);
    }
    else if (dest == 'b')
    {
        if (push(stack_b, stack_a) == 0)
            write(1, "pb\n", 3);
    }
}