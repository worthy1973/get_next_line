/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:51:48 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/05/22 20:35:52 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_next_line(char *buf, char *line)
{
	int	len;

	len = 0;
	if (!buf[len])
		return (NULL);
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] == '\n')
		len++;
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (buf[len] && buf[len] != '\n')
	{
		line[len] = buf[len];
		len++;
	}
	if (buf[len] == '\n')
		line[len] = '\n';
	return (line);
}

char	*ft_next_buff(char *buf)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (!buf[len])
		return (ft_free(&buf, NULL));
	new = ft_calloc(ft_strlen(buf) - len + 1, sizeof(char));
	if (!new)
		return (ft_free(&buf, NULL));
	len++;
	i = 0;
	while (buf[len])
		new[i++] = buf[len++];
	ft_free(&buf, NULL);
	return (new);
}

char	*ft_protec_join(char *buffer, char *reader)
{	
	char	*temp;

	temp = ft_strjoin(buffer, reader);
	if (!temp)
		return (ft_free(&buffer, &reader));
	ft_free(&buffer, 0);
	return (temp);
}

char	*ft_read_fd(int fd, char *buf, int bytes)
{
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (ft_free(&buf, &tmp));
	while (bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(&buf, &tmp));
		tmp[bytes] = '\0';
		buf = ft_protec_join(buf, tmp);
		if (!buf)
			return (NULL);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	ft_free(&tmp, NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	int			bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buf)
			ft_free(&buf, NULL);
		return (NULL);
	}
	if (!buf)
		buf = ft_calloc(1, 1);
	if (!buf)
		return (ft_free(&buf, NULL));
	bytes = 1;
	buf = ft_read_fd(fd, buf, bytes);
	if (!buf)
		return (NULL);
	line = ft_next_line(buf, line);
	if (!line || *line == '\0')
		return (ft_free(&buf, &line));
	buf = ft_next_buff(buf);
	return (line);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char	*line;
	//char *str= "hola\nmundo";
	int i = 0;
	int j = 0;

	line = NULL;
	if (fd < 0)
	{
		printf("Error!!-->memory allocation\n");
		return (0);
	}
	while (j==0)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("line [%d] content :%s\n\n", i++, line);
	}
	//line = ft_next(str);
	close (fd);
	return (0);
}
