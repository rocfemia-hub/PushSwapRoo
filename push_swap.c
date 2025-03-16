/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:32:42 by roo               #+#    #+#             */
/*   Updated: 2025/03/16 19:15:18 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_vars	*var;
	char	**argvn;

	var = ft_calloc(1, sizeof(t_vars));
	stack_a = NULL;
	stack_b = NULL;
	argvn = NULL;
	if (argc == 1)
		return (ft_printf("Error\n"), free(var), -1);
	if (ft_next_step(argc, argv, argvn, &stack_a) == -1)
		return (ft_printf("Error\n"), 0);
	var->num_ops = 0;
	var->len_a = ft_stacksize(stack_a);
	var->len_b = ft_stacksize(stack_b);
	ft_next_next_step(stack_a, stack_b, var);
	return (0);
}

int	ft_next_step(int argc, char **argv, char **argvn, t_stack **stack_a)
{
	int	i;

	i = 0;
	if (argc == 2 && !argvn)
	{
		i = -1;
		argvn = ft_split(argv[1], ' ');
		while (argvn[++i])
		{
			if (ft_nums_overflow(argvn[i]) == -1)
				return (ft_printf("Error\n"), ft_free_stack(stack_a),
					ft_free_split(argvn), -1);
			ft_stackadd_back(stack_a, ft_stacknew(ft_atoi2(argvn[i])));
		}
		ft_free_split(argvn);
	}
	else
	{
		while (argv[++i])
		{
			if (ft_if_numb(argv[i], argvn, stack_a) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_next_next_step(t_stack *stack_a, t_stack *stack_b, t_vars *var)
{
	if (var->len_a == 0)
		return (ft_printf("Error\n"), free(var), 0);
	ft_min_max(var, stack_b);
	if (ft_if_repeat(stack_a) != 1)
		return (ft_printf("Error\n"), ft_free_stack(&stack_a), 0);
	if (ft_if_ascending(stack_a) == 1)
		return (ft_free_stack(&stack_a), free(var), 0);
	if (var->len_a <= 3)
		ft_lil_nums(&stack_a, &stack_b, var);
	else
	{
		while (var->len_a > 3)
		{
			ft_price_mov(stack_a, stack_b, var);
			ft_optimize_position(&stack_a, &stack_b, var);
			var->len_a = ft_stacksize(stack_a);
			var->len_b = ft_stacksize(stack_b);
			ft_min_max(var, stack_b);
		}
		ft_last3_stack_a(&stack_a, var);
		ft_big_first(&stack_b, var);
		ft_pivots(&stack_a, &stack_b, var);
	}
	return (ft_free_stack(&stack_a), free(var), 0);
}

/* ft_printf("\nAsí esta el stack_a:\n");
    ft_print_stack(stack_a);
ft_printf("\nNúmero de movimientos: 
%d\nEstá ordenado?: %d\n", var->num_ops, ft_if_ascending(stack_a)); 
ARG=$(seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '); ./push_swap $ARG*/