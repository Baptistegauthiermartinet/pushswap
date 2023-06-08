/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:46:40 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/08 12:46:57 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*last_node;
	t_list	*first_node;
	t_list	*temp;

	last_node = stack -> previous;
	first_node = stack;
	while (stack != last_node)
	{
		temp = stack -> next;
		if (stack -> nbr > temp -> nbr)
			return (0);
		stack = stack -> next;
	}
	stack = first_node;
	return (1);
}

int	get_len_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

int	ft_lstsize_push_swap(t_list *lst)
{
	int		i;
	t_list	*temp;
	t_list	*current;

	if (lst == NULL)
		return (0);
	temp = lst;
	current = lst -> next;
	i = 1;
	while (current != temp)
	{
		current = current -> next;
		i++;
	}
	lst = temp;
	return (i);
}

int	full_sep(const char *str, char sep)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
			return (1);
		else
			i++;
	}
	return (0);
}

int	choose_segment(t_list **stack)
{
	int	size;

	size = ft_lstsize_push_swap(*stack);
	if (size <= 100)
		return (size / 8);
	else
		return (size / 13);
}
