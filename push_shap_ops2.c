/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_shap_ops2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:22 by roo               #+#    #+#             */
/*   Updated: 2025/03/08 21:29:19 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate(t_stack **stack, int mov) // ra rb
{
    t_stack *first;
    t_stack *second;
    
    if(!*stack)
        return(0);
    first = *stack;
    second = (*stack)->next;
    *stack = second;
    first->next = NULL;
    ft_stackadd_back(stack, first);
	if(mov == 0)
		ft_printf("ra\n");
	else if(mov == 1)
		ft_printf("rb\n");
	
    return(1);

}

int ft_rotate_rotate(t_stack **stack, t_stack **stack_2) // rr
{
    ft_rotate(stack, -1);
	ft_rotate(stack_2, -1);
	ft_printf("rr\n");
    return(1);
}

int ft_reverse_rotate(t_stack **stack, int mov) // rra rrb
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
	if(mov == 0)
		ft_printf("rra\n");
	else if(mov == 1)
		ft_printf("rrb\n");
    return(1);
}

int ft_reverse_reverse(t_stack **stack, t_stack **stack_2) // rrr
{
    ft_reverse_rotate(stack, -1);
	ft_reverse_rotate(stack_2, -1);
	ft_printf("rrr\n");
    return(0);
}
