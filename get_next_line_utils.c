/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:22:22 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/03/07 16:35:58 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strdup(const char *s1)
{
    char	*str;
    int		i;

    i = 0;
    if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*str;
    int		i;
    int		j;

    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (NULL);
    if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    free((char *)s1);
    return (str);
}

char	*ft_strchr(const char *s, int c)
{
    int		i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return ((char *)s + i);
        i++;
    }
    if (s[i] == c)
        return ((char *)s + i);
    return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*str;
    size_t	i;

    i = 0;
    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (s[start] && i < len)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}

