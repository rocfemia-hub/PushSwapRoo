/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:55:21 by roo               #+#    #+#             */
/*   Updated: 2025/01/24 20:54:00 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_price_mov(t_stack *stack_a, t_stack *stack_b, t_vars *var)
{
    var->price = INT_MAX;
    var->i_stack_a = 0;
    while(stack_a)
    {
        ft_price(stack_a, stack_b, var);
        var->tmp_i_a++;
        stack_a = stack_a->next;
    }
}

void    ft_price(t_stack *stack_a, t_stack *stack_b, t_vars *var)
{
    var->tmpprice = INT_MAX;
    if(stack_a->num < var->max_b && stack_a->num > var->min_b)
        ft_normal_price(stack_a, stack_b, var);
    else if(stack_a->num > var->max_b || stack_a->num < var->min_b)
        ft_unusual_price(stack_b, var);
    if(var->tmpprice < var->price)
    {
        var->price = var->tmpprice;
        var->i_stack_a = var->tmp_i_a;
        var->i_stack_b = var->tmp_i_b;
    }
}

void    ft_normal_price(t_stack *stack_a, t_stack *stack_b, t_vars *var)
{
    var->tmpprice = 0;
    var->tmp_i_b = ft_ideal_pos(stack_a->num, var, stack_b);
    var->tmpprice = var->tmpprice + var->tmp_i_a + var->tmp_i_b + 1;
}

void    ft_unusual_price(t_stack *stack_b, t_vars *var)
{
    var->tmpprice = 0;
    var->tmp_i_b = ft_find_indexbynum(var->max_b, stack_b);
    var->tmpprice = var->tmpprice + var->tmp_i_a + var->tmp_i_b + 1;
} 

int ft_ideal_pos(int number, t_vars *var, t_stack *stack)
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
        if (number > node->num && number < tmp->num && var->max_b != node->num)
            return (ft_printf("\n el num %d se posiciona entre %d y %d ", number, node->num, tmp->num), i);
        i++;
        if (tmp == ft_stacklast(stack))
        {
            tmp = stack;
            node = node->next;
            continue; //rompe el bucle y lo comienza de nuevo
        }
        tmp = tmp->next;
        node = node->next;
    }
    return (42000);
}
