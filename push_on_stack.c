/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_on_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:03:22 by bgauthie          #+#    #+#             */
/*   Updated: 2023/03/28 11:03:23 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_list	*push_on_stack(t_list *stack_to, t_list *node)
{
	t_list	*temp_next;
	t_list	*temp_prev;

	temp_next = node -> next;
	temp_prev = node -> previous;
	if (!stack_to)
	{
		stack_to = node;
		node -> next = NULL;
		node -> previous = NULL;
	}
	else
	{
		node -> next = stack_to;
		node -> previous = ft_lstlast(stack_to);
	}
	temp_next -> previous = temp_prev;
	temp_prev -> next = temp_next;
	return(temp_next);
}