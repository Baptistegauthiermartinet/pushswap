/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:45:01 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/09 18:14:25 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (check_neighbours(stack_a) == 3)
				swap_stack(stack_a, 1);
			else
				rotate_stack(stack_a);
		}
		size = ft_lstsize_push_swap(*stack_a);
	}
}

void	sort_long(t_list **stack_a, t_list **stack_b)
{
	split_in_half(stack_a, stack_b);
	sort(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		push_stack(stack_a, stack_b);
		if (check_neighbours(stack_a) == 3 && check_neighbours(stack_b) == 4)
			swap_both(stack_a, stack_b);
		else if (check_neighbours(stack_a) == 3)
			swap_stack(stack_a, 1);
		else if (check_two_top(stack_b) == 1 && (*stack_b)->index < (*stack_a)->index)
			swap_stack(stack_b, 1);
	}
}
