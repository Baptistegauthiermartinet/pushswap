/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:19:44 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/04 19:14:37 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_error(void)
{
	ft_printf("Error\n");
	return (0);
}

static int	is_str_int(char *str)
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

static int	ft_is_int(int argc, char **argv)
{
	int		i;
	int		arg_len;
	int		nbr;
	char	*str;

	i = 1;
	while (i < argc)
	{
		if (is_str_int(argv[i]) == 0)
			return (0);
		if (argv[i][0] == '0')
			return (1);
		arg_len = ft_strlen(argv[i]);
		nbr = ft_atoi(argv[i]);
		str = ft_itoa(nbr);
		if (nbr_comp(str, argv[i], arg_len) != 0) /* pb avec -0 ? */
		{
			free(str);
			return (0);
		}
		i++;
		free(str);
	}
	return (1);
}

static int	check_duplicates(t_list	*lst)
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

int	check_errors(int argc, char **argv, t_list **a)
{
	if (argc == 1)
		return (0);
	if (ft_is_int(argc, argv) == 0)
		return (print_error());
	*a = create_stack_a(argv);
	if (check_duplicates(*a) == 0)
		return (print_error());
	return (1);
}
