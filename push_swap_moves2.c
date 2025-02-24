/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:18:57 by roo               #+#    #+#             */
/*   Updated: 2025/02/24 16:07:50 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize_position(t_stack **stack_a, t_stack **stack_b, t_vars *var)
{
	if(var->i_stack_a > 0 && var->i_stack_a < var->len_a)
	{
		if(var->i_stack_a > (var->len_a / 2 + 1))
			while(var->i_stack_a++ < var->len_a)
				var->num_ops = var->num_ops + ft_reverse_rotate(stack_a);
		else
			while(var->i_stack_a-- > 0)
				var->num_ops = var->num_ops + ft_rotate(stack_a);
	}
	if(var->i_stack_b > 0 && var->i_stack_b < var->len_b)
	{
		if(var->i_stack_b > (var->len_b / 2 + 1))
			while(var->i_stack_b++ < var->len_b)
				var->num_ops = var->num_ops + ft_reverse_rotate(stack_b);
		else
			while(var->i_stack_b-- > 0)
				var->num_ops = var->num_ops + ft_rotate(stack_b);
	}
	var->num_ops = var->num_ops + ft_push(stack_a, stack_b);
}
