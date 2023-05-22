/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:11:08 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/05/22 17:16:15 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *str);

char	*ft_free(char **buff, char **buff2);

char	*ft_strjoin(char *str1, char *str2);

char	*ft_strchr(const char *s, int c);

char	*ft_next_line(char *buf, char *line);

char	*ft_next_buff(char *buf);

char	*ft_protec_join(char *buffer, char *reader);

char	*ft_read_fd(int fd, char *buf, int bytes);

char	*get_next_line(int fd);

#endif
