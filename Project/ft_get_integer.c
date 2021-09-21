/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:19:54 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 11:29:00 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_len(int number)
{
	int	i;

	i = 0;
	if (number == 0 || number < 0)
		i++;
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

void	ft_print_int(const char *number, int nb_len, t_format *t_vars)
{
	if (t_vars->is_negative == 1)
	{
		number++;
		nb_len--;
	}
	while (nb_len > 0)
	{
		ft_putchar(*number);
		number++;
		nb_len--;
	}
}

void	ft_get_integer(t_format *t_vars, va_list args)
{
	int		i_arg;
	int		nb_len;
	char	*number;

	i_arg = va_arg(args, int);
	if (i_arg < 0)
		t_vars->is_negative = 1;
	nb_len = ft_nb_len(i_arg);
	number = ft_itoa(i_arg, nb_len);
	ft_int_print_checks(number, nb_len, t_vars);
	free (number);
	t_vars->total_chars += nb_len;
}
