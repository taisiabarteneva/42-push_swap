/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 06:17:30 by wurrigon          #+#    #+#             */
/*   Updated: 2021/12/31 06:09:59 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				i;
	int				i_tmp;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	int				max_one;
	int				max_two;
	int				max_three;
}	t_info;

# define DEFAULT_ERR	1
# define MEM_ERR		2

/* list functions */
void	fill_list(t_list **head, int ac, char **av);
void	list_add_back(t_list **head, int data);
void	list_add_front(t_list **head, int data);
int		count_nodes(t_list *head);
void	free_list(t_list **head);

/* error handling */
void	fatal_error(int err_num);

/* parse */
int		ft_atoi(const char *str);
void	check_duplicate_values(t_list *head);
int		check_args(int ac, char **av);

/* commands */
void	swap_shell(t_list **stack_a, t_list **stack_b, char name);
void	push_shell(t_list **stack_a, t_list **stack_b, char dest);
void	rotate_shell(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_shell(t_list **stack_a, t_list **stack_b);

/* algorythm prerequisites */
void	index_elems(t_list **head);
void	tmp_index_elems(t_list **head, int group_count);
int		count_step(t_list *stack);
int		check_group(t_list *head, int step);
int		tmp_check_group(t_list *head, int step);

/* sort */
void	sort_three(t_list **head);
void	sort_three_if_full(t_list **stack_a, t_list **stack_b, char stack_name);
void	sort_small_list(t_list **a, t_list **b);
void	sort_middle_list(t_list **stack_a, t_list **stack_b);
void	sort_big_list(t_list **stack_a, t_list **stack_b);

void	push_to_b(t_list **head_a, t_list **head_b, int *groups_count);
void	merge_sort(t_list **stack_a, t_list **stack_b, int group_count,
			char stack_name);
void	merge_sort_a(t_list **stack_a, t_list **stack_b, int group_count);
void	merge_sort_base_case_b(t_list **stack_a, t_list **stack_b,
			int group_count);
void	merge_sort_base_case_a(t_list **stack_a, t_list **stack_b,
			int group_count);
int		merge_sort_divide_b(t_list **stack_a, t_list **stack_b, int group_count,
			int *pushed);

int		merge_sort_divide_a(t_list **stack_a, t_list **stack_b, int group_count,
			int *pushed);

/* side functions for sorting */
int		find_max(t_list *head);
int		find_min(t_list **head);
int		tmp_find_max(t_list *head, int count);
int		tmp_find_min(t_list **head, int group_count);

int		list_is_sorted(t_list *a, t_list *b);
void	init_info_struct(t_info **group);
int		calculate_elems_to_push(t_info *group);
int		locate_max_elems_stack_b(t_list *stack_b, int flag, int max);
int		locate_elem_stack_b(t_list **stack_b, int max_index);

#endif