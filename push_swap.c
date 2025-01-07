/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:32:42 by roo               #+#    #+#             */
/*   Updated: 2025/01/07 16:16:57 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //cuidado función prohivida

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
        //int value = ft_atoi(argv[i]);
        //printf("Adding value to stack_a: %d\n", value);
        //ft_stackadd_back(&stack_a, ft_stacknew(value));
        ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
    }
    return(print_stack(stack_a), 0);
}