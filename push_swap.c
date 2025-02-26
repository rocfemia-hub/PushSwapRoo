/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:32:42 by roo               #+#    #+#             */
/*   Updated: 2025/02/26 18:30:34 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_vars  *var;
    int     i;
    char    **argvn;
    
    stack_a = NULL;
    var = ft_calloc(1, sizeof(t_vars));
	var->num_ops = 0;
    stack_b = NULL;
    argvn = NULL;
	// gestion simple sin arg, argumento vacio ""
/* 	if (argc == 1)
		return (ft_printf("Error_1\n"), free(var), -1); */
    if (argc == 2 && !argvn)
	{
 	   	i = -1;
        argvn = ft_split(argv[1], ' ');
		while (argvn[++i])
		{
			if (ft_nums_overflow(argvn[i]) == -1)
				return(ft_printf("Error_2\n"), ft_free_stack(&stack_a), 0); //debes freesear antes de retornar
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi2(argvn[i])));
		}
		ft_free_split(argvn);
	}
	else
	{
		i = 0;
		while (argv[++i])
		{
			if (ft_nums_overflow(argv[i]) == -1)
				return(ft_printf("Error_3\n"), ft_free_stack(&stack_a), 0); //debes freesear antes de retornar
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi2(argv[i])));
		}
	}
	// gestionar numeros del 1 al 5 y sin argumentos
	/* if (ft_stacksize(stack_a) < 6)
		return (ft_printf("Error_5\n"), free(var), -1); */
    var->len_a = ft_stacksize(stack_a);
    var->len_b = ft_stacksize(stack_b);
	if (var->len_a == 0)
		return (ft_printf("Error_4\n"), free(var), 0);
    ft_min_max(var, stack_b);
    while(var->len_a > 3)
    {
		// CALCULAR PRECIOS TMB A PARTIR DE LA MITAD
        ft_price_mov(stack_a, stack_b, var);
		ft_optimize_position(&stack_a, &stack_b, var);
	    var->len_a = ft_stacksize(stack_a);
    	var->len_b = ft_stacksize(stack_b);
        ft_min_max(var, stack_b);
    }
	ft_last3_stack_a(&stack_a, var);
	ft_big_first(&stack_b, var);
	ft_pivots(&stack_a, &stack_b, var);
    ft_printf("\nAsí esta el stack_a:\n");
    ft_print_stack(stack_a);
    ft_printf("\nAsí esta el stack_b:\n");
    ft_print_stack(stack_b);
	ft_printf("\nMovimientos: %d\nOrdenado: %d\n", var->num_ops, ft_if_ascending(stack_a));
    ft_free_stack(&stack_a);
	free(var);
    return(0);
}
