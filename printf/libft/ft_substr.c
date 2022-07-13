/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:00:24 by ccaswell          #+#    #+#             */
/*   Updated: 2021/10/26 19:23:13 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s2 = (char *)malloc(sizeof(*s) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < start && s[i])
		i++;
	if (s[i] == '\0')
		s2[j] = '\0';
	while (j < len && s[i])
		s2[j++] = s[i++];
	s2[j] = '\0';
	return (s2);
}
