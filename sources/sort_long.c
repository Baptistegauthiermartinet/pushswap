/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:45:01 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/23 14:48:09 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	shorter_path(t_list **stack, int idx)
{
	int		i;
	int		j;
	t_list	*head;

	i = 0;
	head = (*stack);
	while ((*stack)->index != idx)
	{
		(*stack) = (*stack)->next;
		i++;
	}
	j = 0;
	(*stack) = head;
	while ((*stack)->index != idx)
	{
		(*stack) = (*stack)->previous;
		j++;
	}
	(*stack) = head;
	if (i <= j)
		return (i);
	else
		return (-j);
}

static void	split_in_half(t_list **stack_a, t_list **stack_b)
{
	int	len_temp;
	int	median;
	int	size;

	size = ft_lstsize_push_swap(*stack_a);
	while (size > 5 && is_sorted(*stack_a) == 0)
	{
		median = get_median(get_idx_max(stack_a), get_idx_min(stack_a));
		len_temp = size / 2;
		while (len_temp > 0)
		{
			if ((*stack_a)-> index < median)
			{
				push_stack(stack_b, stack_a);
				if (check_neighbours(stack_b) == 1)
					rotate_stack(stack_b);
				else if (check_two_top(stack_b) == 1)
					swap_stack(stack_b, 1);
				len_temp--;
			}
			else
				rotate_stack(stack_a);
		}
		size = ft_lstsize_push_swap(*stack_a);
	}
}

void	sort_long(t_list **stack_a, t_list **stack_b)
{
	int	cpt;

	split_in_half(stack_a, stack_b);
	if (is_sorted(*stack_a) == 0)
		sort(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		cpt = shorter_path(stack_b, (*stack_a)->index -1);
		while (cpt != 0)
		{
			if (cpt > 0)
			{
				rotate_stack(stack_b);
				cpt--;
			}
			if (cpt < 0)
			{
				rev_rotate_stack(stack_b);
				cpt++;
			}
		}
		push_stack(stack_a, stack_b);
	}
}
