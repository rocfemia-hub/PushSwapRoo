/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:36:16 by roo               #+#    #+#             */
/*   Updated: 2025/01/21 02:07:33 by roo              ###   ########.fr       */
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

// STACKS

int			ft_print_stack(t_stack *stack_a);
t_stack		*ft_stacknew(int data);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_free_stack(t_stack **stack);

// UTILS

int			ft_atoi(const char *nptr);
int			ft_nums_overflow(const char *nptr);


static int	ft_words_num(const char *s, char c);
static int	ft_lett_words(const char *s, char c, int k);
static void	ft_free_free(char **matrix);
static char	**ft_split2(const char *s, char c, char **matrix);
char		**ft_split(const char *s, char c);

// OPERATIONS

int 		ft_swap(t_stack **stack);
int 		ft_swap_swap(t_stack **stack, t_stack **stack_2);
int 		ft_push(t_stack **stack_dest, t_stack **stack_orig);


int			ft_rotate(t_stack **stack);
int			ft_rotate_rotate(t_stack **stack, t_stack **stack_2);
int			ft_reverse_rotate(t_stack **stack);
int			ft_reverse_reverse(t_stack **stack, t_stack **stack_2);

// PRICES
int			ft_idealpos(int number, t_stack *stack);


#endif