#include "push_swap.h"

void fill_list(t_list **head, int ac, char **av)
{
    int     val;
    int     i;

    *head = (t_list *)malloc(sizeof(t_list));
    if (!head)
        fatal_error(MEM_ERR);
    val = ft_atoi(av[FIRST_ELEM]);
    (*head)->data = val;
    (*head)->i = 0;
    (*head)->next = NULL;
    i = LIST_START;
    while (i < ac)
    {
        val = ft_atoi(av[i]);
        list_add_back(*head, val);
        i++;
    }
    check_duplicate_values(*head); 
    index_elems(head);
}

void list_add_back(t_list *head, int data)
{
    t_list  *current;

    current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = (t_list *)malloc(sizeof(t_list));
    if (current->next == NULL)
        fatal_error(MEM_ERR);
    current->next->data = data;
    current->next->i = 0;
    current->next->next = NULL;
}

int count_nodes(t_list *head)
{
    int     count;

    count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

void free_list(t_list **head)
{
    t_list *tmp;

    while (*head)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

// Iterate over a List
void print_list(t_list *a, t_list *b)
{
    for (; a || b ; )
    {
        if (a)
            dprintf(2, "%d:%d", a->data, a->i);
        else
            dprintf(2, "-");
        dprintf(2, "      ");
        if (b)
            dprintf(2, "%d:%d\n", b->data, b->i);
        else
            dprintf(2, "-\n");
        if (a)
            a = a->next;
        if (b)
            b = b->next;
        
    }
}