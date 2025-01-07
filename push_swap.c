/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:32:42 by roo               #+#    #+#             */
/*   Updated: 2025/01/07 19:16:28 by roo              ###   ########.fr       */
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
    return(ft_print_stack(stack_a), 0);
}