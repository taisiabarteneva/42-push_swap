/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_for_all_cases.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:46:06 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 02:45:27 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_group(t_list *head, int step)
{
	while (head)
	{
		if (head->i < step)
			return (1);
		head = head->next;
	}
	return (0);
}

static int	push_to_b_extra(t_list **head_a, t_list **head_b, int step)
{
	int	pushed;
	int	max_i;

	pushed = 0;
	max_i = find_max(*head_a);
	while (count_nodes(*head_a) > 3 && check_group(*head_a, step) == 1)
	{
		if ((*head_a)->i < step && (*head_a)->i < (max_i - 2))
		{
			push_shell(head_a, head_b, 'b');
			pushed++;
		}
		else
			rotate_shell(head_a, NULL);
	}
	return (pushed);
}

/* Перекинуть по группам элементы из стека А в В,
пока в А не останется трех элементов */
void	push_to_b(t_list **head_a, t_list **head_b, int *groups_count)
{
	int	step;
	int	const_step;
	int	pushed;
	int	i;

	i = 0;
	const_step = count_step(*head_a);
	step = const_step;
	while (count_nodes(*head_a) > 3)
	{
		pushed = push_to_b_extra(head_a, head_b, step);
		if (groups_count)
			groups_count[i] = pushed;
		step += const_step;
		i++;
	}
	sort_three(head_a);
}
