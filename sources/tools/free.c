/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:41:29 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/07 15:24:48 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL)
		return ;
	temp = stack -> previous;
	temp -> next = NULL;
	temp = stack;
	while (stack != NULL)
	{
		stack = stack -> next;
		free(temp);
		temp = stack;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
