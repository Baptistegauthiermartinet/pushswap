/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:02:03 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/26 13:22:05 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	change_location(t_list *node)
{
	if (node -> location == 'a')
		node -> location = 'b';
	else
		node -> location = 'a';
}

static t_list	*reconnect_ptrs(t_list **temp_next, t_list **temp_previous)
{
	if ((*temp_next) == NULL)
		return (NULL);
	else
	{
		(*temp_previous)-> next = (*temp_next);
		(*temp_next)-> previous = (*temp_previous);
		return (*temp_next);
	}
}

static void	connect(t_list **stack, t_list **node)
{
	t_list	*temp;

	temp = (*stack)-> previous;
	temp -> next = (*node);
	(*node)-> previous = temp;
	(*node)-> next = (*stack);
	(*stack)-> previous = (*node);
	(*stack) = (*node);
}

void	push_stack(t_list **stack_to, t_list **stack_from)
{
	t_list	*temp_next;
	t_list	*temp_previous;

	if ((*stack_from) == NULL)
		return ;
	temp_next = (*stack_from)-> next;
	if (temp_next -> nbr == (*stack_from)-> nbr)
		temp_next = NULL;
	temp_previous = (*stack_from)-> previous;
	if ((*stack_to) == NULL)
	{
		(*stack_from)-> next = (*stack_from);
		(*stack_from)-> previous = (*stack_from);
		(*stack_to) = (*stack_from);
	}
	else
		connect(stack_to, stack_from);
	(*stack_from) = reconnect_ptrs(&temp_next, &temp_previous);
	change_location(*stack_to);
	ft_printf("p%c\n", (*stack_to)-> location);
}
