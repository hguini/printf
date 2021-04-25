/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:05:38 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:05:53 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_if_c(va_list list, t_variable *variable)
{
	if (variable->minus)
		ft_pf_putchar(va_arg(list, int), variable);
	while (--variable->width >= 1)
		ft_pf_putchar(' ', variable);
	if (!variable->minus)
		ft_pf_putchar(va_arg(list, int), variable);
}
