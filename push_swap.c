/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:32:42 by roo               #+#    #+#             */
/*   Updated: 2025/01/16 23:20:44 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     i;
    
    stack_a = NULL;
    stack_b = NULL;
    i = 0;
    while (argv[++i])
    {
        ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
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
    
    //printf("\n así empieza el stack_a:\n"); //función prohibida cuidao!!!
    //ft_print_stack(stack_a);
    //printf("\n así empieza el stack_b:\n"); //función prohibida cuidao!!!
    //ft_print_stack(stack_b);
    
    //printf("\n así se queda el stack_a al final:\n"); //función prohibida cuidao!!!
    //ft_print_stack(stack_a);
    //printf("\n así se queda el stack_b al final:\n"); //función prohibida cuidao!!!
    //ft_print_stack(stack_b);
    return(0);
}