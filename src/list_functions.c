/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 04:45:41 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 05:54:40 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_list(t_list **head, int ac, char **av)
{
	int	val;
	int	i;

	i = 1;
	while (i < ac)
	{
		val = ft_atoi(av[i]);
		list_add_back(head, val);
		i++;
	}
	check_duplicate_values(*head);
	index_elems(head);
}

void	list_add_front(t_list **head, int data)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		fatal_error(MEM_ERR);
	tmp->data = data;
	tmp->i = 0;
	tmp->i_tmp = 0;
	tmp->next = *head;
	*head = tmp;
}

void	list_add_back(t_list **head, int data)
{
	t_list	*tmp;
	t_list	*current;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		fatal_error(MEM_ERR);
	if (!(*head))
		*head = tmp;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
	}
	tmp->data = data;
	tmp->i = 0;
	tmp->i_tmp = 0;
	tmp->next = NULL;
}

int	count_nodes(t_list *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	free_list(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
