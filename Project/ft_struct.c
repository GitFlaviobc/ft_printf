/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:23:52 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/07 15:07:56 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_struct(t_format *t_vars)
{
	t_vars->flags = "-0*.";
	t_vars->parameters = "%cspdiuxX";
	t_vars->fill = '\0';
	t_vars->size_fill = 0;
	t_vars->is_negative = 0;
	t_vars->onleft = 0;
	t_vars->zero_flag = 0;
	t_vars->width = 0;
	t_vars->precision = 0;
	t_vars->size_precision = 0;
	t_vars->total_chars = 0;
	t_vars->is_formating = 0;
}

void	ft_reset_struct(t_format *t_vars)
{
	t_vars->fill = '\0';
	t_vars->size_fill = 0;
	t_vars->is_negative = 0;
	t_vars->onleft = 0;
	t_vars->zero_flag = 0;
	t_vars->width = 0;
	t_vars->precision = 0;
	t_vars->size_precision = 0;
}
