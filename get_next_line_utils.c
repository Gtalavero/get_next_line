/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:49:14 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/23 18:17:11 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Return the number of characters of a char string.
*/

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** Returns a pointer to the first occurrence of the character 'c' in the string 's'
** 
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

/*
** Returns a new string result of the concatenation of 's1' and 's2'
** 
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(s = (char*)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = 0;
	return (s);
}

/*
** Returns a pointer to a new string obtained duplicating "s"
*/

char		*ft_strdup(char *s)
{
	char	*s2;
	int		i;
	int		size;

	size = ft_strlen(s);
	i = 0;
	s2 = (char*)malloc(sizeof(char) * size + 1);
	if (s2 == NULL)
	{
		return (s2);
	}
	while (i <= size)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}

/*
** Allocates (with malloc) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

