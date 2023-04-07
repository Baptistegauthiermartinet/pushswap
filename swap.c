/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:49:17 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/07 13:34:50 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	swap_stack(t_list **head, int n)
{
	t_list	*temp_prev;
	t_list	*second_node;
	t_list	*temp_next;
	int		size;

	size = ft_lstsize_push_swap(*head);
	if (size == 1 || size == 0)
		return ;
	if (size > 2)
	{
		temp_prev = (*head)-> previous;
		second_node = (*head)-> next;
		temp_next = second_node -> next;
		temp_prev -> next = second_node;
		second_node -> previous = temp_prev;
		second_node -> next = (*head);
		(*head)-> previous = second_node;
		(*head)-> next = temp_next;
		temp_next -> previous = (*head);
		(*head) = second_node;
	}
	else
		(*head) = (*head)-> next;
	if (n == 1)
		ft_printf("s%c\n", (*head)-> location);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a, 0);
	swap_stack(stack_b, 0);
	ft_printf("ss\n");
}