/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:41:29 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/26 14:27:46 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL)
		return ;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack -> next;
		free(temp);
	}
}
