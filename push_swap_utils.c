/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:20:02 by roo               #+#    #+#             */
/*   Updated: 2025/01/07 01:05:36 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void				ft_stackadd_back(t_stack **lst, t_stack *new)
{
    t_stack  *node;
    
    node = *lst;
    if(!node)
    {
        *lst = new;
        return ;
    }
    while(lst && node->next != NULL)
    {
        node = node->next;       
    }
    node->next = new;
}
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sig;
	long	result;

	i = 0;
	sig = 1;
	result = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		sig = sig * -1;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		if (result * sig > INT_MAX)
			return (-1);
		if (result * sig < INT_MIN)
			return (0);
		i++;
	}
	return (result * sig);
}
int print_stack(t_stack *stack_a)
{
    printf("%d\n", stack_a->num); // función prohibida cuidado
    while(stack_a->next != NULL)
    {
        stack_a = stack_a->next;
        printf("%d\n", stack_a->num); // función prohibida cuidado
    }
    return(stack_a->num);
}