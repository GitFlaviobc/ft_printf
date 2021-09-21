/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 08:26:12 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 11:59:49 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*u_src;
	unsigned char	u_c;

	u_src = (unsigned char *)src;
	u_c = (unsigned char)c;
	if (*u_src == u_c)
		return ((char *)src);
	while (*u_src)
	{
		if (*u_src == u_c)
			return ((char *)u_src);
		u_src++;
	}
	if (u_c == '\0')
		return ((char *)u_src);
	return (0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (len == 0)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && len-- > 1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str != '\0')
		str++;
	return (str - s);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_cpy;
	unsigned const char	*src_cpy;

	dest_cpy = dest;
	src_cpy = src;
	if (dest == src)
		return (dest);
	while (len-- > 0)
	{
		*dest_cpy++ = *src_cpy++;
	}
	return (dest);
}
