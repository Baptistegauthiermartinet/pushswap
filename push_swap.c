/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:41 by bgauthie          #+#    #+#             */
/*   Updated: 2023/03/28 12:05:43 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *lst)
{
	if (!lst)
	{
		ft_printf("stack NULL\n");
		return;
	}
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
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_b = NULL;
	if (check_errors(argc, argv, &stack_a) == 0)
		return (0);
	add_prev_ptr(stack_a);

	print_stack(stack_a);
	print_stack(stack_b);
}

