/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:55:39 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/25 11:58:38 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
			break ;
		}
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)s + i);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	n;
	char	*bigstr;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (0);
	bigstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!bigstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		bigstr[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
		bigstr[i++] = s2[n++];
	bigstr[i] = '\0';
	free(s1);
	return (bigstr);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, (nmemb * size));
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*aux;

	i = 0;
	aux = s;
	while (i < n)
	{
		aux[i] = c;
		i++;
	}
	return (s);
}
