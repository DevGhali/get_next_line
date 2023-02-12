/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabd-el- <gabd-el-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:51:19 by gabd-el-          #+#    #+#             */
/*   Updated: 2023/02/12 19:35:56 by gabd-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;

	x = 0;
	if (dstsize != 0)
	{
		while (x < dstsize - 1 && src[x] != '\0')
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
}

char	*ft_strjoin(char *stati, char *buf)
{
	char	*ret;
	size_t	len;

	if (!stati)
	{
		stati = (char *)malloc(sizeof(char) * 1);
		if (stati == NULL)
			return (NULL);
		stati[0] = '\0';
	}
	if (!buf || !stati)
		return (free(stati), NULL);
	len = ft_strlen(stati) + ft_strlen(buf);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, stati, ft_strlen(stati) + 1);
	ft_strlcpy(&ret[ft_strlen(stati)], buf, ft_strlen(buf) + 1);
	return (free(stati), ret);
}
