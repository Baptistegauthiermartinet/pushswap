/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:41 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/18 15:58:28 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	int		i;
	
	a = NULL;
	i = 0;
	while (argv[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
	}
	if (argc == 1 )//|| check_duplicates )
	{
		print_error();
		return (0);
	}
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->content;
	}
	
}