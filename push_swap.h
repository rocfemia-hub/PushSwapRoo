/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:36:16 by roo               #+#    #+#             */
/*   Updated: 2025/01/24 20:54:08 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include "./Helicopter/libft.h"


typedef struct stack_list
{
	int			num;
	struct stack_list	*next;
}					t_stack;

typedef struct variables
{
	int		min_b;
	int		max_b;
	int		price;
	int		tmpprice;
	int		i_stack_a;
	int		i_stack_b;
	int		tmp_i_a;
	int		tmp_i_b;
}	t_vars;


// STACKS

int			ft_print_stack(t_stack *stack_a);
t_stack		*ft_stacknew(int data);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_free_stack(t_stack **stack);

// UTILS

int			ft_atoi2(const char *nptr);
int			ft_nums_overflow(const char *nptr);
int 		ft_find_indexbynum(int num, t_stack *stack);
void 		ft_min_max(t_vars *var, t_stack *stack);

// OPERATIONS

int 		ft_swap(t_stack **stack);
int 		ft_swap_swap(t_stack **stack, t_stack **stack_2);
int 		ft_push(t_stack **stack_dest, t_stack **stack_orig);


int			ft_rotate(t_stack **stack);
int			ft_rotate_rotate(t_stack **stack, t_stack **stack_2);
int			ft_reverse_rotate(t_stack **stack);
int			ft_reverse_reverse(t_stack **stack, t_stack **stack_2);

// PRICES

int			ft_ideal_pos(int number, t_vars *var, t_stack *stack);
void  	  	ft_price_mov(t_stack *stack_a, t_stack *stack_b, t_vars *var);
void  		ft_price(t_stack *stack_a, t_stack *stack_b, t_vars *var);
void    	ft_normal_price(t_stack *stack_a, t_stack *stack_b, t_vars *var);
void    	ft_unusual_price(t_stack *stack_b, t_vars *var);

#endif