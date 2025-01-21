/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:55:21 by roo               #+#    #+#             */
/*   Updated: 2025/01/21 02:34:24 by roo              ###   ########.fr       */
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
    while (node)
    {
        tmp = stack;
        if (tmp && tmp->next) 
            tmp = tmp->next;
        if (number > node->num && number < tmp->num)
            return (i);
        i++;
        node = node->next;
    }
    return (42000);
}