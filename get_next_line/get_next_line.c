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

static char	*delsubstring(char *str, size_t indx1, size_t indx2)
{
	
}

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
		str++;
	}
	line[i] = '\0';
	printf("str: %s\n", str);
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
	if (ft_strchr(str,'\n') == NULL && return_read != 0)
		return ft_strjoin(str, read_file(fd, str));
	else
	{
		return str;
	}
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (!str)
		str = ft_calloc(1, 1);
	str = read_file(fd, str);
	line = get_line(str);
	printf("str main: %s\n", str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("../test1.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("line[%d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}