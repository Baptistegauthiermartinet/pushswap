/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:25:25 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/02 12:38:05 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int len_int(int nbr)
{
	int	i;
	int	sgn;

	sgn = 1;
	if (nbr < 0)
		sgn *= -1;
	i = 1;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i * sgn);
}

void	get_class(t_list **stack)
{
	t_list	*last_node;
	t_list	*first_node;

	last_node = (*stack) -> previous;
	first_node = (*stack);
	while ((*stack) != last_node)
	{
		(*stack) -> class = len_int((*stack) -> nbr);
		(*stack) = (*stack) -> next;
	}
	(*stack) = first_node;
}