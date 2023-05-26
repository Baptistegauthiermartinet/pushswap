/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:54:58 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/26 14:31:56 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_list **stack)
{
	if (is_idx_max(*stack) == 1)
		swap_stack(stack, 1);
}

void	sort_three(t_list **stack)
{
	int	idx;

	idx = (*stack)-> index;
	if (idx > (*stack)->next->index && idx > (*stack)->previous->index)
	{
		rotate_stack(stack);
		if ((*stack)-> index > (*stack)-> next -> index)
			swap_stack(stack, 1);
	}
	else if (idx < (*stack)->next->index && idx > (*stack)->previous->index)
	{
		rev_rotate_stack(stack);
		return ;
	}
	else if (idx > (*stack)->next->index && idx < (*stack)->previous->index)
		swap_stack(stack, 1);
	else if (idx < (*stack)->next->index && idx < (*stack)->previous->index)
	{
		if ((*stack)->next->index > (*stack)->previous->index)
		{
			swap_stack(stack, 1);
			rotate_stack(stack);
		}
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	if (is_sorted((*stack_a)-> next) == 1)
	{
		rotate_stack(stack_a);
		return ;
	}
	if (is_idx_max((*stack_a)-> previous) == 1)
		rev_rotate_stack(stack_a);
	else if (is_idx_max((*stack_a)-> next) == 1)
		rotate_stack(stack_a);
	else if (is_idx_max((*stack_a)-> next -> next) == 1)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_a);
	}
	push_stack(stack_b, stack_a);
	sort_three(stack_a);
	push_stack(stack_a, stack_b);
	rotate_stack(stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	if (is_idx_max((*stack_a)-> previous) == 1)
		rev_rotate_stack(stack_a);
	else if (is_idx_max((*stack_a)-> next) == 1)
		rotate_stack(stack_a);
	else if (is_idx_max((*stack_a)-> next -> next) == 1)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_a);
	}
	else if (is_idx_max((*stack_a)->previous->previous) == 1)
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_a);
	}
	push_stack(stack_b, stack_a);
	sort_four(stack_a, stack_b);
	push_stack(stack_a, stack_b);
	rotate_stack(stack_a);
}

void	sort_short(t_list **stack_a, t_list **stack_b, int len)
{
	if (is_sorted((*stack_a)-> next) == 1)
	{
		rotate_stack(stack_a);
		return ;
	}
	if (is_sorted((*stack_a)-> previous) == 1)
	{
		rev_rotate_stack(stack_a);
		return ;
	}
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
}
