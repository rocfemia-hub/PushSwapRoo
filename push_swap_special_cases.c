/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_special_cases.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:15:11 by roo               #+#    #+#             */
/*   Updated: 2025/02/03 20:28:14 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_ascending(t_stack *stack)
{
	while(stack->next)
	{
		if(stack->num > stack->next->num)
			return(stack->num);
		stack = stack->next;
	}
	return(0);
}

int last3_stack_a(t_stack **stack_a, t_vars *var)
{
	var->first = (*stack_a)->num;
	var->second = (*stack_a)->next->num;
	var->trird = (*stack_a)->next->next->num;
	if(ft_if_ascending(*stack_a) == 0)
		return (0);
	else if(var->first > var->second && var->trird > var->first)
		return (var->num_ops += ft_swap(stack_a), 1);
	else if (var->first < var->trird && var->trird < var->second)
		return (var->num_ops += ft_swap(stack_a), var->num_ops += ft_rotate(stack_a), 2);
	else if (var->trird < var->second && var->second > var->first)
		return (var->num_ops += ft_reverse_rotate(stack_a), 3);
	else if (var->first > var->second && var->second < var->trird)
		return (var->num_ops += ft_rotate(stack_a), 4);
	else if (var->first > var->second && var->second > var->trird)
		return (var->num_ops += ft_rotate(stack_a), var->num_ops += ft_swap(stack_a), 5);
	return (6);
}