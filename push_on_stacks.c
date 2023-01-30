/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_on_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:39:53 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/30 15:06:37 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_on_a(t_list *a, t_list *b)
// {
	
// }

void	push_on_b(t_list *a, t_list *b)
{
	t_list	*temp;

	
	if (!a)
		return (0);
		
}

void	remove_one_node(t_list *lst)
{
	t_list	*current;
	t_list	*temp_prev;
	t_list	*temp_next;

	current = lst;
	temp_next = lst -> next;
	temp_prev = lst -> previous;
	lst = temp_next;
	current -> next = NULL;
	current -> previous = NULL;
	temp_prev -> next = temp_next;
	temp_next -> previous = temp_prev;
	
}
