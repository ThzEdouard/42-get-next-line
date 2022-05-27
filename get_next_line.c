/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:09:47 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/27 20:48:43 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*trash;
	char		*line;
	int			byte;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	byte = 1;
	line = NULL;
	get_read_file(fd, &trash, &byte);
	line = ft_substr(trash, 0, ft_lenline(trash));
	trash = get_save_trash(trash, 0);
	if (line[0] == 0 && trash == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_save_trash(char *trash, int x)
{
	char	*save_trash;
	int		new_line;
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
	char	buf[BUFFER_SIZE + 1];
	char	*save_trash;

	if (!*trash)
	{
		*trash = malloc(sizeof(char) * 1);
		if (!*trash)
			return ;
		*trash[0] = 0;
	}
	while (!(ft_newline(*trash)) && *byte_ptr)
	{
		*byte_ptr = read(fd, buf, BUFFER_SIZE);
		if (*byte_ptr <= 0)
			return ;
		buf[*byte_ptr] = 0;
		*trash = ft_strjoin(*trash, buf);
	}
}
