/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:20:21 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/24 16:26:44 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	if ((*stack) != NULL)
	{
		*stack = (*stack)-> next;
		ft_printf("r%c\n", (*stack)-> location);
	}
	else
		return ;
}

void	rev_rotate_stack(t_list **stack)
{
	if ((*stack) != NULL)
	{
		*stack = (*stack)-> previous;
		ft_printf("rr%c\n", (*stack)-> location);
	}
	else
		return ;
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) != NULL)
		*stack_a = (*stack_a)-> next;
	if ((*stack_b) != NULL)
		*stack_b = (*stack_b)-> next;
	ft_printf("rr\n");
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) != NULL)
		*stack_a = (*stack_a)-> previous;
	if ((*stack_b) != NULL)
		*stack_b = (*stack_b)-> previous;
	ft_printf("rrr\n");
}
