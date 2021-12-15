#include "push_swap.h"

/* sa, sb, ss */
void swap(t_list **_head)
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

void swap_shell(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b)
    {
        swap(stack_a);
        write(1, "sa\n", 3);
    }
    else if (!stack_a)
    {
        swap(stack_b);
        write(1, "sb\n", 3);
    }
    else
    {
        swap(stack_a);
	    swap(stack_b);
	    write(1, "ss\n", 3);
    }
}

/* pa, pb */
void push(t_list **head_dst, t_list **head_src)
{
    t_list  *src;
    t_list  *dst;
    t_list  *second;

    if (!(*head_dst))
    {
        dst = malloc(sizeof(t_list));
    }
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

void push_shell(t_list **stack_a, t_list **stack_b, int flag)
{
    if (flag == 0)
    {
        push(stack_a, stack_b);
        write(1, "pa\n", 3);
    }
    else if (flag == 1)
    {
        push(stack_a, stack_b);
        write(1, "pb\n", 3);
    }
}


/* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one. */
void rotate(t_list **head)
{
    t_list  *current;
    t_list  *last;

    if (!(*head) || (*head)->next == NULL)
        return ;
    current = *head;
    last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = current;
    *head = current->next;
    current->next = NULL;
}

void rotate_shell(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b)
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
    }
    else if (!stack_a)
    {
        rotate(stack_b);
        write(1, "rb\n", 3);
    }
    else
    {
        rotate(stack_a);
        rotate(stack_b);
        write(1, "rr\n", 3);
    }
}

/* rra : shift down all elements of stack a by 1. The last element becomes the first one. */
void reverse_rotate(t_list **head)
{
    t_list *last;
    t_list *prelast;

    if (!(*head) || (*head)->next == NULL)
        return ;
    last = *head;
    prelast = *head;
    while (prelast->next->next != NULL)
    {
        prelast = prelast->next;
        last = last->next;
    }
    last = last->next;
    last->next = *head;
    prelast->next = NULL;
    *head = last;
}

void reverse_rotate_shell(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b)
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
    }
    else if (!stack_a)
    {
        reverse_rotate(stack_b);
        write(1, "rrb\n", 4);
    }
    else
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        write(1, "rrr\n", 4);
    }
}