/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_con.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:42:51 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/06 11:23:20 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	src_len;

	if (src == 0 || dest == 0)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < len)
		ft_memcpy(dest, src, src_len + 1);
	else if (len != 0)
	{
		ft_memcpy(dest, src, len - 1);
		dest[len - 1] = '\0';
	}
	return (src_len);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = (char *) malloc (len * sizeof(char));
	if (ptr)
	{
		ft_strlcpy(ptr, str, len);
		return (ptr);
	}
	return (0);
}

char	*ft_itoa(int n, int n_size)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *) malloc ((n_size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[n_size] = '\0';
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	while (n_size-- > i)
	{
		str[n_size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
