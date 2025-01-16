/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:15:07 by roo               #+#    #+#             */
/*   Updated: 2025/01/16 21:10:21 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // función prohibida cuidao

int ft_print_stack(t_stack *stack_a)
{
    printf("%d\n", stack_a->num); // función prohibida cuidao!!!
    while(stack_a->next != NULL)
    {
        stack_a = stack_a->next;
        printf("%d\n", stack_a->num); // función prohibida cuidao!!!
    }
    return(stack_a->num);
}

t_stack  *ft_stacknew(int data)
{
    t_stack  *new;
    
    new = (t_stack *)malloc(sizeof(t_stack));
    if(!new)
        return(NULL);
    new->num = data;
    new->next = NULL;
    return(new);
}

void    ft_stackadd_back(t_stack **stack, t_stack *new)
{
    t_stack  *node;
    
    node = *stack;
    if(!node)
    {
        *stack = new;
        return ;
    }
    while(stack && node->next != NULL)
    {
        node = node->next;       
    }
    node->next = new;
}

/*t_stack *findprev(t_stack *stack_a, int num)
{
    while(stack_a->next && stack_a->next->num != num)
    {
        stack_a = stack_a->next;
    }
    return (stack_a);
}*/
