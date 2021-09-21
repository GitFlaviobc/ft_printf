/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:51:40 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/07 12:07:16 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_number(const char *str, int i, t_format *t_vars)
{
	if (str[i] == '0' && t_vars->onleft == 0)
	{
		t_vars->fill = '0';
		t_vars->zero_flag = 1;
	}
	else
		t_vars->fill = ' ';
	i = ft_get_number(str, i, t_vars);
	return (i);
}

int	ft_flag_minus(const char *str, int i, t_format *t_vars)
{
	t_vars->onleft = 1;
	t_vars->fill = ' ';
	i++;
	if (ft_isdigit(str[i]) || str[i] == '-')
		i = ft_get_number(str, i, t_vars);
	return (i);
}

int	ft_flag_dot(const char *str, int i, t_format *t_vars)
{
	i++;
	t_vars->precision = 1;
	if (ft_isdigit(str[i]))
		i = ft_get_number(str, i, t_vars);
	else
		t_vars->size_precision = 0;
	return (i);
}

int	ft_flag_star(int i, t_format *t_vars, va_list args)
{
	if (t_vars->precision == 0)
	{
		t_vars->width = ft_check_star_value(t_vars, args);
		if (t_vars->width != 0 && t_vars->fill != '0')
			t_vars->fill = ' ';
	}
	else
		t_vars->size_precision = ft_check_star_value(t_vars, args);
	i++;
	return (i);
}
