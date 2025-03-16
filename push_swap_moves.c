/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:15:11 by roo               #+#    #+#             */
/*   Updated: 2025/03/16 16:37:17 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_ascending(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_if_repeat(t_stack *stack)
{
	t_stack	*stack_aux;
	int		i;

	i = stack->num;
	stack_aux = stack->next;
	while (stack_aux)
	{
		if (i == stack_aux->num)
			return (ft_printf("num duplicado %d\n", stack->num), 0);
		stack_aux = stack_aux->next;
	}
	if (stack->next == NULL)
		return (1);
	return (ft_if_repeat(stack->next));
}

int	ft_if_numb(char *argv, char **argvn, t_stack **stack_a)
{
	int	i;

	i = -1;
	argvn = ft_split(argv, ' ');
	while (argvn[++i])
	{
		if (ft_nums_overflow(argvn[i]) == -1)
			return (ft_free_stack(stack_a), ft_free_split(argvn), -1);
		ft_stackadd_back(stack_a, ft_stacknew(ft_atoi2(argvn[i])));
	}
	return (ft_free_split(argvn), 0);
}

int	ft_last3_stack_a(t_stack **stack_a, t_vars *var)
{
	var->first = (*stack_a)->num;
	var->second = (*stack_a)->next->num;
	var->third = (*stack_a)->next->next->num;
	if (ft_if_ascending(*stack_a))
		return (0);
	else if (var->first > var->second && var->third > var->first)
		return (var->num_ops = var->num_ops + ft_swap(stack_a, 0), 1);
	else if (var->first < var->third && var->third < var->second)
		return (var->num_ops = var->num_ops + ft_swap(stack_a, 0),
			var->num_ops = var->num_ops + ft_rotate(stack_a, 0), 2);
	else if (var->third < var->second && var->second > var->first)
		return (var->num_ops = var->num_ops + ft_reverse_rotate(stack_a, 0), 3);
	else if (var->first > var->second && var->second < var->third)
		return (var->num_ops = var->num_ops + ft_rotate(stack_a, 0), 4);
	else if (var->first > var->second && var->second > var->third)
		return (var->num_ops = var->num_ops + ft_rotate(stack_a, 0),
			var->num_ops = var->num_ops + ft_swap(stack_a, 0), 5);
	return (6);
}

void	ft_big_first(t_stack **stack_b, t_vars *var)
{
	int	mid_len_b;

	mid_len_b = var->len_b / 2;
	if (var->pos_max_b != 0)
	{
		if (var->pos_max_b > mid_len_b)
		{
			while (var->pos_max_b < var->len_b)
			{
				var->num_ops = var->num_ops + ft_reverse_rotate(stack_b, 1);
				var->pos_max_b++;
			}
		}
		else
		{
			while (var->pos_max_b > 0)
			{
				var->num_ops = var->num_ops + ft_rotate(stack_b, 1);
				var->pos_max_b--;
			}
		}
	}
}
