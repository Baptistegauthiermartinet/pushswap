/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:49:17 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/09 14:36:30 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **stack, int n)
{
	int		head_nbr;
	int		next_nbr;
	int		head_idx;
	int		next_idx;
	t_list	*temp_next;

	if ((*stack) == NULL)
		return ;
	if (ft_lstsize_push_swap(*stack) == 1 || ft_lstsize_push_swap(*stack) == 0)
		return ;
	head_nbr = (*stack)-> nbr;
	head_idx = (*stack)-> index;
	temp_next = (*stack)-> next;
	next_nbr = temp_next -> nbr;
	next_idx = temp_next -> index;
	(*stack)-> nbr = next_nbr;
	(*stack)-> index = next_idx;
	temp_next -> nbr = head_nbr;
	temp_next -> index = head_idx;
	if (n == 1)
		ft_printf("s%c\n", (*stack)-> location);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a, 2);
	swap_stack(stack_b, 2);
	ft_printf("ss\n");
}
