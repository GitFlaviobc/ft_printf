/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:32:46 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 11:55:15 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_prefix(t_format *t_vars)
{
	ft_putchar('0');
	ft_putchar('x');
	t_vars->total_chars += 2;
}

void	ft_pointer_fill_size(int hex_len, t_format *t_vars)
{
	if (t_vars->size_precision > t_vars->width)
	{
		ft_size_fill(hex_len, t_vars->size_precision, t_vars);
		t_vars->fill = '0';
	}
	else
		ft_size_fill((hex_len + 2), t_vars->width, t_vars);
}

void	ft_pointer_print_checks(const char *hex, int hex_len, t_format *t_vars)
{
	ft_pointer_fill_size(hex_len, t_vars);
	if (t_vars->onleft == 0)
	{
		if (t_vars->fill == '0')
		{
			ft_print_prefix(t_vars);
			ft_print_fill(t_vars->size_fill, t_vars->fill);
		}
		else
		{
			ft_print_fill(t_vars->size_fill, t_vars->fill);
			ft_print_prefix(t_vars);
		}
		ft_print_hex(hex, hex_len);
	}
	else
	{
		ft_print_prefix(t_vars);
		ft_print_hex(hex, hex_len);
		ft_print_fill(t_vars->size_fill, t_vars->fill);
	}
}

size_t	ft_pointer_size(unsigned long int i_arg)
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
	return (hex_len);
}

void	ft_get_pointer(t_format *t_vars, va_list args)
{
	unsigned long int	i_arg;
	int					hex_len;
	char				*hex;

	i_arg = va_arg(args, unsigned long int);
	hex_len = ft_pointer_size(i_arg);
	hex = ft_itohex('x', i_arg, hex_len);
	if (!i_arg && t_vars->precision == 1)
	{
		hex_len = 0;
		*hex = '\0';
	}
	ft_pointer_print_checks(hex, hex_len, t_vars);
	t_vars->total_chars += hex_len;
	free (hex);
}
