/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:06:40 by bgauthie          #+#    #+#             */
/*   Updated: 2023/03/28 12:07:00 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *swap_stack(t_list *stack)
{
    t_list *temp_next;
    t_list *temp_next_next;
    t_list *temp_prev;
    int     size;

    size = ft_lstsize_push_swap(stack);
    if (size < 2)
        return(stack);
    if (size == 2)
    {
        rotate_stack(&stack);
        return (stack);
    }
    temp_prev = stack -> previous;
    temp_next = stack -> next;
    temp_next_next = temp_next -> next;

    temp_prev -> next = temp_next;
    temp_next -> previous = temp_prev;
    temp_next -> next = stack;
    stack -> previous = temp_next;
    stack -> next = temp_next_next;
    temp_next_next -> previous = stack;
    return (temp_next);
}
/*
void    swap_both(t_list *stack_a, t_list *stack_b)
{
    stack_a = swap_stack(stack_a);
    stack_b = swap_stack(stack_b);
}
*/