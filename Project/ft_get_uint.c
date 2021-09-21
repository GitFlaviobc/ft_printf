/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:06:12 by fbonini           #+#    #+#             */
/*   Updated: 2021/07/07 16:51:58 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unb_len(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		i++;
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n, int n_size)
{
	char			*str;

	str = malloc((n_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str [n_size] = '\0';
	while (n_size--)
	{
		str[n_size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

void	ft_get_uint(t_format *t_vars, va_list args)
{
	unsigned int		i_arg;
	int					nb_len;
	char				*number;

	i_arg = va_arg(args, unsigned int);
	nb_len = ft_unb_len(i_arg);
	number = ft_utoa(i_arg, nb_len);
	if (i_arg == 0)
	{
		*number = '0';
		nb_len = 1;
	}
	ft_int_print_checks(number, nb_len, t_vars);
	free (number);
	t_vars->total_chars += nb_len;
}
