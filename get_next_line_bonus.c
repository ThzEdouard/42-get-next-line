/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:45:37 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/27 21:50:06 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*trash[1024];
	char		*line;
	int			byte;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	byte = 1;
	line = NULL;
	get_read_file(fd, &trash[fd], &byte);
	if (trash[fd] == NULL)
		return (NULL);
	line = ft_substr(trash[fd], 0, ft_lenline(trash[fd]));
	trash[fd] = get_save_trash(trash[fd], 0);
	if (line[0] == 0 && trash[fd] == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_save_trash(char *trash, int x)
{
	char	*save_trash;
	int		i;

	i = 0;
	while (trash[i] && trash[i] != '\n')
		i++;
	if (!trash[i])
		return (free (trash), NULL);
	save_trash = malloc(sizeof(char) * (ft_strlen(trash) - i + 1));
	if (!save_trash)
		return (free (trash), NULL);
	i++;
	while (trash[i + x])
	{
		save_trash[x] = trash[i + x];
		x++;
	}
	save_trash[x] = 0;
	free(trash);
	return (save_trash);
}

void	get_read_file(int fd, char **trash, int *byte_ptr)
{
	char	*buf;

	if (!*trash)
	{
		*trash = malloc(sizeof(char) * 1);
		if (!*trash)
			return ;
		*trash[0] = 0;
	}
	while (!(ft_newline(*trash)) && *byte_ptr)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		*byte_ptr = read(fd, buf, BUFFER_SIZE);
		if (*byte_ptr <= 0)
		{
			free(buf);
			return ;
		}
		buf[*byte_ptr] = 0;
		*trash = ft_strjoin(*trash, buf);
		free(buf);
	}
}
