/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:41 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/04 19:53:16 by bgauthie         ###   ########.fr       */
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
	ft_printf("Stack %c = ", lst -> location);
	while (lst != temp)
	{
		ft_printf(" %d(%d) ", lst -> nbr, lst -> index);
		lst = lst->next;
	}
	ft_printf(" %d(%d)\n", lst -> nbr, lst -> index);
	lst = temp;
}

void	print_stacks(t_list *a, t_list *b)
{
	print_stack(a);
	print_stack(b);
}

void name_b(t_list *b)
{
	t_list *current = b;
	while (current)
	{
		current -> location = 'b';
		current = current -> next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_b = NULL;
	if (check_errors(argc, argv, &stack_a) == 0)
		return (0);
	add_prev_ptr(stack_a);
	if (is_sorted(stack_a) == 1)
		return (0);
	set_index(stack_a);
	sort(&stack_a, &stack_b);	
	


	
	print_stacks(stack_a, stack_b);


	
}


/*
	debug ----> -g dans makefile, fichier json a completer(args et nom de l`exec), F5*/