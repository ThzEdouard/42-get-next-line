/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:45:34 by eflaquet          #+#    #+#             */
/*   Updated: 2022/05/27 21:58:31 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	get_read_file(int fd, char **trash, int *byte_ptr);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_save_trash(char *trash, int len_line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_newline(char *str);
int		ft_lenline(char *str);

#endif