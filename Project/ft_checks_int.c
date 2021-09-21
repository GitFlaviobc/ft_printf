/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:55:14 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 11:54:03 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_right_no_prec(const char *number, int nb_len, t_format *t_vars)
{
	ft_size_fill(nb_len, t_vars->width, t_vars);
	if (t_vars->is_negative == 1 && t_vars->fill == '0')
		ft_putchar('-');
	ft_print_fill(t_vars->size_fill, t_vars->fill);
	if (t_vars->is_negative == 1 && t_vars->fill != '0')
		ft_putchar('-');
	ft_print_int(number, nb_len, t_vars);
}

void	ft_int_right_and_prec(const char *number, int nb_len, t_format *t_vars)
{
	if (t_vars->size_precision == 0 && *number == '0')
	{
		nb_len = 0;
		t_vars->total_chars--;
	}
	ft_size_fill(nb_len, t_vars->size_precision, t_vars);
	t_vars->total_chars -= t_vars->size_fill;
	if (t_vars->is_negative == 1 && t_vars->size_precision >= nb_len)
		t_vars->size_fill++;
	ft_size_fill(nb_len + t_vars->size_fill, t_vars->width, t_vars);
	ft_print_fill(t_vars->size_fill, ' ');
	if (t_vars->is_negative == 1)
	{
		ft_size_fill(nb_len - 1, t_vars->size_precision, t_vars);
		ft_putchar('-');
	}
	else
		ft_size_fill(nb_len, t_vars->size_precision, t_vars);
	ft_print_fill(t_vars->size_fill, '0');
	ft_print_int(number, nb_len, t_vars);
}

void	ft_int_left_no_prec(const char *number, int nb_len, t_format *t_vars)
{
	if (t_vars->is_negative == 1)
		ft_putchar('-');
	ft_size_fill(nb_len, t_vars->width, t_vars);
	if (t_vars->zero_flag == 1)
		ft_print_fill(t_vars->size_fill, '0');
	ft_print_int(number, nb_len, t_vars);
	if (t_vars->zero_flag == 0)
		ft_print_fill(t_vars->size_fill, ' ');
}

void	ft_int_left_and_prec(const char *number, int nb_len, t_format *t_vars)
{
	if (t_vars->size_precision == 0 && *number == '0')
	{
		nb_len = 0;
		t_vars->total_chars--;
	}
	ft_size_fill(nb_len, t_vars->size_precision, t_vars);
	if (t_vars->is_negative == 1 && t_vars->size_precision != 0)
		ft_putchar('-');
	if (t_vars->size_precision >= nb_len && t_vars->is_negative == 1)
	{
		t_vars->size_fill++;
		t_vars->total_chars++;
	}
	ft_print_fill(t_vars->size_fill, '0');
	if (t_vars->is_negative == 1 && t_vars->size_precision == 0)
		ft_putchar('-');
	ft_print_int(number, nb_len, t_vars);
	ft_size_fill(nb_len + t_vars->size_fill, t_vars->width, t_vars);
	ft_print_fill(t_vars->size_fill, ' ');
}

void	ft_int_print_checks(const char *number, int nb_len, t_format *t_vars)
{
	if (t_vars->onleft == 0)
	{
		if (t_vars->precision == 0)
			ft_int_right_no_prec(number, nb_len, t_vars);
		else
			ft_int_right_and_prec(number, nb_len, t_vars);
	}
	else
	{
		if (t_vars->precision == 0)
			ft_int_left_no_prec(number, nb_len, t_vars);
		else
			ft_int_left_and_prec(number, nb_len, t_vars);
	}
}
