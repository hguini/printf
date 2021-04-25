/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:06:17 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:06:59 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_if_s(va_list list, t_variable *variable)
{
	const char	*arg;
	int			len;

	if (!(arg = va_arg(list, char *)))
		arg = "(null)";
	len = ft_strlen(arg);
	if (variable->precision == -1)
		variable->precision = len;
	else
	{
		if (len < variable->precision)
			variable->precision = len;
	}
	variable->width -= variable->precision;
	if (variable->minus)
		while (*arg && variable->precision-- > 0)
			ft_pf_putchar(*arg++, variable);
	while (variable->width-- > 0)
		ft_pf_putchar(' ', variable);
	if (!variable->minus)
		while (*arg && variable->precision-- > 0)
			ft_pf_putchar(*arg++, variable);
}
