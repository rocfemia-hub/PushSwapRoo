/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shap_ops1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:38 by roo               #+#    #+#             */
/*   Updated: 2025/01/07 20:05:07 by roo              ###   ########.fr       */
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
}
int ft_swap_swap(t_stack **stack, t_stack **stack_2)
{
    *stack = ft_swap(stack);
    *stack_2 = ft_swap(stack_2);
}
int ft_push(t_stack **stack_dest, t_stack **stack_orig) // según el pa o el pb que queramos hacer colocaremos los stacks en un orden u otro.
{
    
}

/*t_stack *findprev(t_stack *stack_a, int num)
{
    while(stack_a->next && stack_a->next->num != num)
    {
        stack_a = stack_a->next;
    }
    return (stack_a);
}*/
