/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:03:30 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/07 12:02:19 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_two_top(t_list **stack)
{
	if ((*stack) == NULL)
		return (0);
	if ((*stack)->index < (*stack)->next->index)
		return (1);
	if ((*stack)->index > (*stack)->next->index)
		return (2);
	return (0);
}

int	check_neighbours(t_list **stack)
{
	int	head_idx;
	int	next_idx;
	int	bottom_idx;

	if ((*stack) == NULL)
		return (0);
	head_idx = (*stack)-> index;
	next_idx = (*stack)-> next -> index;
	bottom_idx = (*stack)-> previous -> index;
	if (head_idx < next_idx && head_idx < bottom_idx)
		return (1);
	if (head_idx > next_idx && head_idx > bottom_idx)
		return (2);
	if (head_idx > next_idx && head_idx < bottom_idx)
		return (3);
	if (head_idx < next_idx && head_idx > bottom_idx)
		return (4);
	return (0);
}

int	get_idx_min(t_list **stack)
{
	t_list	*head;
	int		idx_min;

	head = (*stack);
	*stack = (*stack)-> next;
	idx_min = (*stack)-> index;
	while (*stack != head)
	{
		if ((*stack)-> index < idx_min)
			idx_min = (*stack)-> index;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (idx_min);
}

void	empty_sort(t_list **stack_a, t_list **stack_b)
{
	push_stack(stack_b, stack_a);
	if (check_neighbours(stack_b) == 1)
		rotate_stack(stack_b);
	if (check_two_top(stack_b) == 1 && check_two_top(stack_a) == 2)
		swap_both(stack_a, stack_b);
	if (check_two_top(stack_b) == 1)
		swap_stack(stack_b, 1);
}

void	go_next(t_list **stack, int cpt)
{
	while (cpt != 0)
	{
		if (cpt > 0)
		{
			rotate_stack(stack);
			cpt--;
		}
		if (cpt < 0)
		{
			rev_rotate_stack(stack);
			cpt++;
		}
	}
}
