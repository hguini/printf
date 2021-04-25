/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:08:27 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:11:46 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_pf_putnbr(long long int n, t_variable *variable)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_pf_putnbr(n / 10, variable);
	ft_pf_putchar(n % 10 + '0', variable);
}

void	ft_if_d(va_list list, t_variable *variable)
{
	int	len;
	int	arg;
	int	prec;

	arg = va_arg(list, int);
	len = ft_len_arg(arg, variable);
	if (!variable->minus)
		ft_print_width(variable, len);
	prec = variable->precision + variable->sign;
	if (variable->sign)
		ft_pf_putchar('-', variable);
	while (prec > len)
	{
		ft_pf_putchar('0', variable);
		prec--;
	}
	if (!(arg == 0 && variable->precision == 0))
		ft_pf_putnbr(arg, variable);
	if (variable->minus)
		ft_print_width(variable, len);
}
