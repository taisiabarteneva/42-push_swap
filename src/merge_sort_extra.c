/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sexysushi <sexysushi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:18:32 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/30 07:54:51 by sexysushi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_if_full_extra_a(t_list **stack_a, t_list **stack_b,
			char stack_name, int pos)
{
	if (pos > 2)
		swap_shell(stack_a, stack_b, stack_name);
	if (pos > 1)
	{
		rotate_shell(stack_a, NULL);
		swap_shell(stack_a, stack_b, stack_name);
		reverse_rotate_shell(stack_a, NULL);
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_shell(stack_a, stack_b, stack_name);
}

static void	sort_three_if_full_extra_b(t_list **stack_a, t_list **stack_b,
			char stack_name, int pos)
{
	if (pos > 2)
		swap_shell(stack_a, stack_b, stack_name);
	if (pos > 1)
	{
		rotate_shell(NULL, stack_b);
		swap_shell(stack_a, stack_b, stack_name);
		reverse_rotate_shell(NULL, stack_b);
	}
	if ((*stack_b)->data < (*stack_b)->next->data)
		swap_shell(stack_a, stack_b, stack_name);
}

void	sort_three_if_full(t_list **stack_a, t_list **stack_b, char stack_name)
{
	int	max;
	int	min;

	if (stack_name == 'a')
	{
		max = tmp_find_max(*stack_a, 3);
		if ((*stack_a)->i_tmp == max)
			sort_three_if_full_extra_a(stack_a, stack_b, stack_name, 3);
		else if ((*stack_a)->next->i_tmp == max)
			sort_three_if_full_extra_a(stack_a, stack_b, stack_name, 2);
		else
			sort_three_if_full_extra_a(stack_a, stack_b, stack_name, 1);
	}
	else
	{
		min = tmp_find_min(stack_b, 3);
		if ((*stack_b)->data == min)
			sort_three_if_full_extra_b(stack_a, stack_b, stack_name, 3);
		else if ((*stack_b)->next->data == min)
			sort_three_if_full_extra_b(stack_a, stack_b, stack_name, 2);
		else
			sort_three_if_full_extra_b(stack_a, stack_b, stack_name, 1);
	}
}
