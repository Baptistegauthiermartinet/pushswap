/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:04:29 by bgauthie          #+#    #+#             */
/*   Updated: 2023/03/28 12:04:30 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_lstsize_push_swap(t_list *lst)
{
	int	i;
	t_list	*temp;
	t_list	*current;

	temp = lst;
	current = lst -> next;
	i = 1;
	while (current != temp)
	{
		current = current -> next;
		i++;
	}
	lst = temp;
	return (i);
}
