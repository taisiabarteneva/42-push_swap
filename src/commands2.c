#include "push_swap.h"

/* ra, rb, rr */
static int rotate(t_list **head)
{
    t_list  *tmp;
    t_list  *last;

    if (!(*head) || !((*head)->next))
        return (1);
    tmp = *head;
    last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = *head;
    *head = (*head)->next;
    tmp->next = NULL;
    return (0);
}

void rotate_shell(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b)
    {
        if (rotate(stack_a) == 0)
            write(1, "ra\n", 3);
    }
    else if (!stack_a)
    {
        if (rotate(stack_b) == 0)
            write(1, "rb\n", 3);
    }
    else
    {
        if (rotate(stack_a) == 0 && rotate(stack_b) == 0)
            write(1, "rr\n", 3);
    }
}

/* rra, rrb, rrr */
static int reverse_rotate(t_list **head)
{
    t_list *prelast;
    t_list *last;

    if (!(*head) || !(*head)->next)
        return (1);
    prelast = *head;
    while (prelast->next->next)
    {
        prelast = prelast->next;
    }
    last = prelast->next;
    last->next = *head;
    prelast->next = NULL;
    *head = last;
    return (0);
}

void reverse_rotate_shell(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b)
    {
        if (reverse_rotate(stack_a) == 0)
            write(1, "rra\n", 4);
    }
    else if (!stack_a)
    {
        if (reverse_rotate(stack_b) == 0)
            write(1, "rrb\n", 4);
    }
    else
    {
        if (reverse_rotate(stack_a) == 0 && reverse_rotate(stack_b) == 0)
            write(1, "rrr\n", 4);
    }
}