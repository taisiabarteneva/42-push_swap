/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:46:21 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/30 05:08:16 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa, sb, ss */
static int	swap(t_list **_head)
{
	t_list	*second_item;
	t_list	*head;

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

static void	swap_shell_extra_a(t_list **stack_a, t_list **stack_b)
{
	if (stack_b && *stack_b && (*stack_b)->next
		&& (*stack_b)->i < (*stack_b)->next->i)
	{
		if (swap(stack_a) == 0 && (swap(stack_b) == 0))
			write(1, "ss\n", 3);
	}
	else
	{
		if (swap(stack_a) == 0)
			write(1, "sa\n", 3);
	}
}

static void	swap_shell_extra_b(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next
		&& (*stack_a)->i > (*stack_a)->next->i)
	{
		if (swap(stack_a) == 0 && (swap(stack_b) == 0))
			write(1, "ss\n", 3);
	}
	else
	{
		if (swap(stack_b) == 0)
			write(1, "sb\n", 3);
	}
}

void	swap_shell(t_list **stack_a, t_list **stack_b, char name)
{
	if (name == 'a')
		swap_shell_extra_a(stack_a, stack_b);
	else if (name == 'b')
		swap_shell_extra_b(stack_a, stack_b);
}
