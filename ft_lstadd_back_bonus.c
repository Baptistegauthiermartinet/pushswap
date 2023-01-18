/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:12:54 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/18 17:04:59 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
