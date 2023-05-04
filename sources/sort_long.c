/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:45:01 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/04 21:46:08 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_in_half(t_list **stack_a, t_list **stack_b, int len)
{
	int	len_temp;

	len_temp = len/2;
	while (len_temp > 0)
	{
		if ((*stack_a)-> index <= len/2)
		{
			push_stack(stack_b, stack_a);
			len_temp--;
		}
		else
			rotate_stack(stack_a);
		
	}
}



void	sort_long(t_list **stack_a, t_list **stack_b, int len)
{
	int	bot_a;
	int	bot_b;
	int	sec_a;
	int	sec_b;
	int i = len/2;
	split_in_half(stack_a, stack_b, len);
	while (i > 0)
	{
		print_stacks(*stack_a, *stack_b);
		bot_a = (*stack_a)->previous->index;
		bot_b = (*stack_b)->previous->index;
		sec_a = (*stack_a)->next->index;
		sec_b = (*stack_b)->next->index;
		while ((*stack_a)->index > bot_a && (*stack_b)->index < bot_b)
			rotate_both(stack_a, stack_b);
		while ((*stack_a)->index > sec_a && (*stack_b)->index < sec_b)
			swap_both(stack_a, stack_b);
		if ((*stack_b)->index > bot_b && (*stack_b)->index > sec_b && (*stack_b)->index < (*stack_a)-> index)
		{
			push_stack(stack_a, stack_b);
			i--;
		}
		if ((*stack_b)->index < sec_b)
			swap_stack(stack_b, 1);
		
		
	}
	
}
