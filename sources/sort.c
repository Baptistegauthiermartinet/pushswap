/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:49:02 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/09 18:16:23 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize_push_swap(*stack_a);
	if (len <= 5)
		sort_short(stack_a, stack_b, len);
	else
		sort_long(stack_a, stack_b);
}
