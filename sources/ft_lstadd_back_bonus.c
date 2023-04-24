/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:12:54 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/24 17:24:23 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (lst && new)
	{
		head = *lst;
		while (*lst && (*lst)-> next)
			*lst = (*lst)-> next;
		if (*lst)
		{
			(*lst)-> next = new;
			*lst = head;
		}
		else
			*lst = new;
	}
}
