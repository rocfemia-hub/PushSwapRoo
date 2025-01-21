/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_printf_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:10:16 by roo               #+#    #+#             */
/*   Updated: 2025/01/21 13:11:21 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
int	ft_putstr_fd(char *s, int fd, int result)
{
	if (s == NULL)
	{
		result = result + write(1, "(null)", 6);
		return (result);
	}
	result = result + write(fd, s, ft_strlen(s));
	return (result);
}
int	ft_putnbr_fd(int n, int fd, int result)
{
	if (n == -2147483648)
	{
		result = ft_putstr_fd("-2147483648", fd, result);
	}
	else if (n < 0)
	{
		result = ft_putchar_fd('-', fd, result);
		result = ft_putnbr_fd(-n, fd, result);
	}
	else if (n > 9)
	{
		result = ft_putnbr_fd((n / 10), fd, result);
		result = ft_putnbr_fd((n % 10), fd, result);
	}
	else
		result = ft_putchar_fd((n + '0'), fd, result);
	return (result);
}
int	ft_putchar_fd(char c, int fd, int result)
{
	write(fd, &c, 1);
	result++;
	return (result);
}