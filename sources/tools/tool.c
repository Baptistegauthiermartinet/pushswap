/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:21:43 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/07 12:03:42 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_it_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	nbr_comp(char *nbr, char *argument, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argument[j] == '-' && nbr[i] == '-')
	{
		j++;
		i++;
	}
	if (nbr[i] == '0' && is_it_zero(argument) == 1)
		return (0);
	while (argument[j] && argument[j] == '0')
		j++;
	while (nbr[i] && argument[j] && nbr[i] == argument[j] && n > 0)
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
		return (0);
	return (nbr[i] - argument[j]);
}

static void	give_index(t_list *stack)
{
	int		idx;
	int		temp;
	t_list	*head;

	idx = 1;
	temp = stack -> nbr;
	head = stack;
	stack = stack -> next;
	while (stack != head)
	{
		if (stack -> nbr < temp)
			idx++;
		stack = stack -> next;
	}
	stack = head;
	stack -> index = idx;
}

void	set_index(t_list *stack)
{
	t_list	*head;

	head = stack;
	give_index(stack);
	stack = stack -> next;
	while (stack != head)
	{
		give_index(stack);
		stack = stack -> next;
	}
	stack = head;
}

int	is_idx_max(t_list *stack)
{
	t_list	*head;
	int		idx;

	head = stack;
	idx = stack -> index;
	stack = stack -> next;
	while (stack != head)
	{
		if (stack -> index > idx)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
