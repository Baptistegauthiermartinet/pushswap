/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:41 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/08 15:59:46 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");
	return (0);
}

void	name_b(t_list *b)
{
	t_list	*current;

	current = b;
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
	{
		free_stack(stack_a);
		return (0);
	}
	set_index(stack_a);
	sort(&stack_a, &stack_b);
	free_stack(stack_a);
	stack_a = NULL;
	free_stack(stack_b);
	stack_b = NULL;
}
