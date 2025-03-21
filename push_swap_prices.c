/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:55:21 by roo               #+#    #+#             */
/*   Updated: 2025/03/16 16:08:33 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_price_mov(t_stack *stack_a, t_stack *stack_b, t_vars *var)
{
	var->price = INT_MAX;
	var->tmp_i_a = 0;
	while (stack_a)
	{
		ft_price(stack_a, stack_b, var);
		var->tmp_i_a++;
		stack_a = stack_a->next;
	}
}

void	ft_price(t_stack *stack_a, t_stack *stack_b, t_vars *var)
{
	var->tmp_price = INT_MAX;
	if (stack_a->num < var->max_b && stack_a->num > var->min_b)
		ft_normal_price(stack_a, stack_b, var);
	else if (stack_a->num > var->max_b || stack_a->num < var->min_b)
		ft_unusual_price(stack_b, var);
	if (var->tmp_price < var->price)
	{
		var->price = var->tmp_price;
		var->i_stack_a = var->tmp_i_a;
		var->i_stack_b = var->tmp_i_b;
	}
}

void	ft_normal_price(t_stack *stack_a, t_stack *stack_b, t_vars *var)
{
	var->tmp_price = 0;
	var->tmp_i_b = ft_ideal_pos(stack_a->num, var, stack_b);
	if (var->tmp_i_a > (var->len_a / 2) + 1)
		var->tmp_price = var->tmp_price + (var->len_a - var->tmp_i_a);
	else
		var->tmp_price = var->tmp_price + var->tmp_i_a;
	if (var->tmp_i_b > (var->len_b / 2) + 1)
		var->tmp_price = var->tmp_price + (var->len_b - var->tmp_i_b);
	else
		var->tmp_price = var->tmp_price + var->tmp_i_b;
	var->tmp_price++;
}

void	ft_unusual_price(t_stack *stack_b, t_vars *var)
{
	var->tmp_price = 0;
	var->tmp_i_b = ft_find_indexbynum(var->max_b, stack_b);
	if (var->tmp_i_a > (var->len_a / 2) + 1)
		var->tmp_price = var->tmp_price + (var->len_a - var->tmp_i_a);
	else
		var->tmp_price = var->tmp_price + var->tmp_i_a;
	if (var->tmp_i_b > (var->len_b / 2) + 1)
		var->tmp_price = var->tmp_price + (var->len_b - var->tmp_i_b);
	else
		var->tmp_price = var->tmp_price + var->tmp_i_b;
	var->tmp_price++;
}

int	ft_ideal_pos(int number, t_vars *var, t_stack *stack)
{
	int		i;
	t_stack	*node;
	t_stack	*tmp;

	i = 0;
	node = stack;
	tmp = stack;
	while (node)
	{
		if (node->num == stack->num)
			tmp = ft_stacklast(stack);
		if (number > node->num && number < tmp->num && var->max_b != node->num)
			return (i);
		i++;
		if (tmp == ft_stacklast(stack))
		{
			tmp = stack;
			node = node->next;
			continue ;
		}
		tmp = tmp->next;
		node = node->next;
	}
	return (42000);
}
