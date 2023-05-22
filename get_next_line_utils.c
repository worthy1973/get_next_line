/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:56:38 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/05/22 17:17:36 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)

{
	void	*memory;
	size_t	asign;
	size_t	i;

	asign = count * size;
	memory = malloc(asign);
	if (!memory)
		return (0);
	i = 0;
	while (i < asign)
		((char *)memory)[i++] = 0;
	return (memory);
}

size_t	ft_strlen(const char *str)

{
	size_t	len;

	len = 0;
	while (str[len])
			len++;
	return (len);
}

char	*ft_free(char **buff, char **buff2)

{
	if (buff && *buff)
	{
		free(*buff);
		*buff = NULL;
	}
	if (buff2 && *buff2)
	{
		free(*buff2);
		*buff2 = NULL;
	}
	return (NULL);
}	

char	*ft_strjoin(char *str1, char *str2)

{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	while (str1[i])
		new_str[j++] = str1[i++];
	i = 0;
	while (str2[i])
		new_str[j++] = str2[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)

{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
