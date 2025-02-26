/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:20:02 by roo               #+#    #+#             */
/*   Updated: 2025/02/26 15:35:13 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi2(const char *nptr)
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

int	ft_nums_overflow(const char *nptr)
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
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return(-1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
		if (result * sig > INT_MAX || result * sig < INT_MIN)
			return(-1);
	}
	return(0);
}

int ft_find_indexbynum(int num, t_stack *stack)
{
    t_stack *tmp;
    int     i;

    tmp = stack;
    i = 0;
    while(tmp)
    {
        if (tmp->num == num)
            return (i);
        tmp = tmp->next;
        i++;
    }
    return (8324);
}

void ft_min_max(t_vars *var, t_stack *stack)
{
	int i;
	
	i = 0;
	
	var->max_b = INT_MIN;
	var->min_b = INT_MAX;
	while (stack)
	{
		if(stack->num > var->max_b)
		{
			var->max_b = stack->num;
			var->pos_max_b = i;	
		}
		if(stack->num < var->min_b)
		{
			var->min_b = stack->num;
			var->pos_min_b = i;
		}
		stack = stack->next;
		i++;
	}
	
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
