/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 02:48:52 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 06:06:17 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_step(t_list *stack)
{
	int	step;
	int	group_count;
	int	num_count;

	num_count = count_nodes(stack);
	step = 0;
	if (num_count <= 50)
		group_count = 3;
	else if (num_count > 50 && num_count <= 100)
		group_count = 5;
	else
		group_count = 12;
	step = num_count / group_count;
	return (step);
}

int	locate_elem_stack_b(t_list **stack_b, int max_index)
{
	int		medium;
	int		nodes_count;
	int		flag;
	int		i;
	t_list	*current;

	nodes_count = count_nodes(*stack_b);
	medium = nodes_count / 2;
	flag = 0;
	i = 0;
	current = *stack_b;
	while (current)
	{
		if (current->i == max_index)
		{
			if (i < medium)
				flag = 0;
			else
				flag = 1;
			break ;
		}
		current = current->next;
		i++;
	}
	return (flag);
}

int	calculate_elems_to_push(t_info *group)
{
	int	total;

	if (!group->max_one && group->max_two)
		group->max_two = 0;
	if (!group->max_two && group->max_three)
		group->max_three = 0;
	total = group->max_two + group->max_two + group->max_three;
	return (total);
}
