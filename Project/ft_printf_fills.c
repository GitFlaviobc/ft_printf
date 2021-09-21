/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:39:41 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/08 11:56:44 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_size_fill(int size, int flag_size, t_format *t_vars)
{
	if (flag_size > size)
		t_vars->size_fill = flag_size - size;
	else
		t_vars->size_fill = 0;
	t_vars->total_chars += t_vars->size_fill;
}

void	ft_print_fill(int size_fill, char fill)
{
	while (size_fill > 0)
	{
		ft_putchar(fill);
		size_fill--;
	}
}
