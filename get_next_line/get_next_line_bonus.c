/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:54:59 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/25 12:17:14 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*delsubstr(char *str)
{
	size_t	i;
	size_t	n;
	size_t	len;
	char	*result;

	len = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	result = malloc(sizeof(char) * (len + 1 - i));
	n = 0;
	i++;
	while (str[i])
		result[n++] = str[i++];
	result[n] = '\0';
	free(str);
	return (result);
}

static char	*get_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_file(int fd, char *str)
{
	char	*aux;
	ssize_t	return_read;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	return_read = 1;
	while (ft_strchr(str, '\n') == NULL && return_read != 0)
	{
		return_read = read(fd, aux, BUFFER_SIZE);
		if (return_read == -1)
		{
			free(aux);
			return (NULL);
		}
		aux[return_read] = '\0';
		str = ft_strjoin(str, aux);
	}
	free(aux);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[2000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = delsubstr(str[fd]);
	return (line);
}

/*
int	main(void)
{
	int		fd1;
	char	*line1;
	int		fd2;
	char	*line2;
	int		i;

	fd1 = open("../test1.txt", O_RDONLY);
	fd2 = open("../test2.txt", O_RDONLY);
	i = 0;
	while (i < 25)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		printf("test1_line[%d]: %s\n", (i + 1), line1);
		printf("test2_line[%d]: %s\n", (i + 1), line2);
		free(line1);
		free(line2);
		i++;
	}
	close(fd1);
	return (0);
}
*/