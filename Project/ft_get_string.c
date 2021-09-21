/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:42:50 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/05 19:45:43 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char *str_arg, int str_len)
{
	while (str_len > 0)
	{
		ft_putchar(*str_arg);
		str_arg++;
		str_len--;
	}
}

void	ft_str_print_checks(char *str_arg, int str_len, t_format *t_vars)
{
	ft_size_fill(str_len, t_vars->width, t_vars);
	if (t_vars->onleft == 0)
	{
		ft_print_fill(t_vars->size_fill, t_vars->fill);
		ft_print_str(str_arg, str_len);
	}
	else
	{
		ft_print_str(str_arg, str_len);
		ft_print_fill(t_vars->size_fill, t_vars->fill);
	}
}

int	ft_strlen_get(char *str_arg, t_format *t_vars)
{
	int	arg_len;

	arg_len = ft_strlen(str_arg);
	if (t_vars->precision == 1 && t_vars->size_precision < arg_len)
		arg_len = t_vars->size_precision;
	return (arg_len);
}

void	ft_get_string(t_format *t_vars, va_list args)
{
	char	*str_arg;
	int		str_len;

	str_arg = va_arg(args, char *);
	if (str_arg == NULL)
	{
		str_arg = "(null)";
		if (t_vars->precision == 0)
			t_vars->size_precision = 6;
	}
	str_len = ft_strlen_get(str_arg, t_vars);
	ft_str_print_checks(str_arg, str_len, t_vars);
	t_vars->total_chars += str_len;
}
