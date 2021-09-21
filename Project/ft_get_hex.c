/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:35:07 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 11:55:05 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(const char *hex, int hex_len)
{
	while (hex_len > 0)
	{
		ft_putchar(*hex);
		hex++;
		hex_len--;
	}
}

void	ft_hex_print_checks(const char *hex, int hex_len, t_format *t_vars)
{
	if (t_vars->onleft == 0)
		ft_hex_on_right(hex, hex_len, t_vars);
	else
		ft_hex_on_left(hex, hex_len, t_vars);
}

size_t	ft_hex_size(unsigned long int i_arg)
{
	unsigned long int	hex_len;

	hex_len = 0;
	if (i_arg == 0)
		return (1);
	while (i_arg)
	{
		i_arg = i_arg / 16;
		hex_len++;
	}
	if (hex_len > 8)
		hex_len = 8;
	return (hex_len);
}

char	*ft_itohex(char c, unsigned long int i_arg, int hex_len)
{
	char	*ret_hex;

	ret_hex = (char *) malloc ((hex_len + 1) * sizeof(char));
	ret_hex[hex_len] = '\0';
	while (hex_len--)
	{
		if (i_arg % 16 >= 10 && c == 'X')
			ret_hex[hex_len] = (i_arg % 16) - 10 + 'A';
		else if (i_arg % 16 >= 10)
			ret_hex[hex_len] = (i_arg % 16) - 10 + 'a';
		else
			ret_hex[hex_len] = (i_arg % 16) + '0';
		i_arg = i_arg / 16;
	}
	return (ret_hex);
}

void	ft_get_hex(char c, t_format *t_vars, va_list args)
{
	unsigned int	i_arg;
	int				hex_len;
	char			*hex;

	i_arg = va_arg(args, unsigned int);
	hex_len = ft_hex_size(i_arg);
	hex = ft_itohex(c, i_arg, hex_len);
	hex_len = ft_check_hex_zero(&hex, hex_len);
	ft_hex_print_checks(hex, hex_len, t_vars);
	t_vars->total_chars += hex_len;
	free(hex);
}
