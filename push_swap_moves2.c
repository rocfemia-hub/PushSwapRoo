/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:18:57 by roo               #+#    #+#             */
/*   Updated: 2025/02/26 18:12:51 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize_position(t_stack **stack_a, t_stack **stack_b, t_vars *var)
{
	ft_double_rotate(stack_a, stack_b, var);
	if(var->i_stack_a > 0 && var->i_stack_a < var->len_a)
	{
		if(var->i_stack_a > (var->len_a / 2) + 1)
			while(var->i_stack_a++ < var->len_a)
				var->num_ops = var->num_ops + ft_reverse_rotate(stack_a);
		else
			while(var->i_stack_a-- > 0)
				var->num_ops = var->num_ops + ft_rotate(stack_a);
	}
	if(var->i_stack_b > 0 && var->i_stack_b < var->len_b)
	{
		if(var->i_stack_b > (var->len_b / 2) + 1)
			while(var->i_stack_b++ < var->len_b)
				var->num_ops = var->num_ops + ft_reverse_rotate(stack_b);
		else
			while(var->i_stack_b-- > 0)
				var->num_ops = var->num_ops + ft_rotate(stack_b);
	}
	var->num_ops = var->num_ops + ft_push(stack_b, stack_a);
}

void	ft_double_rotate(t_stack **stack_a, t_stack **stack_b, t_vars *var)
{
	while (var->i_stack_b > 0 && var->i_stack_a > 0
		&& var->i_stack_b < var->len_b / 2 && var->i_stack_a < var->len_a / 2)
	{
		var->num_ops = var->num_ops + ft_rotate_rotate(stack_a, stack_b);
		var->i_stack_a--;
		var->i_stack_b--;
	}
	while (var->i_stack_b > (var->len_b / 2) + 1 && var->i_stack_a > (var->len_a / 2) + 1
		&& var->i_stack_b < var->len_b && var->i_stack_a < var->len_a)
	{
		var->num_ops = var->num_ops + ft_reverse_reverse(stack_a, stack_b);
		var->i_stack_a++;
		var->i_stack_b++;
	}
}

int	ft_lil_nums(t_stack **stack_a, t_stack **stack_b, t_vars *var)
{
	if (var->len_a == 1)
		return (-1);
	if (var->len_a == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			return (var->num_ops = var->num_ops + ft_swap(stack_a), -1);
		return (-1);
	}
	if (var->len_a == 3)
		return (ft_last3_stack_a(stack_a, var), -1);
	if (var->len_a == 4)
	{
		var->num_ops = var->num_ops + ft_push(stack_b, stack_a);
		ft_last3_stack_a(stack_a, var);
		return (ft_pivots(stack_a, stack_b, var), -1);
	}
	if (var->len_a == 5)
	{
		var->num_ops = var->num_ops + ft_push(stack_b, stack_a);
		var->num_ops = var->num_ops + ft_push(stack_b, stack_a);
		ft_rare_parsing(stack_a, stack_b, var);
		ft_last3_stack_a(stack_a, var);
		return (ft_pivots(stack_a, stack_b, var), -1);
	}
	return (0);
}
