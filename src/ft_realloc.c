/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:18:48 by nlavrine          #+#    #+#             */
/*   Updated: 2019/01/21 18:18:48 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_realloc(char *ptr, size_t prev_size, size_t new_size)
{
	char	*new;

	new = NULL;
	if (prev_size < new_size)
	{
		new = (char *)ft_memalloc(new_size);
		if (ptr && *ptr)
		{
			new = (char *)ft_memmove(new, ptr, prev_size);
			ft_memdel((void **)(&ptr));
		}
		return (new);
	}
	return (ptr);
}

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s2 || !n)
		return (s1);
	len = ft_strlen(s1);
	while (i < n)
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst >= src)
		while (n)
		{
			n--;
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		}
	else
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	return (dst);
}
