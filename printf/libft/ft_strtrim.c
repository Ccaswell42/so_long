/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:17:34 by ccaswell          #+#    #+#             */
/*   Updated: 2021/10/26 19:07:37 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	prov(char a, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static size_t	strcount(char const *s1, char const *set)
{
	int		i;
	size_t	x;
	int		z;

	i = 0;
	x = 0;
	while ((prov(s1[i], set) == 1) && s1[i])
	{
		i++;
		x++;
	}
	z = ft_strlen(s1);
	while (prov(s1[z - 1], set) == 1 && z > i)
	{
		x++;
		z--;
	}
	return (x);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s2;
	size_t	x;
	size_t	a;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	x = strcount(s1, set);
	s2 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) - x + 1));
	if (!s2)
		return (0);
	while ((prov(s1[i], set) == 1) && s1[i])
		i++;
	a = i;
	while (i < ft_strlen(s1) - x + a)
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
