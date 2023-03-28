/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:20:21 by bgauthie          #+#    #+#             */
/*   Updated: 2023/03/28 11:30:25 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_stack(t_list **stack)
{
    *stack = (*stack) -> next;
}

void    rev_rotate_stack(t_list **stack)
{
    *stack = (*stack) -> previous;
}

void    rotate_both(t_list *stack_a, t_list *stack_b)
{
    rotate_stack(&stack_a);
    rotate_stack(&stack_b);
}

void    rev_rotate_both(t_list *stack_a, t_list *stack_b)
{
    rev_rotate_stack(&stack_a);
    rev_rotate_stack(&stack_b);
}