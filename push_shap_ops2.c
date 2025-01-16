/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shap_ops2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:22 by roo               #+#    #+#             */
/*   Updated: 2025/01/16 23:16:17 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    //t_stack *third;

    first = *stack;
    second = (*stack)->next;
    //third = (*stack)->next->next;
    *stack = second;
    first->next = NULL;
    ft_stackadd_back(stack, first);
    
    return(1);

}

int ft_rotate_rotate(t_stack **stack, t_stack **stack_2)
{
    if(ft_rotate(stack) == 1 && ft_rotate(stack_2) == 1)
        return(1);
    return(0);
}

int ft_reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *prelast;

    prelast = *stack;
    while (prelast->next->next)
        prelast = prelast->next;
    last = prelast->next;
    prelast->next = NULL;
    last->next = *stack;
    *stack = last;
    
    return(1);
}

int ft_reverse_reverse(t_stack **stack, t_stack **stack_2)
{
    if(ft_reverse_rotate(stack) == 1 && ft_reverse_rotate(stack_2) == 1)
        return(1);
    return(0);
}