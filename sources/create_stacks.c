/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:03 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/23 14:48:48 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack_a(char **argv)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 1;
	while (argv[i])
		ft_lstadd_back(&a, ft_lstnew_push_swap(ft_atoi(argv[i++])));
	return (a);
}

void	add_prev_ptr(t_list *lst)
{
	t_list	*temp;
	t_list	*current;

	temp = lst;
	current = lst -> next;
	while (current)
	{
		current -> previous = temp;
		temp = current;
		current = current -> next;
	}
	temp = ft_lstlast(lst);
	lst -> previous = temp;
	temp -> next = lst;
}
