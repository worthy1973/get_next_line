/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:57:48 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/05/18 17:11:33 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)

{
	void	*memory;
	int		asign;
	int		i;

	asign = count * size;
	memory = malloc(asign);
	if (!memory)
		return (0);
	i = 0;
	while (i < asign)
		((char *)memory)[i++] = 0;
	return (memory);
}
/*La función "calloc" en C se utiliza para asignar memoria dinámica 
 * y se inicializa a cero. La función toma dos argumentos: el número 
 * de elementos que se deben asignar y el tamaño en bytes de cada elemento. 
 * En el código proporcionado, la función "ft_calloc" intenta replicar la 
 * funcionalidad de la función "calloc" estándar.El código comienza definiendo 
 * un puntero void llamado "memory" y dos variables enteras "asign" e "i". Luego, 
 * se asigna la cantidad de memoria necesaria para almacenar "count" elementos, 
 * cada uno de "size" bytes. Si no se puede asignar suficiente memoria, la función 
 * devuelve NULL. Después de asignar la memoria, el código itera a través de cada 
 * byte y establece su valor en cero utilizando un puntero de carácter.*/

size_t	ft_strlen(const char *str)

{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len)
}
/* La funcion strlen en C se utiliza para calcular la longitud de una cadena
 * de caracteres. Toma como argumento un puntero a una cadena de caracteres
 * (const chr *) y devuelve el numero de caracteres en esa cadena, excluyendo
 * el caracter nulo final ('\0')
 * Este codigo proporcionado calcula la longitud de una cadena de caracteres
 * (str) utilizando un bucle while. Comienza inicializando la variable 'len"
 * a cero. Luego, entra en un bucle while que se ejecuta mientras el caracter
 * actual al que apunta el puntero "str" no sea el caracter nulo (\'0'). En cada 
 * iteracion, incrementa "len" y avanza al siguiente caracter de la cadena.
 * cuando se alcanza el caracter nulo, se sale del bucle y se devuelve el valor de 
 * "len", que representa la longitud de la cadena*/

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
	return(NULL);
}	
/* La funcion free en C se utiliza para liberar la memoria que fue previamente
 * asignada dinamicamene utilizando las funciones malloc, calloc o realoc. Cuando ya 
 * no necesitamos utilizar una region de memoria asignada dinamicamente, podemos 
 * llamar a la funcion free para liberar esa memoria y hacerla disponible nuevamente
 * para su reutilizacion.
 * En este codigo, se verifica si los punteros buff y buff2 existen y apuntan a 
 * direcciones de memoria validas. Si es as, se utiliza la funcion free para liberar
 * la memoria a la que apuntan y se establecen los punteros a NULL para evitar acceder
 * a la memoria liberada.
 * Finalmente, la funcion devuelve NULL*/

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int	i;
	int	j;

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
	new_str[j] != ('\0');
	return (new_str);
}
/*La funcion strjoin en C se utiliza para concatenar dos cadenas de caracteres
 * y crear una nueva cadena que contenga ambas.
 * En la funcion se toman dos punteros a caracteres str1 y str2. La funcion utliza
 * la funcion malloc para asignar memoria para la nueva cadena new_str que contendra
 * la concatenacion de las dos cadenas.
 * Se realiza la verificacion de que la asignacion de memoria ha sido exitosa !new_str
 * Luego, se itera a traves de la cadena str1 y se copian sus caracteres a new_str hasta
 * que se alcance el caracter nulo '\0'. Luego se hace lo mismo con la cadena str2
 * Finalmente, se agrega el caracter nulo '\0' al final de new_str para asegurarse de que
 * sea una cadena valida y se devuelve "new_str"*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL)
}
/*La funcion strchr en C se utiliza para buscar la primera aparición de un 
 * caracter especifico en una cadena de caracteres.
 * En esta funcion se toman dos argumentos: un puntero a una cadena de caracteres 's'y un entero c
 * La funcion busca la primera aparicion del caracter c en la cadena s
 * Dentro del bucle 'while' se verifica si el caracter actual al que apunta s es
 * igual al caracter c. Si se encuentra una coincidencia, se devuelve un punteroa la ubicación
 * de ese caracter en la cadena s utlizando un casting a (char *)
 *  
