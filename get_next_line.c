/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:35:37 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/03/07 12:39:04 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		get_next_line(int fd, char **line)
{
    static char	*str[4096];
    char		*buf;
    int			bytes;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes] = '\0';
        if (!str[fd])
            str[fd] = ft_strdup(buf);
        else
            str[fd] = ft_strjoin(str[fd], buf);
        if (ft_strchr(buf, '\n'))
            break ;
    }
    free(buf);
    if (bytes < 0)
        return (-1);
    else if (bytes == 0 && (!str[fd] || str[fd][0] == '\0'))
    {
        *line = ft_strdup("");
        return (0);
    }
    return (get_line(&str[fd], line));
}
