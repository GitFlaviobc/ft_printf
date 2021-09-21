/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:51:44 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/07 15:04:55 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_char(char c, t_format *t_vars, va_list args)
{
	char	c_check;

	if (c == '%')
		c_check = '%';
	else
		c_check = va_arg(args, int);
	if (t_vars->width != 0)
		t_vars->size_fill = t_vars->width - 1;
	if (t_vars->onleft == 0)
	{
		ft_print_fill(t_vars->size_fill, t_vars->fill);
		ft_putchar(c_check);
	}
	else
	{
		ft_putchar(c_check);
		ft_print_fill(t_vars->size_fill, ' ');
	}
	t_vars->total_chars += t_vars->size_fill + 1;
}
