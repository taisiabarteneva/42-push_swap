/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sexysushi <sexysushi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 07:48:34 by sexysushi         #+#    #+#             */
/*   Updated: 2021/12/30 07:53:41 by sexysushi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa, pb */
static int	push(t_list **head_dst, t_list **head_src)
{
	t_list	*second;

	if (!(*head_src))
		return (1);
	second = (*head_src)->next;
	(*head_src)->next = *head_dst;
	*head_dst = *head_src;
	*head_src = second;
	return (0);
}

void	push_shell(t_list **stack_a, t_list **stack_b, char dest)
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
