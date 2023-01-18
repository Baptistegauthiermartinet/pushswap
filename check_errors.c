/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:19:44 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/18 13:29:33 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(void)
{
	ft_printf("Error\n");
}

int	check_duplicates(int arg_nbr, char **arguments)
{
	int	i;
	int	j;

	i = 1;
	while (i < arg_nbr)
	{
		j = i + 1;
		while (j <= arg_nbr)
		{
			if (arguments[i] == arguments[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}