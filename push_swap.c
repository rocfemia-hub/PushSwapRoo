/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:32:42 by roo               #+#    #+#             */
/*   Updated: 2025/01/21 19:58:14 by roo              ###   ########.fr       */
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
    stack_b = NULL;
    i = 0;
    if (argc == 2)
        argvn = ft_split(argv[1], ' ');
    i = 0;
    while (argv[++i])
    {
        if (ft_nums_overflow(argv[i]) == -1)
            return(ft_printf("Error!!!\n"), ft_free_stack(&stack_a), 0); //debes freesear antes de retornar
        ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi2(argv[i])));
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
    
    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);

    
    ft_printf("\n así empieza el stack_a:\n");
    ft_print_stack(stack_a);
    ft_printf("\n así empieza el stack_b:\n");
    ft_print_stack(stack_b);
    
    int pos = ft_idealpos(stack_a->num, stack_b);
    if (pos != 42000)
        ft_printf("\n El número %d debe insertarse en la posición %d.\n", stack_a->num, pos);
    else
        ft_printf("\n No se encontró una posición adecuada para el número %d.\n", stack_a->num);
    //ft_printf("\n así se queda el stack_a al final:\n");
    //ft_print_stack(stack_a);
    //ft_printf("\n así se queda el stack_b al final:\n");
    //ft_print_stack(stack_b);
    ft_free_stack(&stack_a);
    return(0);
}