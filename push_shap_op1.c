/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:38 by roo               #+#    #+#             */
/*   Updated: 2025/01/07 19:12:40 by roo              ###   ########.fr       */
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
     t_stack *first;
    t_stack *second;
    t_stack *third;

    first = *stack;
    second = (*stack)->next;
    third = (*stack)->next->next;
    *stack = second;
    second->next = first;
    first->next = third;

    t_stack *first_2;
    t_stack *second_2;
    t_stack *third_2;

    first_2 = *stack_2;
    second_2 = (*stack_2)->next;
    third_2 = (*stack_2)->next->next;
    *stack_2 = second_2;
    second_2->next = first_2;
    first_2->next = third_2;
}

/*t_stack *findprev(t_stack *stack_a, int num)
{
    while(stack_a->next && stack_a->next->num != num)
    {
        stack_a = stack_a->next;
    }
    return (stack_a);
}*/
