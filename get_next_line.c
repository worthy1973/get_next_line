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
void	*ft_protect_join(char *s1, char *s2)
{
	char	*tmp;

	if (!s1)
		return (ft_strdup(s2));
	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	ft_free(&s1, NULL);
	return (tmp);
}
void 	*ft_free(char **s1, char **s2) // REVISAR ESTA FUNCION
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}
char	*ft_strdup(char *s1)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	return (tmp);
}	

int	main()
{
	printf(
