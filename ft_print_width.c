/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:14:56 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:15:11 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_print_width(t_variable *variable, int len)
{
	if ((variable->precision + variable->sign) > len)
		len = variable->precision + variable->sign;
	if (variable->precision != -1)
		variable->zero = 0;
	if (variable->sign && variable->zero && !variable->minus)
	{
		ft_pf_putchar('-', variable);
		variable->sign = 0;
	}
	while (variable->width > len)
	{
		if (variable->zero && variable->precision == -1 && variable->minus == 0)
			ft_pf_putchar('0', variable);
		else
			ft_pf_putchar(' ', variable);
		variable->width--;
	}
}
