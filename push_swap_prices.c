/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:55:21 by roo               #+#    #+#             */
/*   Updated: 2025/01/21 17:31:38 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_idealpos(int number, t_stack *stack)
{
    int     i;
    t_stack *node;
    t_stack *tmp;

    i = 0;
    node = stack;
    tmp = stack;
    while (node)
    {
        if (node->num == stack->num)
            tmp = ft_stacklast(stack);
        if (number < node->num && number > tmp->num)
            return (ft_printf("\n el num %d se posiciona entre %d y %d ", number, node->num, tmp->num), i);
        i++;
        if (tmp == ft_stacklast(stack))
        {
            tmp = stack;
            node = node->next;
        }
        else
            tmp = tmp->next;
    }
    return (42000);
}