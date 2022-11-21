/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:17:17 by luaraujo          #+#    #+#             */
/*   Updated: 2022/11/21 18:10:05 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*delsubstr(char *str, size_t indx1, size_t indx2)
{
	size_t	i;
	char	*result;

	if (indx1 > indx2)
	{
		i = indx1;
		indx1 = indx2;
		indx2 = i;
	}
	i = (ft_strlen(str) + 1) - (indx2 - indx1 + 1);
	result = malloc(sizeof(char) * i);
	i = 0;
	while (i < indx1)
	{
		result[i] = str[i];
		i++;
	}
	indx2++;
	while (str[indx2])
		result[i++] = str[indx2++];
	result[i] = '\0';
	return (result);
}

static char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
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
	if (return_read == -1)
		return (NULL);
	if (return_read == 0 && str == NULL)
		return (NULL);
	if (ft_strchr(str, '\n') == NULL && return_read != 0)
	{
		aux = ft_calloc(1, 1);
		return (ft_strjoin(str, read_file(fd, aux)));
	}
	else
		return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!str)
		str = ft_calloc(1, 1);
	str = read_file(fd, str);
	if (str == NULL)
		return (NULL);
	line = get_line(str);
	i = 0;
	while (str[i] != '\n')
		i++;
	str = delsubstr(str, 0, i);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("../test1.txt", O_RDONLY);
	i = 0;
	while (i < 100)
	{
		line = get_next_line(fd);
		printf("line[%d]: %s\n", (i + 1), line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
