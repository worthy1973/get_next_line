/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:52:01 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/05/17 16:43:05 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *buf, char *line)

{
	int	len;

	len = 0;
	if (!buf[len])
		return (NULL);
	while (buf[len] && buff[len] !='\n')
		len++;
	if (buf[len] == '\n')
		len++;
	line = ft_calloc(len + 1, size_of(char));
	if (!line)
		return (NULL);
	len = 0;
	while (buf[len] && buf[len] != '\n')
	{
		line[len] == buf[len]
		len++;
	}
	if (buf[len] == '\n')
		line[len] = '\n';
	return (line);
}	

void	*ft_read(int fd,char *buf, int bytes)

{
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (ft_free(&buf,&tmp);
	while (bytes > 0)
	{
		bytes = read(fd,tmp, BUFFER_SIZE);
		if (bytes < 0)
	   		return (ft_free (&buf, &tmp);
		tmp[bytes] = '\0';
		buf = ft_protect_join(buf,tmp);
		if (!buf)
		 	return (NULL);
		if (ft_strchr(tmp, '\n'))
			break;

	}	
	ft_free (&tmp, NULL); 
	return (buf);
}
