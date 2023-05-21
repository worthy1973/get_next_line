/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dlopez-i@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:35:34 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/05/21 12:43:38 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//Aqui se declaran las funciones que se van a utilizar en el programa
//Asignar memoria dinamica
void	*ft_calloc(size_t count, size_t size);
//Calcular la longitud de una cadena de caracteres
size_t	ft_strlen(const char *str);
//Libera la memoria de dos cadenas de caracteres
char	*ft_free(char **buff, char **buff2);
//Concatena dos cadenas de caracteres
char	*ft_strjoin(char *str1, char *str2);
//Copia una cadena de caracteres
char	*ft_strchr(const char *s, int c);
//Muestra la siguiente linea de un archivo
int		get_next_line(int fd, char **line);

#endif 
