/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:03:54 by ccaswell          #+#    #+#             */
/*   Updated: 2021/10/26 19:26:02 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = 0;
	l2 = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc((sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 2)));
	if (!s3)
		return (0);
	while (s1[l1])
	{
		s3[i] = s1[l1];
		i++;
		l1++;
	}
	while (s2[l2])
		s3[i++] = s2[l2++];
	s3[i] = '\0';
	return (s3);
}
