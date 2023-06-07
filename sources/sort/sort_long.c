/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:45:01 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/07 12:44:04 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	shorter_path(t_list **stack, int idx)
{
	int		i;
	int		j;
	t_list	*head;

	i = 0;
	head = (*stack);
	while ((*stack)->index != idx)
	{
		(*stack) = (*stack)->next;
		i++;
	}
	j = 0;
	(*stack) = head;
	while ((*stack)->index != idx)
	{
		(*stack) = (*stack)->previous;
		j++;
	}
	(*stack) = head;
	if (i <= j)
		return (i);
	else
		return (-j);
}

static int	shorter_to(t_list **stack, int boundary)
{
	int		i;
	int		j;
	t_list	*head;

	i = 0;
	head = (*stack);
	while ((*stack)->index > boundary)
	{
		(*stack) = (*stack)->next;
		i++;
	}
	j = 0;
	(*stack) = head;
	while ((*stack)->index > boundary)
	{
		(*stack) = (*stack)->previous;
		j++;
	}
	(*stack) = head;
	if (i <= j)
		return (i);
	else
		return (-j);
}

static void	mini_sort(t_list **stack_a, t_list **stack_b, int boundary)
{
	int	cpt;

	cpt = shorter_to(stack_a, boundary);
	go_next(stack_a, cpt);
	empty_sort(stack_a, stack_b);
}

static void	empty_stack(t_list **stack_a, t_list **stack_b)
{
	int	nbr_to_push;
	int	boundary;
	int	i;

	i = ft_lstsize_push_swap(*stack_a) / 13;
	boundary = 0;
	while ((*stack_a) != NULL)
	{
		if (i == 0)
		{
			boundary = ft_lstsize_push_swap(*stack_a);
			nbr_to_push = boundary;
		}
		else
		{
			boundary += i;
			nbr_to_push = i;
		}
		while (nbr_to_push > 0 && (*stack_a) != NULL)
		{
			mini_sort(stack_a, stack_b, boundary);
			nbr_to_push--;
		}
	}
}

void	sort_long(t_list **stack_a, t_list **stack_b)
{
	int	cpt;

	empty_stack(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		if ((*stack_a) == NULL)
		{
			while ((*stack_b)-> index != ft_lstsize_push_swap(*stack_b))
				rotate_stack(stack_b);
			push_stack(stack_a, stack_b);
		}
		cpt = shorter_path(stack_b, (*stack_a)->index -1);
		go_next(stack_b, cpt);
		push_stack(stack_a, stack_b);
	}
}
