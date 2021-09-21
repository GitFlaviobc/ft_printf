/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:26:04 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 10:31:42 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_hex_zero(char **hex, int hex_len)
{
	char	*str_check;
	char	*new_hex;
	int		i;

	str_check = (char *) malloc (9 * sizeof(char));
	i = 0;
	new_hex = *hex;
	while (i < 8)
	{
		str_check[i] = '0';
		i++;
	}
	str_check[i] = '\0';
	if (!ft_strncmp(new_hex, str_check, hex_len))
	{
		new_hex[1] = '\0';
		hex_len = 1;
	}
	*hex = new_hex;
	free(str_check);
	return (hex_len);
}

int	ft_hex_is_zero(int hex_len, t_format *t_vars)
{
	t_vars->total_chars--;
	return (hex_len = 0);
}

void	ft_check_prec_and_width(int hex_len, t_format *t_vars)
{
	if (t_vars->size_precision > t_vars->width || t_vars->size_precision == 0)
		ft_size_fill(t_vars->size_precision + hex_len, t_vars->width, t_vars);
	else
	{
		if (t_vars->size_precision > hex_len)
			ft_size_fill(t_vars->size_precision, t_vars->width, t_vars);
		else
			ft_size_fill(hex_len, t_vars->width, t_vars);
	}
}

void	ft_hex_on_right(const char *hex, int hex_len, t_format *t_vars)
{
	if (t_vars->precision == 0)
	{
		ft_size_fill(hex_len, t_vars->width, t_vars);
		ft_print_fill(t_vars->size_fill, t_vars->fill);
		ft_print_hex(hex, hex_len);
	}
	else
	{
		if (t_vars->size_precision == 0 && *hex == '0')
			hex_len = ft_hex_is_zero(hex_len, t_vars);
		ft_check_prec_and_width(hex_len, t_vars);
		ft_print_fill(t_vars->size_fill, ' ');
		ft_size_fill(hex_len, t_vars->size_precision, t_vars);
		ft_print_fill(t_vars->size_fill, '0');
		ft_print_hex(hex, hex_len);
	}
}

void	ft_hex_on_left(const char *hex, int hex_len, t_format *t_vars)
{
	if (t_vars->precision == 0)
	{
		ft_print_hex(hex, hex_len);
		ft_size_fill(hex_len, t_vars->width, t_vars);
		ft_print_fill(t_vars->size_fill, t_vars->fill);
	}
	else
	{
		if (t_vars->size_precision == 0 && *hex == '0')
			hex_len = ft_hex_is_zero(hex_len, t_vars);
		ft_size_fill(hex_len, t_vars->size_precision, t_vars);
		ft_print_fill(t_vars->size_fill, '0');
		ft_print_hex(hex, hex_len);
		ft_check_prec_and_width(hex_len, t_vars);
		ft_print_fill(t_vars->size_fill, ' ');
	}
}
