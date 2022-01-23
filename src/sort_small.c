/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:45:16 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 06:05:21 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_extra(t_list **head)
{
	if ((*head)->next && (*head)->next->data < (*head)->data)
		swap_shell(head, NULL, 'a');
}

void	sort_three(t_list **head)
{
	int	max;
	int	count;

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

/* second push will be ignored, if there's one element */
void	sort_small_list(t_list **a, t_list **b)
{
	int	count;

	count = count_nodes(*a);
	if (count == 2 || count == 3)
		sort_three(a);
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
			swap_shell(a, NULL, 'a');
	}
}
