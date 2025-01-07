/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:36:16 by roo               #+#    #+#             */
/*   Updated: 2025/01/07 01:00:16 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct stack_list
{
	int			num;
	struct stack_list	*next;
}					t_stack;

t_stack  	*ft_stacknew(int data);
void		ft_stackadd_back(t_stack **lst, t_stack *new);
int			ft_atoi(const char *nptr);
int			print_stack(t_stack *stack_a);

#endif