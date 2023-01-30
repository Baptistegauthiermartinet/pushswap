/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:19:44 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/30 14:04:01 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	check_errors(int argc, char **argv, t_list **a)
{
	if (argc == 1 || ft_is_int(argc, argv) == 0)
		return (print_error());
	*a = create_stack_a(argv);
	if (check_duplicates(*a) == 0)
		return (print_error());
	return (1);
}

int	is_str_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_int(int argc, char **argv) //pb sur le 0 et -0
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		if (is_str_int(argv[i]) == 0)
			return (0);
		len = ft_strlen(argv[i]);
		if (ft_strncmp(ft_itoa(ft_atoi(argv[i])), argv[i], len) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_list	*lst)
{
	t_list	*temp;
	t_list	*current;

	current = lst;
	while (current)
	{
		temp = current -> next;
		while (temp)
		{
			if (current -> nbr == temp -> nbr)
				return (0);
			temp = temp -> next;
		}
		current = current -> next;
	}
	return (1);
}
