/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:41 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/18 17:22:10 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc == 1 || check_duplicates(argc, argv) == 0)
	{
		print_error();
		return (0);
	}
	// a = create_stack_a(argc, argv);
	// print_stack(a);
}
