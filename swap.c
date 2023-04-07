/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:49:17 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/07 14:26:05 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **stack)
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

	
	
	ft_printf("s%c\n", (*stack)-> location);
	
}

/*infinite_loop on sb*/