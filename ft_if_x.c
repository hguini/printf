/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:10:11 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 19:39:46 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_len_x(unsigned int x)
{
	int	i;

	i = 0;
	while (x /= 16)
		i++;
	return (i);
}

void	ft_putnbr_x(unsigned int n, t_variable *variable)
{
	int	hex;

	hex = 55;
	if (variable->type == 'x')
		hex = 87;
	if (n < 16)
	{
		if (n < 10)
			ft_pf_putchar(n + '0', variable);
		else
			ft_pf_putchar(n + hex, variable);
	}
	else
	{
		ft_putnbr_x(n / 16, variable);
		ft_putnbr_x(n % 16, variable);
	}
}

void	ft_if_x(va_list list, t_variable *variable)
{
	int				len;
	unsigned int	arg;
	int				prec;

	arg = va_arg(list, unsigned int);
	if (!(arg == 0 && variable->precision == 0))
		len = ft_len_x(arg) + 1;
	else
		len = ft_len_x(arg);
	if (!variable->minus)
		ft_print_width(variable, len);
	prec = variable->precision;
	while (prec > len)
	{
		ft_pf_putchar('0', variable);
		prec--;
	}
	if (!(arg == 0 && variable->precision == 0))
		ft_putnbr_x(arg, variable);
	if (variable->minus)
		ft_print_width(variable, len);
}
