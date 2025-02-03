/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:15:07 by roo               #+#    #+#             */
/*   Updated: 2025/01/27 21:52:02 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_print_stack(t_stack *stack)
{
    if(!stack)
        return(0);
    ft_printf("%d\n", stack->num);
    while(stack->next != NULL)
    {
        stack = stack->next;
        ft_printf("%d\n", stack->num);
    }
    return(stack->num);
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
t_stack		*ft_stacklast(t_stack *stack)
{
    while(stack && stack->next != NULL)
    {
        stack = stack->next;
    }
    return(stack);
}

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

int ft_stacksize(t_stack *stack)
{
    int i;
    
    i = 0;
    while(stack)
    {
        stack = stack->next;
        i++;
    }
    return(i);
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

/*t_stack *findprev(t_stack *stack_a, int num)
{
    while(stack_a->next && stack_a->next->num != num)
    {
        stack_a = stack_a->next;
    }
    return (stack_a);
}*/
