/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:20:21 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/07 12:00:20 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_parameters(char c, t_format *t_vars, va_list args)
{
	if (c == 'c' || c == '%')
		ft_get_char(c, t_vars, args);
	if (c == 's')
		ft_get_string(t_vars, args);
	if (c == 'x' || c == 'X')
		ft_get_hex(c, t_vars, args);
	if (c == 'p')
		ft_get_pointer(t_vars, args);
	if (c == 'd' || c == 'i')
		ft_get_integer(t_vars, args);
	if (c == 'u')
		ft_get_uint(t_vars, args);
	t_vars->is_formating = 0;
}

int	ft_get_flags(const char *str, int i, t_format *t_vars, va_list args)
{
	if (ft_isdigit(str[i]))
		i = ft_flag_number(str, i, t_vars);
	if (str[i] == '-')
		i = ft_flag_minus(str, i, t_vars);
	if (ft_isdigit(str[i]))
		i = ft_flag_number(str, i, t_vars);
	if (str[i] == '*')
		i = ft_flag_star(i, t_vars, args);
	if (str[i] == '.')
		i = ft_flag_dot(str, i, t_vars);
	if (str[i] == '*')
		i = ft_flag_star(i, t_vars, args);
	return (i);
}

int	ft_get_format(const char *str, int i, t_format *t_vars, va_list args)
{
	if (ft_strchr(t_vars->flags, str[i]) || ft_isdigit(str[i]))
		i = ft_get_flags(str, i, t_vars, args);
	if (ft_strchr(t_vars->parameters, str[i]))
	{
		ft_check_parameters(str[i], t_vars, args);
		ft_reset_struct(t_vars);
	}
	if (str[i] == '\0')
		i--;
	return (i);
}

int	ft_check_string(const char *str, va_list args)
{
	t_format	t_vars;
	int			i;

	i = 0;
	ft_zero_struct(&t_vars);
	while (str[i] != '\0')
	{
		if (str [i] == '%' && t_vars.is_formating == 0)
		{
			i++;
			t_vars.is_formating = 1;
			i = ft_get_format(str, i, &t_vars, args);
		}
		else
		{
			ft_putchar(str[i]);
			t_vars.total_chars++;
		}
		i++;
	}
	return (t_vars.total_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, str);
	printed_chars = ft_check_string(str, args);
	va_end(args);
	return (printed_chars);
}
