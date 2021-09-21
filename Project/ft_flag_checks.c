/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:33:32 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 12:11:29 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_width(const char *number_str, t_format *t_vars)
{
	int	number;

	number = ft_atoi(number_str);
	t_vars->width = number;
}

void	ft_set_precision(const char *number_str, t_format *t_vars)
{
	int	number;

	number = ft_atoi(number_str);
	t_vars->size_precision = number;
}

int	ft_is_repeat(const char *str, int i, t_format *t_vars)
{
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
		{
			t_vars->onleft = 1;
			t_vars->fill = ' ';
		}
		i++;
	}
	return (i);
}

int	ft_get_number(const char *str, int i, t_format *t_vars)
{
	char	*number_str;
	int		j;

	j = 0;
	number_str = (char *) malloc(sizeof(char));
	while (ft_isdigit(str[i]))
	{
		number_str[j] = str[i];
		j++;
		i++;
	}
	number_str[j] = '\0';
	if (t_vars->precision == 0)
		ft_set_width(number_str, t_vars);
	else
		ft_set_precision(number_str, t_vars);
	free (number_str);
	i = ft_is_repeat(str, i, t_vars);
	return (i);
}

int	ft_check_star_value(t_format *t_vars, va_list args)
{
	int	star_value;

	star_value = va_arg(args, int);
	if (star_value > 0 && t_vars->onleft == 1)
		t_vars->zero_flag = 0;
	if (star_value < 0)
	{
		if (t_vars->width == 0)
			t_vars->onleft = 1;
		if (t_vars->precision == 1)
			star_value = 0;
		else
			t_vars->zero_flag = 0;
		t_vars->precision = 0;
		star_value = -star_value;
	}
	return (star_value);
}
