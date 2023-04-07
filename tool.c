/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:21:43 by bgauthie          #+#    #+#             */
/*   Updated: 2023/04/07 12:44:43 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_comp(char *nbr, char *argument, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argument[j] == '-' && nbr[i] == '-')
	{
		j++;
		i++;
	}
	while (argument[j] && argument[j] == '0')
		j++;
	while (nbr[i] && argument[j] && nbr[i] == argument[j] && n > 0)
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
		return (0);
	return (nbr[i] - argument[j]);
}
