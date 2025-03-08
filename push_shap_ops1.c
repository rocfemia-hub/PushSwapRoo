/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shap_ops1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:38 by roo               #+#    #+#             */
/*   Updated: 2025/03/08 21:27:05 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_swap(t_stack **stack, int mov) // sa sb
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
	if(mov == 0)
		ft_printf("sa\n");
	else if(mov == 1)
		ft_printf("sb\n");    
    return(1);
}

int ft_swap_swap(t_stack **stack, t_stack **stack_2) // ss
{
    ft_swap(stack, -1);
	ft_swap(stack_2, -1);
	ft_printf("ss\n");
    return(1);
}

int ft_push(t_stack **stack_dest, t_stack **stack_orig, int mov) // pa pb
{
    t_stack *first_orig;

	first_orig = *stack_orig;
	*stack_orig = (*stack_orig)->next;
	first_orig->next = NULL;
	ft_stackadd_front(stack_dest, first_orig);
	if(mov == 1)
		ft_printf("pa\n");
	else if(mov == 0)
		ft_printf("pb\n");
    return(1);
}
