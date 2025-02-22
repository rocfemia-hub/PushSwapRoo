/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:32:42 by roo               #+#    #+#             */
/*   Updated: 2025/02/20 16:24:43 by roo              ###   ########.fr       */
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
    if (argc == 2 && !argvn)
	{
 	   	i = -1;
        argvn = ft_split(argv[1], ' ');
		while (argvn[++i])
		{
			if (ft_nums_overflow(argvn[i]) == -1)
				return(ft_printf("Error!!!\n"), ft_free_stack(&stack_a), 0); //debes freesear antes de retornar
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi2(argvn[i])));
		}
	}
	else
	{
		i = 0;
		while (argv[++i])
		{
			if (ft_nums_overflow(argv[i]) == -1)
				return(ft_printf("Error!!!\n"), ft_free_stack(&stack_a), 0); //debes freesear antes de retornar
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi2(argv[i])));
		}
	}

    ////////////////////////// PRUEBAS //////////////////////////
    
    //ft_swap(&stack_a);
    //ft_swap_swap(&stack_b, &stack_a);
    //ft_push(&stack_b, &stack_a);
    //ft_push(&stack_a, &stack_b);
    //ft_rotate(&stack_a);
    //ft_rotate_rotate(&stack_a, &stack_b);
    //ft_reverse_rotate(&stack_a);
    //ft_reverse_reverse(&stack_a, &stack_b);

    var->len_a = ft_stacksize(stack_a);
    var->len_b = ft_stacksize(stack_b);
    ft_min_max(var, stack_b);
    while(var->len_a > 3)
    {
        ft_price_mov(stack_a, stack_b, var);
        while (var->i_stack_a-- > 0)
            var->num_ops = var->num_ops + ft_rotate(&stack_a);
        while (var->i_stack_b-- > 0)
            var->num_ops = var->num_ops + ft_rotate(&stack_b);
        var->num_ops = var->num_ops + ft_push(&stack_b, &stack_a);
	    var->len_a = ft_stacksize(stack_a);
    	var->len_b = ft_stacksize(stack_b);
        ft_min_max(var, stack_b);
    }
	ft_last3_stack_a(&stack_a, var);
	ft_big_first(&stack_b, var);
	ft_pivots(&stack_a, &stack_b, var);
	
    // int pos = ft_ideal_pos(stack_a->num, var, stack_b);
    // if (pos != 42000)
    //     ft_printf("\n El número %d debe insertarse en la posición %d.\n", stack_a->num, pos);
    // else
    //     ft_printf("\n No se encontró una posición adecuada para el número %d.\n", stack_a->num);
    //ft_printf("\n así se queda el stack_a al final:\n");
    //ft_print_stack(stack_a);
    //ft_printf("\n así se queda el stack_b al final:\n");
    //ft_print_stack(stack_b);
    ft_printf("\n así esta el stack_a:\n");
    ft_print_stack(stack_a);
    ft_printf("\n así esta el stack_b:\n");
    ft_print_stack(stack_b);
	ft_printf("\n%d\n ordenado %d\n", var->num_ops, ft_if_ascending(stack_a));
    ft_free_stack(&stack_a);
    return(0);
}
