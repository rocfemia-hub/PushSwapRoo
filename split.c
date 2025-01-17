/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:26:39 by roo               #+#    #+#             */
/*   Updated: 2025/01/17 18:27:00 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words_num(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}

static int	ft_lett_words(const char *s, char c, int k)
{
	int	lett_len;
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			lett_len = 0;
			while (s[i] != c && s[i] != '\0')
			{
				lett_len++;
				i++;
			}
			if (k == 0)
				return (lett_len);
			k--;
		}
		i++;
	}
	return (0);
}

static void	ft_free_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static char	**ft_split2(const char *s, char c, char **matrix)
{
	int	i;
	int	j;
	int	word_len;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word_len = ft_lett_words(s, c, k);
			matrix[k] = (char *)malloc((word_len + 1) * sizeof(char));
			if (!matrix[k])
				return (ft_free_free(matrix), NULL);
			j = 0;
			while (s[i] != '\0' && s[i] != c)
				matrix[k][j++] = s[i++];
			matrix[k][j] = '\0';
			k++;
		}
	}
	return (matrix[k] = NULL, matrix);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**matrix;

	words = ft_words_num((char *)s, c);
	matrix = (char **)malloc((words + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix = ft_split2(s, c, matrix);
	return (matrix);
}