/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:49:17 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/24 17:13:11 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **stack, int n)
{
	int		head_nbr;
	int		next_nbr;
	t_list	*temp_next;
	int		size;

	if ((*stack) == NULL)
		return ;
	size = ft_lstsize_push_swap(*stack);
	if (size == 1 || size == 0)
		return ;
	head_nbr = (*stack)-> nbr;
	temp_next = (*stack)-> next;
	next_nbr = temp_next -> nbr;
	(*stack)-> nbr = next_nbr;
	temp_next -> nbr = head_nbr;
	if (n == 1)
		ft_printf("s%c\n", (*stack)-> location);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a, 2);
	swap_stack(stack_b, 2);
	ft_printf("ss\n");
}
