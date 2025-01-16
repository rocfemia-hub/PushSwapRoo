/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shap_ops1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:38 by roo               #+#    #+#             */
/*   Updated: 2025/01/16 23:16:31 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    first = *stack;
    second = (*stack)->next;
    third = (*stack)->next->next;
    *stack = second;
    second->next = first;
    first->next = third;
    
    return(1);
}

int ft_swap_swap(t_stack **stack, t_stack **stack_2)
{
    if(ft_swap(stack) == 1 && ft_swap(stack_2) == 1)
        return(1);
    return(0);
}

int ft_push(t_stack **stack_dest, t_stack **stack_orig) // según el pa o el pb que queramos hacer colocaremos los stacks en un orden u otro.
{
    t_stack *first_dest;
    t_stack *first_orig;
    t_stack *tmp_aux;

    first_dest = *stack_dest;
    first_orig = *stack_orig;
    tmp_aux = (*stack_orig)->next;

    *stack_dest = first_orig;
    first_orig->next = first_dest;
    *stack_orig = tmp_aux;
    
    return(1);
}
