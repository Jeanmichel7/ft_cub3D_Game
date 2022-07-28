/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:29:10 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/20 02:51:12 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read(int fd, char *buffer)
{
	int	ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
	{
		free(buffer);
		return (-1);
	}
	buffer[ret] = '\0';
	return (ret);
}

char	*ft_calloc_line(char *buffer, long size)
{
	long	i;

	i = 0;
	buffer = malloc(sizeof(char) * (size + 1));
	if (buffer == NULL)
		return (NULL);
	while (i < size + 1)
		buffer[i++] = '\0';
	return (buffer);
}

char	*ft_check_retour(int ret, char *buffer, char *line)
{
	if (ret == 0 && line)
		return (line);
	else if (ret < 1)
		return (NULL);
	else if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		return (line);
	}
	else if (ret > 0 && buffer && buffer[0] != '\0')
	{
		buffer = update_buffer(buffer);
		return (line);
	}
	return (line);
}

char	*ft_check_buffer_line(char *buffer)
{
	if (ft_strlen(buffer) != BUFFER_SIZE)
	{
		free(buffer);
		buffer = ft_calloc_line(buffer, BUFFER_SIZE);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			ret;

	if (fd < 0 || fd >= 1000)
		return (NULL);
	if (buffer[fd] && buffer[fd][0] == '\0')
		return (ft_check_retour(0, buffer[fd], NULL));
	ret = ft_check_buffer_empty(&buffer[fd], fd);
	if (ret == -1 || ret == 0)
		return (NULL);
	line = malloc(sizeof(char));
	line[0] = '\0';
	line = ft_strconcat(line, buffer[fd]);
	while (!(ft_is_buffer_end_line(buffer[fd])) && ret > 0)
	{
		buffer[fd] = ft_check_buffer_line(buffer[fd]);
		ret = ft_read(fd, buffer[fd]);
		line = ft_strconcat(line, buffer[fd]);
	}
	if (ret < 1)
		return (ft_check_retour(ret, buffer[fd], line));
	else
		buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
