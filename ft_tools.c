/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:17:03 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:17:17 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_pf_putchar(const char symbol, t_variable *result)
{
	write(1, &symbol, 1);
	result->result++;
}

int		ft_len_arg(long long int arg, t_variable *variable)
{
	long long int len;

	len = 0;
	if (arg < 0)
	{
		arg = -arg;
		len++;
		variable->sign = 1;
	}
	if (arg == 0 && variable->precision != 0)
		len++;
	while (arg > 0)
	{
		arg /= 10;
		len++;
	}
	return (len);
}
