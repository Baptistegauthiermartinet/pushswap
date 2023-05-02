/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:12:54 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/02 12:49:37 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;
	int		rank;

	rank = 0;
	if (lst && new)
	{
		head = *lst;
		while (*lst && (*lst)-> next)
		{
			*lst = (*lst)-> next;
			rank++;
		}
		if (*lst)
		{
			(*lst)-> next = new;
			new -> rank = rank;
			*lst = head;
		}
		else
		{
			*lst = new;
			new -> rank = rank;
		}
	}
}
