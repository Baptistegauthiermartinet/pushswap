/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:41 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/30 14:58:16 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *lst)
{
	t_list	*temp;

	temp = lst -> previous;
	ft_printf("Stack = ");
	while (lst != temp)
	{
		ft_printf(" %d ", lst->nbr);
		lst = lst->next;
	}
	ft_printf(" %d\n", lst -> nbr);
	lst = temp;
}

void	print_stacks(t_list *a, t_list *b)
{
	t_list	*temp;

	temp = a -> previous;
	ft_printf("A = ");
	while (a != temp)
	{
		ft_printf(" %d ", a -> nbr);
		a = a -> next;
	}
	ft_printf(" %d ", a -> nbr);
	temp = b -> previous;
	ft_printf("\nB = ");
	while (b != temp)
	{
		ft_printf(" %d ", b -> nbr);
		b = b -> next;
	}
	ft_printf(" %d \n", b -> nbr);

}

int	main(int argc, char **argv)
{
	// char	**arguments;
	// int		i;
	
	// // if (argc == 2)
	// // {
	// // 	arguments = ft_split(argv[1], ' ');
	// // 	i = 0;
	// // 	while (arguments[i])
	// // 		i++;
	// // 	argc += i - 1;
	// // 	check_errors(argc, arguments);
	// // }
	// // check_errors(argc, argv);



	t_list	*a;
	
	check_errors(argc, argv, &a);
	add_prev_ptr(a);
//	print_stack(a);


	remove_one_node(a);
	print_stack(a);


}

