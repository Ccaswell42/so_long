/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:45:49 by ccaswell          #+#    #+#             */
/*   Updated: 2021/10/27 14:26:25 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	if (!s[i])
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			x++;
			while (s[i] == c && s[i])
				i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	i--;
	if (s[i] == c && s[i])
		x--;
	return (x);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**free_all(char **s, int j)
{
	while (j--)
		free(s[j]);
	free (s);
	return (NULL);
}

static char	**ft_func(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s || !str)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, word_len(s + i, c));
			if (str[j] == NULL)
				return (free_all(str, j));
			j++;
			while (s[i] != c && s[i])
				i++;
			continue ;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!str)
		return (NULL);
	str = ft_func(s, c, str);
	if (!str)
		return (NULL);
	return (str);
}
