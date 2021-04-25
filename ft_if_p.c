/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:12:54 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 19:38:14 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_print_ox(unsigned long long int arg, t_variable *variable)
{
	if (variable->precision != 0 || variable->width != 0 || arg == 0)
	{
		ft_pf_putchar('0', variable);
		ft_pf_putchar('x', variable);
	}
}

int		ft_len_p(unsigned long long int x)
{
	int	i;

	i = 0;
	while (x /= 16)
		i++;
	return (i);
}

void	ft_putnbr_p(unsigned long long int n, t_variable *variable)
{
	int	hex;

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
		ft_putnbr_p(n / 16, variable);
		ft_putnbr_p(n % 16, variable);
	}
}

void	ft_if_p(va_list list, t_variable *variable)
{
	int					len;
	unsigned long long	arg;

	arg = va_arg(list, unsigned long long);
	if (!(arg == 0 && variable->precision == 0))
		len = ft_len_p(arg) + 1;
	else
		len = ft_len_p(arg);
	if (!variable->minus)
	{
		ft_print_width(variable, len + 2);
		ft_print_ox(arg, variable);
	}
	while (variable->precision > len)
	{
		ft_pf_putchar('0', variable);
		variable->precision--;
	}
	if (variable->minus)
		ft_print_ox(arg, variable);
	if (!(arg == 0 && variable->precision == 0))
		ft_putnbr_p(arg, variable);
	if (variable->minus)
		ft_print_width(variable, len + 2);
}
