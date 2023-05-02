/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:05:31 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/02 12:12:41 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list *stack)
{
	t_list	*last_node;
	t_list	*first_node;
	t_list	*temp;

	last_node = stack -> previous;
	first_node = stack;
	while (stack != last_node)
	{
		temp = stack -> next;
		if (stack -> nbr > temp -> nbr)
			return (0);
		stack = stack -> next;
	}
	stack = first_node;
	return (1);
}