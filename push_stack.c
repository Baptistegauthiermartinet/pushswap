/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:02:03 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/06 14:19:26 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_location(t_list *node)
{
	if (node -> location == 'a')
		node -> location = 'b';
	else
		node -> location = 'a';
}

static t_list	*get_next_node(t_list *stack)
{	
	if (ft_lstsize_push_swap(stack) == 1)
		return (NULL);
	else
		return (stack -> next);
}

static t_list	*get_previous_node(t_list *stack)
{
	if (ft_lstsize_push_swap(stack) == 1)
		return (NULL);
	else
		return (stack -> previous);
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

void	push_stack(t_list **stack_to, t_list **stack_from)
{
	t_list	*temp_next;
	t_list	*temp_previous;

	if ((*stack_from) == NULL)
		return ;
	temp_next = get_next_node(*stack_from);
	temp_previous = get_previous_node(*stack_from);
	if ((*stack_to) == NULL)
	{
		(*stack_from)-> next = (*stack_from);
		(*stack_from)-> previous = (*stack_from);
		(*stack_to) = (*stack_from);
	}
	else
	{
		(*stack_from)-> next = (*stack_to);
		(*stack_from)-> previous = (*stack_to)-> previous;
		(*stack_to) = (*stack_from);
	}
	(*stack_from) = reconnect_ptrs(&temp_next, &temp_previous);
	change_location(*stack_to);
	ft_printf("p%c\n", (*stack_to)-> location);
}
