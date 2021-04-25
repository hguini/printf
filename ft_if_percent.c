/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:14:14 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:14:25 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_if_percent(t_variable *variable)
{
	if (variable->minus)
		ft_pf_putchar('%', variable);
	while (--variable->width >= 1)
	{
		if (variable->zero && !variable->minus)
			ft_pf_putchar('0', variable);
		else
			ft_pf_putchar(' ', variable);
	}
	if (!variable->minus)
		ft_pf_putchar('%', variable);
}
