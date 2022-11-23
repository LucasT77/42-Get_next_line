/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:17:40 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/23 17:07:21 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*bigstr;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
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
	free(s1);
	return (bigstr);
}

/*size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
*/