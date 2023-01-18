/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:19:44 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/18 17:29:47 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
}

void	print_stack(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}

t_list	*create_stack_a(int argc, char **argv)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 1;
	while (argv[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
	}
	return (a);
}

int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 2)
		{
			if (ft_strncmp(argv[i], argv[j], 100) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
