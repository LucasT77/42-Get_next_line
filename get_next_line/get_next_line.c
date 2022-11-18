/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:17:17 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/17 14:17:21 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (*str != '\n')
	{
		line[i] = *str;
		i++;
		*str++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_file(int fd, char *str)
{
	char	*aux;
	ssize_t	return_read;

	aux = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	return_read = read(fd, aux, BUFFER_SIZE);
	str = ft_strjoin(str, aux);
	free(aux);
	if (ft_strchr(str,'\n') == NULL)
		read_file(fd, str);
	else
		return ;
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (!str)
		str = ft_calloc(1, 1);
	str = read_file(fd, str);
	line = get_line(str);
	return (line);
}