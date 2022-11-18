/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:17:40 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/17 14:17:43 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	aux;

	aux = nmemb * size;
	if (nmemb != aux / size)
		return (NULL);
	result = malloc(aux);
	if (!result)
		return (NULL);
	ft_bzero(result, aux);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*bigstr;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	bigstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!bigstr)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		bigstr[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		bigstr[i] = s2[i - len1];
		i++;
	}
	bigstr[i] = '\0';
	return (bigstr);
}

