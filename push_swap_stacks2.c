/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:38:51 by roo               #+#    #+#             */
/*   Updated: 2025/02/03 20:39:51 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*aux;

	node = *stack;
	while (node)
	{
		aux = node->next;
		free(node);
		node = aux;
	}
}

void    ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *lst;
   		*lst = new;
	}  
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
