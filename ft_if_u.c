/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:09:25 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:09:37 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_if_u(va_list list, t_variable *variable)
{
	int				len;
	unsigned int	arg;
	int				prec;

	arg = va_arg(list, unsigned int);
	len = ft_len_arg(arg, variable);
	if (!variable->minus)
		ft_print_width(variable, len);
	prec = variable->precision;
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
