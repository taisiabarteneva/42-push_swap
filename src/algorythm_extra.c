#include "push_swap.h"

int find_min(t_list **head)
{
    int     min_val;
    t_list  *current;

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

int find_max(t_list *head)
{
	int 	max_val;
	t_list	*found;

	max_val = INT_MIN;
	while (head != NULL)
	{
		if (head->data >= max_val)
		{
			max_val = head->data;
			found = head;
		}
		head = head->next;
	}
	return (found->i);
}