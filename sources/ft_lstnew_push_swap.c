/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:29:38 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/04 11:38:58 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_push_swap(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> location = 'a';
	new -> nbr = content;
	new -> next = NULL;
	new -> previous = NULL;
	return (new);
}
