/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:10:41 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/26 16:14:28 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_list *lst)		/*a retirer*/
{
	t_list	*temp;

	if (!lst)
	{
		ft_printf("stack NULL\n");
		return ;
	}
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

void	print_stacks(t_list *a, t_list *b)		/*a retirer*/
{
	print_stack(a);
	print_stack(b);
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
		return (0);
	set_index(stack_a);
	sort(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	if (is_sorted(stack_a) == 1)
		ft_printf("SUCCESS\n");
	//free_stack(stack_a);
}
